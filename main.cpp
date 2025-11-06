#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"
#include "Quicksort.h"

using namespace std;

struct Tweet {
  int sentiment;
  int id;
  string date;
  string query;
  string user;
  string text;
  vector<string> words;
  int tweet_length;
 };

 vector<Tweet> read_tweets(string filename) {
   vector<Tweet> tweets;
   ifstream file(filename);

   if (!file.is_open()) {
     cerr << "Error: Input file '" << filename << "' not found" << endl;
     return tweets;
    }

    string line;
    while (getline(file, line)) {
      istringstream ss(line);
      vector<Tweet> tweets;
      Tweet tweet;

      getline(ss, line, ',');
      tweet.sentiment = stoi(line);

      getline(ss, line, ',');
      tweet.id = stoi(line);

      getline(ss, tweet.date, ',');

      getline(ss, tweet.query, ',');
      getline(ss, tweet.user, ',');

      if (ss.peek() == '"') {
        getline(ss, tweet.text, '"');
        getline(ss, tweet.text, '"');
      }
      else {
          getline(ss, tweet.text, ',');
       }
      //parsing the array of words in the qoute.
       getline(ss, line);
       tweet.words.clear();

       for (char c : line) {
         if (c == '[' || c == ']' || c == ',') {
           c = ' ';
         }
       }
       string word;
       stringstream tokenStream(line);
       while (getline(tokenStream, word, ',')) {
         tweet.words.push_back(word);
       }

    tweet.tweet_length = tweet.words.size();
    //have to handle case where last column tokens is parsed.
    tweets.push_back(tweet);
    }
    return tweets;
 }

 int main() {
   string filename = "dataset_tokenized";
   vector<Tweet> tweets = read_tweets(filename);
   Tweet tweet;

   if (tweets.empty()) {
     return 1;
   }

   vector<Node> data1 = tweets;
   auto start1 = chrono::high_resolution_clock::now();
   quickSort(data1, 0, data1.size() - 1);
   auto stop1 = chrono::high_resolution_clock::now();
   auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
   cout << "Time taken by Merge Sort: " << duration1.count() << endl;

   vector<int> data2 = tweets.date;
   auto start2 = chrono::high_resolution_clock::now();
   // HeapSort(dataForAlgo1);
   auto stop2 = chrono::high_resolution_clock::now();
   auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
   cout << "Time taken by Merge Sort: " << duration2.count() << endl;

   vector<int> data3 = tweets.tweet_length;
}
//check now
//will do this again