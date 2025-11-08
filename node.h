#include <vector>
#include <string>
#pragma once
using namespace std;

class Node {
    int sentiment;
    int id;
    string date_string;
    int date;
    int time;
    string query;
    std::string username;
    std::string tweet;
    vector<string> tokens;
    int tweet_len;
public:
    Node();
    Node(int month, int day, int year, std::string username, std::string tweet, std::string time_s);
    //getters
    int get_sentiment();
    int get_id();
    int get_date();
    std::string get_query();
    std::string get_tweet();
    std::string get_username();
    int get_tweet_len();
    int get_time();

    //Setters;
    void set_sentiment(int s);
    void set_id(int i);
    void set_date(const string& d);
    void set_query(const string& q);
    void set_username(const string& u);
    void set_tweet(const string& t);
    void set_tokens(const std::vector<std::string>& tokks);
};
