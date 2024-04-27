#include <iostream>
using namespace std;

int bubble_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            count++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return count;
}


int selection_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            count++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return count;
}


int insertion_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        count++;
        arr[j + 1] = key;
    }
    return count;
}


void heapify(int arr[], int n, int i, int& count) {
    int smallest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    
    if (l < n) {
        count++;
        if (arr[l] < arr[smallest])
            smallest = l;
    }

    if (r < n) {
        count++;
        if (arr[r] < arr[smallest])
            smallest = r;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest, count);
    }
}

int heap_sort_count(int arr[], int n) {
    int count = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, count);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, count);
    }
    return count;
}