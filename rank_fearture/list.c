#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "students.h"

void quick_sort_descending(profile *arr, int low, int high) {
    if (low < high) {
        int pi = partitionbydown(arr, low, high);
        quick_sort_descending(arr, low, pi - 1);
        quick_sort_descending(arr, pi + 1, high);
    }
}

void quick_sort_ascending(profile *arr, int low, int high) {
    if (low < high) {
        int pi = partitionbyup(arr, low, high);
        quick_sort_ascending(arr, low, pi - 1);
        quick_sort_ascending(arr, pi + 1, high);
    }
}

int partitionbyup(profile *arr, int low, int high) {
    profile pivot = arr[high]; // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].aver < pivot.aver) { // Ascending order
            i++;
            profile temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    profile temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}

int partitionbydown(profile *arr, int low, int high) {
    profile pivot = arr[high]; // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].aver > pivot.aver) { // Descending order
            i++;
            profile temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    profile temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}

