#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"
#include "Quicksort.h"
#include "merge_sort.h"

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

 vector<Node> read_tweets(string filename) {
   vector<Node> tweets;
   ifstream file(filename);

   if (!file.is_open()) {
     cerr << "Error: Input file '" << filename << "' not found" << endl;
     return tweets;
    }

    string line;
    while (getline(file, line)) {
      istringstream ss(line);
      Node tweet;

      getline(ss, line, ',');
      tweet.set_sentiment(stoi(line));

      getline(ss, line, ',');
      tweet.set_id(stoi(line));

      getline(ss, line, ',');
      tweet.set_date(line);

      getline(ss, line, ',');
      tweet.set_query(line);

      getline(ss, line, ',');
      tweet.set_username(line);

      if (ss.peek() == '"') {
        getline(ss, line, '"');
        getline(ss, line, '"');
        tweet.set_tweet(line);
        ss.ignore();
      }
      //parsing the array of words in the quote.
      getline(ss, line);
      for (char c : line) {
         if (c == '[' || c == ']' || c == ',' || c == '\'') {
           c = ' ';
         }
       }
    string word;
    //TA suggested I use tokenStream since it parses the tokens on its own.
    stringstream tokenStream(line);
    vector<string> tokens;
    while (getline(tokenStream, word, ',')) {
    tokens.push_back(word);
    }
    tweet.set_tokens(tokens);


    tweets.push_back(tweet);
    }
    return tweets;
 }

 int main() {

   vector<Node> tweets = read_tweets("tokenized_dataset.csv");
   Tweet tweet;

   if (tweets.empty()) {
     return 1;
   }

   vector<Node> data1 = tweets;
   auto start1 = chrono::high_resolution_clock::now();
   quickSort_len(data1, 0, 100);
   auto stop1 = chrono::high_resolution_clock::now();
   auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
   cout << "Time taken by Merge Sort: " << duration1.count() << endl;

   cout << "First 5 tweets after sorting:\n";
   for (int i = 0; i < 10; ++i) {
     cout << "User: " << data1[i].get_username()
          << " | Length: " << data1[i].get_tweet_len()
           << " | Text: " << data1[i].get_tweet() << "\n";
   }

   string outpath = "/Users/gabrielavelazquez/CLionProjects/project2_dsa/Project2_DSA/tweet_lengths.csv";
   ofstream outfile(outpath);
   outfile << "tweet, length" << endl;
   for (int i = 0; i < 10; ++i) {
     outfile << "T" << i  << ", " <<  data1[i].get_tweet_len() << endl;
   }
   outfile.close();

   vector<Node> data2 = tweets;
   auto start2 = chrono::high_resolution_clock::now();
   tweet_len_merge_sort_helper(data2, 0, 100);
   auto stop2 = chrono::high_resolution_clock::now();
   auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
   cout << "\nTime taken by Merge Sort: " << duration2.count() << endl;

   cout << "First 5 tweets after merge sorting:\n";
   for (int i = 0; i < 10; ++i) {
     cout << "User: " << data2[i].get_username()
          << " | Length: " << data2[i].get_tweet_len()
           << " | Text: " << data2[i].get_tweet() << "\n";
   }


}
//check now
//will do this again
