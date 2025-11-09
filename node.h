#include <vector>
#include <string>
#pragma once
using namespace std;

class Node {
    int sentiment;
    string id;
    string date_string;
    int date;
    int time;
    string query;
    std::string username;
    std::string tweet;
    string tokens;
    int tweet_len;
    int date_time;
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
    int get_date_time();

    //Setters;
    void set_sentiment(int s);
    void set_id(const string& i);
    void set_date(const string& d);
    void set_query(const string& q);
    void set_username(const string& u);
    void set_tweet(const string& t);
    void set_tokens(const string& tokks);
};
