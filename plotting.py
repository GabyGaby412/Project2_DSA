import pandas as pd
import matplotlib.pyplot as plt

fig, axes = plt.subplots(2, 1, figsize=(12, 7))

data = pd.read_csv('tweet_lengths.csv')
#plt.figure(figsize=(12,6))
axes[0].bar(data["tweet"], data[" length"])
axes[0].set_title("Random 15 Tweet Lengths after sorted")


data2 = pd.read_csv("sorting_time.csv")
data2[" time"] = data2[" time"].str.replace("ms", "", regex = False).astype(float)

axes[1].set_position([0.15, 0.1, 0.3, 0.35])
axes[1].bar(data2["sorting"], data2[" time"], width=0.6)
axes[1].set_title("Sorting Time Comparisons in milliseconds")
axes[1].set_ylim(bottom=0)

plt.show()