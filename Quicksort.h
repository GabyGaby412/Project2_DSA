#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include "node.h"
using namespace std;
#pragma once

//Find middle/pivot
int pivot(std::vector<Node> date, int low, int high) {
    int pivot = date[low].get_date();
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (date[up].get_date() > pivot) {
                break;
            }
            up++;
        }

        for (int j = high; j > low; j--) {
            if (date[down].get_date() < pivot) {
                break;
            }
            down--;
        }

        if (up < down) {
            swap(date[up].get_date(), date[down].get_date());
        }
    }
    swap(date[low].get_date(), date[down].get_date());
    return down;
}


//The quicksort

void quickSort(vector<Node> &date, int low, int high) {
    if (low < high) {
        int middle = pivot(date, low, high);
        quickSort(date, low, middle -1);
        quickSort(date, middle +1, high);

    }
}

//tried doing this with len but there is something strange going on
int pivot_len(std::vector<Node> tokens, int low, int high) {
    int pivot = tokens[low].get_tweet_len();
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (tokens[up].get_tweet_len() > pivot) {
                break;
            }
            up++;
        }

        for (int j = high; j > low; j--) {
            if (tokens[down].get_tweet_len() < pivot) {
                break;
            }
            down--;
        }

        if (up < down) {
            swap(&data[up].get_tweet_len(), &data[down].get_tweet_len());
        }
    }
    swap(data[low].get_tweet_len(), &data[down].get_tweet_len());
    return down;
}


//The quicksort

void quickSort_len(vector<Node> &tokens, int low, int high) {
    if (low < high) {
        int middle = pivot(tokens, low, high);
        quickSort(tokens, low, middle -1);
        quickSort(tokens, middle +1, high);

    }
}
