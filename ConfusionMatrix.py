import matplotlib.pyplot as plt
import numpy as np
from sklearn import metrics

data=np.loadtxt("putty.log")
actual=data[::2]
predicted=data[1::2]
print(actual)
print(predicted)

confusion_matrix = metrics.confusion_matrix(actual, predicted)

cm = metrics.ConfusionMatrixDisplay(confusion_matrix = confusion_matrix)

cm.plot()
plt.show()