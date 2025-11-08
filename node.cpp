#include "node.h"

//default constructor
Node::Node() {
    this->sentiment = 0;
    this->id = 0;
    this->date = 0;
    this->username = "";
    this->tweet = "";
    this->tweet_len = 0;
    this->time = 0;
    this->query = "";
    this->date_time = 0;
}
//parameterized constructor
Node::Node(int month, int day, int year, std::string username, std::string tweet, std::string time_s) {
    //calculate day minus 2000 years
    int temp = month * 12 + day;
    int temp_year = year - 2000;
    int leap_year = 0;
    //leap year check
    for (int i = 0; i < temp_year; i += 4) {
        leap_year++;
    }
    temp += leap_year;
    temp_year *= 365;
    temp += temp_year;
    this->date = temp;
    this->username = username;
    this->tweet = tweet;
    this->tweet_len = tweet.size();
    int time_num = 0;
    //hh:mm:ss time calculation
    time_num += (stoi(time_s.substr(0, 2)) * 60 * 60);
    time_num += (stoi(time_s.substr(3, 2)) * 60);
    time_num += stoi(time_s.substr(6, 2));
    this->time = time_num;
    int temp_date_time = 0;
    temp_date_time = temp * 24 * 60 * 60;
    temp_date_time += time_num;
    this->date_time = temp_date_time;
}
//fetch functions
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
int Node::get_time() {
    return this->time;
}
int Node::get_date_time() {
    return this->date_time;
}
void Node::set_sentiment(int s) { sentiment = s; }
void Node::set_id(int i) { id = i; }
void Node::set_date(const string& d) { date_string = d; }
void Node::set_query(const string& q) { query = q; }
void Node::set_username(const string& u) { username = u; }
void Node::set_tweet(const string& t) { tweet = t; }
void Node::set_tokens(const vector<string>& tokks) {
    tokens = tokks;
    tweet_len = tokks.size();
}
