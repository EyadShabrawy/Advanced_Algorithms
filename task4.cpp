#include <iostream>
using namespace std;

int partitionArray(int data[], int start, int end) {
    int pivotValue = data[end];
    int smallerElementIndex = (start - 1);

    for (int current = start; current < end; current++) {
        if (data[current] <= pivotValue) {
            smallerElementIndex++;
            swap(data[smallerElementIndex], data[current]);
        }
    }
    swap(data[smallerElementIndex + 1], data[end]);
    return (smallerElementIndex + 1);
}

void quickSort(int data[], int start, int end, int targetValue) {
    int targetIndex = -1;
    for (int i = start; i <= end; i++) {
        if (data[i] == targetValue) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex != -1) {
        swap(data[targetIndex], data[end]);

        if (start < end) {
            int partitionIndex = partitionArray(data, start, end);
            quickSort(data, start, partitionIndex - 1, targetValue);
            quickSort(data, partitionIndex + 1, end, targetValue);
        }
    }
}

int main() {
    int numbers[] = {3, 1, 12, 9, 4, 10, 54, 34, 12, 89};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    int key = 12;

    bool keyFound = false;
    for (int i = 0; i < arraySize; i++) {
        if (numbers[i] == key) {
            keyFound = true;
            break;
        }
    }

    if (!keyFound) {
        cout << "Key element not found in the array." << endl;
        return 0;
    }

    bool isMinimum = true, isMaximum = true;
    for (int i = 0; i < arraySize; i++) {
        if (numbers[i] < key) {
            isMinimum = false;
        }
        if (numbers[i] > key) {
            isMaximum = false;
        }
    }

    if (isMinimum || isMaximum) {
        cout << "Please choose another key element." << endl;
        return 0;
    }

    quickSort(numbers, 0, arraySize - 1, key);

    cout << "Sorted Array\n";
    for (int i = 0; i < arraySize; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
