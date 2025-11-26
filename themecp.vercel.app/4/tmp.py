import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import newton

# ---【修复中文显示】---
plt.rcParams['font.sans-serif'] = ['SimHei'] # Windows默认黑体
plt.rcParams['axes.unicode_minus'] = False

# 1. 计算 r 和 theta_max
def calc_parameters():
    def f(theta): return 4 * np.sin(theta) - 3 * np.cos(theta) - 4 * theta + 3
    def f_prime(theta): return 4 * np.cos(theta) + 3 * np.sin(theta) - 4
    theta_max = newton(f, 2.0, fprime=f_prime)
    r = 4.0 / (1 - np.cos(theta_max))
    return r, theta_max

R_VAL, THETA_MAX = calc_parameters()

# 2. 数据生成
def get_cycloid_data(n_samples):
    theta = np.linspace(0, THETA_MAX, n_samples)
    x = R_VAL * (theta - np.sin(theta))
    y = R_VAL * (1 - np.cos(theta))
    return torch.from_numpy(x).float().view(-1, 1), torch.from_numpy(y).float().view(-1, 1)

# 3. 网络结构
class BPNetwork(nn.Module):
    def __init__(self):
        super(BPNetwork, self).__init__()
        self.hidden = nn.Linear(1, 10)
        self.sigmoid = nn.Sigmoid()
        self.predict = nn.Linear(10, 1)
    def forward(self, x):
        return self.predict(self.sigmoid(self.hidden(x)))

# 4. 实验循环
def run_experiment():
    torch.manual_seed(123) # 换个随机种子，运气可能会更好
    np.random.seed(123)
    
    sample_counts = [5, 10, 20, 30, 40, 50, 80] # 去掉了100，因为80足够说明问题了
    x_test, y_test = get_cycloid_data(1000)
    test_losses = []

    for n in sample_counts:
        x_train, y_train = get_cycloid_data(n)
        net = BPNetwork()
        # ---【调整】学习率改小到0.02，更稳定；训练轮数增加到3000---
        optimizer = optim.Adam(net.parameters(), lr=0.02) 
        loss_func = nn.MSELoss()
        
        for epoch in range(3000):
            prediction = net(x_train)
            loss = loss_func(prediction, y_train)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
        
        net.eval()
        with torch.no_grad():
            test_loss = loss_func(net(x_test), y_test).item()
        test_losses.append(test_loss)
        print(f"样本数: {n} | Loss: {test_loss:.6f}")

    # 5. 绘图
    plt.figure(figsize=(8, 5))
    plt.plot(sample_counts, test_losses, 'o-', color='red', linewidth=2)
    plt.title('平均损失值 (MSE) vs 训练样本数量', fontsize=14)
    plt.xlabel('训练样本数量', fontsize=12)
    plt.ylabel('MSE 损失值', fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.5)
    
    for x, y in zip(sample_counts, test_losses):
        plt.text(x, y+0.00005, f'{y:.4f}', ha='center', fontsize=9)
        
    plt.show()

if __name__ == '__main__':
    run_experiment()