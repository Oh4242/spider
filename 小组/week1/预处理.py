import pandas as pd
import matplotlib
matplotlib.use('QtAgg')#用于图形显示
import matplotlib.pyplot as plt

try:
    # 读取txt文件，文件中数据以空格分隔，无表头
    data = pd.read_csv('housing.data.txt', sep='\s+', header=None)
    new_columns = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV']#定义列名
    data.columns = new_columns
    for col in data.columns:#将每列转换为数值类型，无法转换的设为NaN
        data[col] = pd.to_numeric(data[col], errors='coerce')
except FileNotFoundError:
    print("未找到文件，请检查文件路径")

data = data.dropna()#删除包含缺失值的行

features = data.columns[:-1]#所有特征列，排除最后一列
fig, axes = plt.subplots(4, 4, figsize=(15, 15))#创建4×4子图网络
axes = axes.flatten()#将子图数组展平为一维

for i, feature in enumerate(features):#给轴命名
    axes[i].scatter(data[feature], data['MEDV'])
    axes[i].set_xlabel(feature)
    axes[i].set_ylabel('MEDV')

for j in range(len(features), len(axes)):#隐藏多余子图
    axes[j].axis('off')

plt.tight_layout(pad=2.0, h_pad=4.0, w_pad=2.0)#调整子图布局
plt.show()

cleaned_file_path = 'try.csv'
data.to_csv(cleaned_file_path, index=False)#保存为csv文件，不包含索引
print("已保存")