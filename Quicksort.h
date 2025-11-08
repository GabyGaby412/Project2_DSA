#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include "node.h"
#include <algorithm>
using namespace std;
#pragma once

//Find middle/pivot
int pivot(std::vector<Node>& date, int low, int high) {
    int pivot = date[low].get_date();
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (date[up].get_date_time() > pivot) {
                break;
            }
            up++;
        }

        for (int j = high; j > low; j--) {
            if (date[down].get_date_time() < pivot) {
                break;
            }
            down--;
        }

        if (up < down) {
            std::swap(date[up], date[down]);
        }
    }
    std::swap(date[low], date[down]);
    return down;
}


//The quicksort


void quickSort_time(vector<Node> &date, int low, int high) {
    if (low < high) {
        int middle = pivot(date, low, high);
        quickSort(date, low, middle -1);
        quickSort(date, middle +1, high);

    }
}
//
// //tried doing this with len but there is something strange going on
int pivot_len(std::vector<Node>& tweet_length, int low, int high) {
    int pivot1 = tweet_length[low].get_tweet_len();
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (tweet_length[up].get_tweet_len() > pivot1) {
                break;
            }
            up++;
        }

        for (int j = high; j > low; j--) {
            if (tweet_length[down].get_tweet_len() < pivot1) {
                break;
            }
            down--;
        }

        if (up < down) {
            std::swap(tweet_length[up], tweet_length[down]);
        }
    }
    std::swap(tweet_length[low], tweet_length[down]);
    return down;
}


//fixed


void quickSort_len(vector<Node> &tweet_length, int low, int high) {
    if (low < high) {
        int middle = pivot_len(tweet_length, low, high);
        quickSort_len(tweet_length, low, middle -1);
        quickSort_len(tweet_length, middle +1, high);
    }
}
