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
