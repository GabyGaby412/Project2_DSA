#include <vector>
#pragma once

class Node {
    int date;
    std::string username;
    std::string tweet;
    int tweet_len;
public:
    Node(int month, int day, int year, std::string username, std::string tweet);
    ~Node();
    int get_date();
    std::string get_tweet();
    std::string get_username();
    int get_tweet_len();
};
Node::Node() {
    this->date = 0;
    this->username = "";
    this->tweet = "";
    this->tweet_len = 0;
}
Node::Node(int month, int day, int year, std::string username, std::string tweet) {
    int temp = month * 12 + day;
    int temp_year = year - 2000;
    int leap_year = 0;
    for (int i = 0; i < temp_year; i += 4) {
        leap_year++;
    }
    temp += leap_yer;
    temp_year *= 365;
    temp += temp_year;
    this->date = temp;
    this->username = username;
    this->tweet = tweet;
    this->tweet_len = tweet.size();
}
Node::~Node() {
    delete Node;
}
int Node::get_date() {
    return this->date;
}
std::string Node::get_tweet() {
    return this->tweet;
}
std::string Node::get_username() {
    return this->username;
}
int Node::get_tweet_len() {
    return this->tweet_len;
}