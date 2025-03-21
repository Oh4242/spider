import matplotlib.pyplot as plt
import numpy as np

# 定义目标函数
def hanshu(x):
    return x ** 2

# 定义目标函数的导数
def daoshu(x):
    return 2 * x

# 实现梯度下降算法
def gradient_descent(x1, step, num):
    x = x1
    xs = [x]  # 用于记录每次迭代后的横坐标
    ys = [hanshu(x)]  # 用于记录每次迭代后的纵坐标
    for i in range(num):
        # 计算梯度
        tidu = daoshu(x)
        # 更新参数
        x = x - step * tidu
        xs.append(x)
        ys.append(hanshu(x))
        # 每 10 次迭代打印一次当前的 x 和目标函数值
        if i % 10 == 0:
            print(f'Iteration {i}: x = {x}, f(x) = {hanshu(x)}')
    return x, xs, ys

# 设置初始参数
x1 = 5.0
step = 0.1
num = 100

# 运行梯度下降算法
result, xs, ys = gradient_descent(x1, step, num)
print(f'Optimal x: {result}, f(x) = {hanshu(result)}')

# 绘制目标函数曲线
x_vals = np.linspace(-6, 6, 400)
y_vals = hanshu(x_vals)
plt.plot(x_vals, y_vals, label='Objective Function $f(x) = x^2$')

# 绘制梯度下降路径
plt.scatter(xs, ys, color='red', s=20, label='Gradient Descent Steps')
plt.plot(xs, ys, color='red', linestyle='--')

# 设置图形标记
plt.title('Gradient Descent Visualization')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()
