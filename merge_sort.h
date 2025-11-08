#include <vector>
#include "node.h"
using namespace std;

void date_merge(std::vector<Node>& list, int left, int mid, int right) {
    //start the merge by creating two arrays from the lower vectors
    std::vector<Node> X;
    std::vector<Node> Y;
    int lower = mid - left + 1;
    int upper = right - mid;
    for (int i = 0; i < lower; i++) {
        X.push_back(list[left+i]);
    }
    for (int j = 0; j < upper; j++) {
        Y.push_back(list[mid+j+1]);
    }
    //create iterators
    int i, j, k;
    i = j = 0;
    k = left;
    //while both list iterators are not at their end
    while (i < lower && j < upper) {
        //if left < right
        if (X[i].get_date_time() < Y[j].get_date_time()) {
            list[k] = X[i];
            i++;
        }
        //if right < left
        else {
            list[k] = Y[j];
            j++;
        }
    }
    //Y is empty now so just push the left list
    while (i < lower) {
        list[k] = X[i];
        i++;
        k++;
    }
    //X is empty now so just push the right list
    while (j < upper) {
        list[k] = Y[j];
        j++;
        k++;
    }
}
//recursively creates lists of size 1 to merge then calls the merge function on each list
void date_merge_sort_helper(std::vector<Node>& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        date_merge_sort_helper(list, left, mid);
        date_merge_sort_helper(list, mid + 1, right);

        date_merge(list, left, mid, right);
    }
}
//calls the helper with the list size of the inputted list
void date_merge_sort(std::vector<Node>& list) {
    date_merge_sort_helper(list, 0, list.size()-1);
}
//same but for word count
void str_len_merge(std::vector<Node>& list, int left, int mid, int right) {
    //start the merge by creating two arrays from the lower vectors
    std::vector<Node> X;
    std::vector<Node> Y;
    int lower = mid - left + 1;
    int upper = right - mid;
    for (int i = 0; i < lower; i++) {
        X.push_back(list[left+i]);
    }
    for (int j = 0; j < upper; j++) {
        Y.push_back(list[mid+j+1]);
    }
    int i, j, k;
    i = j = 0;
    k = left;
    while (i < lower && j < upper) {
        if (X[i].get_tweet_len() < Y[j].get_tweet_len()) {
            list[k] = X[i];
            i++;
        }
        else {
            list[k] = Y[j];
            j++;
        }
    }
    while (i < lower) {
        list[k] = X[i];
        i++;
        k++;
    }
    while (j < upper) {
        list[k] = Y[j];
        j++;
        k++;
    }
}
void tweet_len_merge_sort_helper(std::vector<Node>& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        tweet_len_merge_sort_helper(list, left, mid);
        tweet_len_merge_sort_helper(list, mid + 1, right);

        str_len_merge(list, left, mid, right);
    }
}

void tweet_merge_sort(std::vector<Node>& list) {
    tweet_len_merge_sort_helper(list, 0, list.size()-1);
}
