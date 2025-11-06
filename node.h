#include <vector>
#include <string>
#pragma once

class Node {
    int date;
    int time;
    std::string username;
    std::string tweet;
    int tweet_len;
public:
    Node();
    Node(int month, int day, int year, std::string username, std::string tweet, std::string time_s);
    int get_date();
    std::string get_tweet();
    std::string get_username();
    int get_tweet_len();
    int get_time();
};
