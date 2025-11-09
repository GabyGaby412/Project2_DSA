#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "node.h"
#include <random>
#include "Quicksort.h"
#include "merge_sort.h"

using namespace std;

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
      else {
        getline(ss, line, ',');
        tweet.set_tweet(line);
      }

      getline(ss, line);
      for (char c : line) {
         if (c == '[' || c == ']' || c == ',' || c == '"' || c == '\n') {
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
   vector<Node> tweets = read_tweets("Project2_DSA/tokenized_dataset.csv");

   if (tweets.empty()) {
     return 1;
   }

   srand(time(0));
   int min = 0;
   int max = tweets.size() - 1;
   int points = 15;

   vector <int> random_points;
   for (int i = 0; i < points; i++) {
     int rand1 = rand() % (max - min + 1);
     random_points.push_back(rand1);
   }
   sort(random_points.begin(), random_points.end());

   vector<Node> data1 = tweets;
   auto start1 = chrono::high_resolution_clock::now();
   quickSort_len(data1, 0, tweets.size() - 1);
   auto stop1 = chrono::high_resolution_clock::now();
   auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
   cout << "Time taken by Quick Sort: " << duration1.count() << endl;

   cout << "Randomized tweets_lengths after sorting:\n";
   for (int i  : random_points) {
     cout << "T"<< i << " | " << "User: " << data1[i].get_username()
          << " | Length: " << data1[i].get_tweet_len()
           << " | Text: " << data1[i].get_tweet() << "\n";
   }

   vector<Node> data2 = tweets;
   auto start2 = chrono::high_resolution_clock::now();
   tweet_merge_sort(data2);
   auto stop2 = chrono::high_resolution_clock::now();
   auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
   cout << "\nTime taken by Merge Sort: " << duration2.count() << endl;

   cout << "Randomized tweets after merge sorting:\n";
   for (int i : random_points) {
     cout << "T"<< i << " | " << "User: " << data2[i].get_username()
          << " | Length: " << data2[i].get_tweet_len()
          << " | Text: " << data1[i].get_tweet() << "\n";
   }

   string outpath = "tweet_lengths.csv";
   ofstream outfile(outpath);
   outfile << "tweet, length" << endl;
   for (int i : random_points) {
     outfile << "T"<< i  << ", " <<  data1[i].get_tweet_len() << endl;
   }
   outfile.close();

   string outpath2 = "sorting_time.csv";\
   ofstream outfile2(outpath2);
   outfile2 << "sorting, time" << endl;
   //outfile2 <<  ", " << "0" << endl;
   outfile2 << "Quicksort" << "," << duration1.count() <<"ms" << endl;
   outfile2 << "Mergesort" << "," << duration2.count() <<"ms" << endl;
   outfile2.close();
 }

///

