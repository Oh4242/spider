import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# 加载数据
data = datasets.load_breast_cancer()
X, y = data.data, data.target.reshape(-1, 1)

# 标准化并添加偏置项
scaler = StandardScaler()
X = scaler.fit_transform(X)
X = np.hstack((np.ones((X.shape[0], 1)), X))  # 添加偏置项x0=1

# 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 初始化参数
theta = np.zeros((X_train.shape[1], 1))


# 定义sigmoid函数
def sigmoid(z):
    return 1 / (1 + np.exp(-z))


# 设置参数
learning_rate = 0.1
iterations = 1000
epsilon = 1e-5  # 防止log(0)

# 训练过程
loss_history = []
for i in range(iterations):
    z = np.dot(X_train, theta)
    h = sigmoid(z)
    h = np.clip(h, epsilon, 1 - epsilon)  # 数值稳定

    # 计算梯度并更新参数
    gradient = np.dot(X_train.T, (h - y_train)) / len(y_train)
    theta -= learning_rate * gradient

    # 计算损失
    loss = (-y_train * np.log(h) - (1 - y_train) * np.log(1 - h)).mean()
    loss_history.append(loss)

    if i % 100 == 0:
        print(f"Iteration {i}, Loss: {loss:.4f}")


# 预测函数
def predict(X, theta):
    return (sigmoid(np.dot(X, theta)) >= 0.5).astype(int)


# 评估准确率
y_pred = predict(X_test, theta)
accuracy = np.mean(y_pred == y_test)
print(f"Test Accuracy: {accuracy * 100:.2f}%")