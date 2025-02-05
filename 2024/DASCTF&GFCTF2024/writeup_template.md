## Misc

> 垃圾信息侵扰已久，为了维护数字空间的清洁，我们需要你的帮助来识别并过滤这些不受欢迎的信息。你的任务是构建一个机器学习模型，准确识别垃圾短信。这里有一个数据集，请先训练你的模型再判断随机发送的短信是否为垃圾短信哦，答对积一分，答错不积分，一共300条信息，总分在240分即可获得flag

我们基于朴素贝叶斯训练一个分类器，然后一条一条进行测试即可，只需要正确240条就可以获得flag

训练器代码：

```python
import os
os.environ["HDF5_USE_FILE_LOCKING"] = "FALSE"
stopwords_path = r'chineseStopWords.txt'
def read_stopwords(stopwords_path):

    stopwords = []
    with open(stopwords_path, 'r', encoding='utf-8') as f:
        stopwords = f.read()
    stopwords = stopwords.splitlines()
    return stopwords
stopwords = read_stopwords(stopwords_path)

from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import BernoulliNB
from sklearn.naive_bayes import MultinomialNB
from sklearn.naive_bayes import ComplementNB
import pandas as pd
import numpy as np

data_path = "data_2.csv"
sms = pd.read_csv(data_path, encoding='utf-8')

from sklearn.model_selection import train_test_split
X = np.array(sms.msg_new)
y = np.array(sms.label)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=42, test_size=0.1)
print("总共的数据大小", X.shape)
print("训练集数据大小", X_train.shape)
print("测试集数据大小", X_test.shape)

from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.preprocessing import StandardScaler
from sklearn.naive_bayes import ComplementNB

pipeline_list = [

    ('tf', TfidfVectorizer(stop_words=stopwords)),
    ('ss',StandardScaler(with_mean=False)),
    ('classifier', ComplementNB(alpha=1))

]

pipeline = Pipeline(pipeline_list)
pipeline.fit(X_train, y_train)
y_pred = pipeline.predict(X_test)

pipeline.fit(X, y)

import joblib
pipeline_path = 'results/pipeline.model'
joblib.dump(pipeline, pipeline_path)
```

​	训练完的模型存储到本地，然后对出现的文本进行测试，程序输出label：0或者1

```python
import os
os.environ["HDF5_USE_FILE_LOCKING"] = "FALSE"
stopwords_path = r'chineseStopWords.txt'
def read_stopwords(stopwords_path):
    stopwords = []

    with open(stopwords_path, 'r', encoding='utf-8') as f:
        stopwords = f.read()
    stopwords = stopwords.splitlines()

    return stopwords

stopwords = read_stopwords(stopwords_path)
import joblib
pipeline_path = 'results/pipeline.model'
pipeline = joblib.load(pipeline_path)

def predict(message):

    label = pipeline.predict([message])[0]
    proba = list(pipeline.predict_proba([message])[0])
    
    return label, proba
```

得出结果：

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20240420122635311.png" alt="image-20240420122635311" style="zoom: 67%;" />

所以，flag是

```
DASCTF{OB0b73eC3VVpvbadnne3}
```

