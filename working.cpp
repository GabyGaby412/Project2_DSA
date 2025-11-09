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
   getline(file, line);

    while (getline(file, line)) {
      istringstream ss(line);
      Node tweet;

      getline(ss, line, ',');
      tweet.set_sentiment(stoi(line));

      getline(ss, line, ',');
      tweet.set_id(line);

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
      getline(ss, line, ',');
      tweet.set_tokens(line);
      
    tweets.push_back(tweet);
    }
    return tweets;
 }

 int main() {
   int num;
   cout << "Insert Number of Points: " ;
   cin >>num;
   cin.ignore();
   vector<Node> tweets = read_tweets("tokenized_dataset.csv");

   if (tweets.empty()) {
     return 1;
   }

   srand(time(0));
   int min = 0;
   int max = 100000;
   int points = 15;

   vector <int> random_points;
   for (int i = 0; i < points; i++) {
     int rand1 = rand() % (max - min + 1);
     random_points.push_back(rand1);
   }
   sort(random_points.begin(), random_points.end());

   vector<Node> data1 = tweets;
   auto start1 = chrono::high_resolution_clock::now();
   quickSort_len(data1, 0, 100000);
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
   tweet_len_merge_sort_helper(data2, 0, 100000);
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
   outfile2 << "Quicksort" << "," << duration1 << endl;
   outfile2 << "Mergesort" << "," << duration2 << endl;
   outfile2.close();
 }

///

