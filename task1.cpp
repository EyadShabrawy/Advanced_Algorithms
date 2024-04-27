#include <iostream>
#include <algorithm>
using namespace std;

// Function to remove duplicates from a character array
void removeDuplicates(char arr[], int &size) {
    // If the array has 0 or 1 elements, there are no duplicates to remove
    if (size == 0 || size == 1)
        return;

    // Sort the array in ascending order
    sort(arr, arr + size);

    // Initialize two pointers, i and j, to traverse the array
    int j = 0;
    for (int i = 0; i < size - 1; i++) {
        // If the current element is not equal to the next element,
        // copy the current element to the jth position and increment j
        if (arr[i]!= arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    // Copy the last element to the jth position
    arr[j++] = arr[size - 1];
    // Update the size of the array
    size = j;
}

int main() {
    char arr[] = {'a', 'b', 'c', 'c', 'b', 'd'};

    // Calculate the size of the array
    int size = sizeof(arr)/sizeof(arr[0]);

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}