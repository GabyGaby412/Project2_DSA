import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('tweet_lengths.csv')

plt.bar(data["tweet"], data[" length"])
plt.title("First 10 Tweet Lengths after sorted")
plt.show()