#DATASET TOKENIZATION FOR DSA PROJECT 2
'''NOTE: this code was run by Gaby at the beginning when the dataset had to be tokenized
after downloading the dataset, hence why the first file isn't found in github, the file was too big to add
so just the tokenized file was added, which is the "tokenized_dataset.csv" Running this code alone will not work
right now.
This code was also refurbished from my computaional linguistics class. '''
import pandas as pd
import re
import ast

df = pd.read_csv('training.1600000.processed.noemoticon.csv', 
                 encoding='latin-1', 
                 header=None,
                 names=['sentiment', 'id', 'date', 'query', 'user', 'text'])

#print(df.head)

#nltk.download('punkt', download_dir='/Users/gabrielavelazquez/nltk_data')
# df["tokens"] = [word_tokenize(str(t).lower()) for t in df["text"]]
df["tokens"] = [re.findall(r"\b\w+\b", str(t).lower()) for t in df["text"]]

# df.to_csv("tokenized_dataset.csv", index=False)
# print("✅ Tokenized words saved to tokenized_dataset.csv")

df = pd.read_csv("cmake-build-debug/tokenized_dataset.csv")

df["tokens"] = df["tokens"].apply((ast.literal_eval))
df["token_count"] = df["tokens"].apply(len)

tweet_text = df["text"]
df["tweet_length"] = tweet_text.apply(len)

# print(tweet_length)
# tweet_lengths = df['length'].tolist()
# print(tweet_lengths[10])




