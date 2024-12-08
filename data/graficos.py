#quiero hacer un grafico con los datos del archivo data.csv
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('data/data.csv')
plt.plot(data['x'], data['y'])
plt.show()


