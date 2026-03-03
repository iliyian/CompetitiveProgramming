import os
import html
from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Frame, PageTemplate, Preformatted, PageBreak, NextPageTemplate
from reportlab.lib.units import cm

# 配置
OUTPUT_FILENAME = "jiangly_template_book.pdf"
SOURCE_EXTENSIONS = [".cpp", ".h"]
FONT_SIZE = 8.5
TITLE_SIZE = 12
LINE_HEIGHT = FONT_SIZE * 1.1

class MyDocTemplate(SimpleDocTemplate):
    def __init__(self, filename, **kw):
        super().__init__(filename, **kw)
        self.toc_data = []

    def afterFlowable(self, flowable):
        "在每个 flowable 渲染后调用，用于记录标题位置"
        if isinstance(flowable, Paragraph):
            text = flowable.getPlainText()
            if text.startswith("File: "):
                filename = text.replace("File: ", "")
                # 记录文件名和当前页码
                self.toc_data.append((filename, self.page))

    # 重写 handle_pageBegin 以确保每页都调用页码绘制（如果 onPage 不起作用）
    # 但通常 onPage 足够了。这里我们坚持使用 PageTemplate 的 onPage。

def draw_page_number(canvas, doc):
    """绘制页码的统一函数"""
    canvas.saveState()
    canvas.setFont('Helvetica', 9)
    # 放在底部中央，稍微高一点避免被切掉
    canvas.drawCentredString(A4[0]/2, 0.75*cm, f"Page {doc.page}")
    canvas.restoreState()

class PDFBookGenerator:
    def __init__(self, output_path):
        self.output_path = output_path
        self.styles = getSampleStyleSheet()
        self.title_style = ParagraphStyle(
            'FileTitle',
            parent=self.styles['Heading1'],
            fontSize=TITLE_SIZE,
            leading=TITLE_SIZE * 1.2,
            spaceAfter=6,
            textColor=colors.dodgerblue,
        )
        self.toc_style = ParagraphStyle(
            'TOCStyle',
            parent=self.styles['Normal'],
            fontSize=10,
            leading=14,
        )

    def get_source_files(self):
        files = [f for f in os.listdir('.') if os.path.isfile(f) and os.path.splitext(f)[1] in SOURCE_EXTENSIONS]
        return sorted(files)

    def get_content_elements(self, files):
        elements = []
        for filename in files:
            if filename == "generate_pdf_book.py": continue
            
            # 这里的 "File: " 必须与 afterFlowable 中的匹配
            elements.append(Paragraph(f"File: {filename}", self.title_style))
            
            try:
                with open(filename, 'r', encoding='utf-8', errors='ignore') as f:
                    lines = f.readlines()
            except Exception as e:
                lines = [f"Error reading file: {e}"]
            
            processed_lines = []
            for line in lines:
                line = line.rstrip()
                if len(line) > 55:
                    line = line[:52] + "..."
                processed_lines.append(line)
            
            code_style = ParagraphStyle(
                'CodeStyle',
                fontName='Courier',
                fontSize=FONT_SIZE,
                leading=LINE_HEIGHT,
            )
            elements.append(Preformatted("\n".join(processed_lines), code_style))
            elements.append(Spacer(1, 0.4 * cm))
        return elements

    def create_pdf(self):
        files = self.get_source_files()
        
        # 页面布局定义
        padding = 1.2 * cm # 增加边距，确保页码不被覆盖
        column_gap = 0.6 * cm
        width = (A4[0] - 2 * padding - column_gap) / 2
        height = A4[1] - 2.5 * padding # 底部留出更多空间给页码

        # 双栏模板
        frame1 = Frame(padding, padding * 1.5, width, height, id='col1')
        frame2 = Frame(padding + width + column_gap, padding * 1.5, width, height, id='col2')
        template = PageTemplate(id='TwoColumns', frames=[frame1, frame2], onPage=draw_page_number)
        
        # 单栏模板（目录）
        full_frame = Frame(padding, padding * 1.5, A4[0] - 2*padding, height, id='full')
        toc_template = PageTemplate(id='OneColumn', frames=[full_frame], onPage=draw_page_number)

        # --- 第一次构建：获取页码 ---
        doc1 = MyDocTemplate("temp_toc.pdf", pagesize=A4)
        doc1.addPageTemplates([toc_template, template])
        
        elements1 = [
            NextPageTemplate('OneColumn'),
            Paragraph("<b>Table of Contents Placeholder</b>", self.styles['Title']),
            PageBreak(),
            NextPageTemplate('TwoColumns')
        ]
        elements1.extend(self.get_content_elements(files))
        doc1.build(elements1)
        
        # 过滤掉占位符产生的 TOC 数据（第一页）
        toc_data = [(name, p) for name, p in doc1.toc_data if name != "Table of Contents Placeholder"]
        
        # --- 第二次构建：生成最终 PDF ---
        doc2 = MyDocTemplate(self.output_path, pagesize=A4)
        doc2.addPageTemplates([toc_template, template])
        
        final_elements = []
        final_elements.append(NextPageTemplate('OneColumn'))
        final_elements.append(Paragraph("<b>Table of Contents</b>", self.styles['Title']))
        final_elements.append(Spacer(1, 0.5 * cm))
        
        # 去重并保持顺序
        seen = set()
        unique_toc = []
        for name, p in toc_data:
            if name not in seen:
                unique_toc.append((name, p))
                seen.add(name)

        for name, page in unique_toc:
            dots = "." * max(5, (85 - len(name)))
            final_elements.append(Paragraph(f"{name} {dots} {page}", self.toc_style))
        
        final_elements.append(PageBreak())
        final_elements.append(NextPageTemplate('TwoColumns'))
        final_elements.extend(self.get_content_elements(files))
        
        doc2.build(final_elements)
        
        if os.path.exists("temp_toc.pdf"):
            try: os.remove("temp_toc.pdf")
            except: pass

if __name__ == "__main__":
    print("正在生成 PDF (修复页码显示)...")
    gen = PDFBookGenerator(OUTPUT_FILENAME)
    gen.create_pdf()
    print(f"成功生成: {OUTPUT_FILENAME}")
