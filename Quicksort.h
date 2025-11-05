#include <iostream>
#include <array>
#include <utility>
#include <vector>
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
            swap(&data[up].get_date(), &data[down].get_date());
        }
    }
    swap(data[low].get_date(), &data[down].get_date());
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
