# 计算暂存区中所有文件的总大小（单位：KB）
$totalSize = 0
git diff --cached --name-only | ForEach-Object {
    if (Test-Path $_) {
        $file = Get-Item $_
        $totalSize += $file.Length
    }
}
# 转换为 KB 并输出
Write-Output ("Total size in staging area: {0} KB" -f ([math]::Round($totalSize / 1KB, 2)))