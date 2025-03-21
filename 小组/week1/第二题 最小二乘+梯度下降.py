import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
def calculate_fit_line(data, feature):
    # 定义一个使用最小二乘法计算拟合直线的函数
    x = data[feature].values
    y = data['MEDV'].values
    n = len(x)
    x_mean = np.mean(x)
    y_mean = np.mean(y)

    # 根据公式计算斜率
    numerator = np.sum(x * y) - n * x_mean * y_mean
    denominator = np.sum(x ** 2) - n * (x_mean ** 2)
    slope = numerator / denominator

    # 计算截距
    intercept = y_mean - slope * x_mean

    # 预测值
    y_pred = slope * x + intercept

    return y_pred
def tidu(X, y, lr, num):
    # 定义一个使用梯度下降法进行参数更新的函数
    theta = np.random.randn(X.shape[1])
    for _ in range(num):
        grad = 2 / X.shape[0] * X.T.dot(X.dot(theta) - y)
        theta = theta - lr * grad
    return X.dot(theta)

try:
    # 读取txt文件，文件中数据以空格分隔，无表头
    data = pd.read_csv('housing.data.txt', sep='\s+', header=None)
    new_columns = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT',
                   'MEDV']
    data.columns = new_columns
    for col in data.columns:
        data[col] = pd.to_numeric(data[col], errors='coerce')
except FileNotFoundError:
    print("未找到文件，请检查文件路径")

data = data.dropna()

features = data.columns[:-1]

# 使用最小二乘法进行预测
for feature in features:
    least_squares_pred = calculate_fit_line(data, feature)
    print(f"使用最小二乘法基于 {feature} 的预测值: {least_squares_pred}")

# 数据标准化
scaler = StandardScaler()
X = data[features].values
X_scaled = scaler.fit_transform(X)
y = data['MEDV'].values

# 调整学习率
learning_rate = 0.0001
num_iterations = 1000
gradient_descent_pred = tidu(X_scaled, y, learning_rate, num_iterations)
print(f"使用梯度下降法的预测值: {gradient_descent_pred}")

cleaned_file_path = 'try.csv'
data.to_csv(cleaned_file_path, index=False)
print("已保存")
