#include <vector>

void selectionSort(std::vector<int>& arr) {
    int arraySize = arr.size();

    for (int firstCounter = 0; firstCounter < arraySize - 1; firstCounter++) {
        int min_idx = firstCounter;

        for (int secondCounter = firstCounter + 1; secondCounter < arraySize; secondCounter++) {
            if (arr[secondCounter] < arr[min_idx]) {
                min_idx = secondCounter;
            }
        }

        std::swap(arr[firstCounter], arr[min_idx]);
    }
}
