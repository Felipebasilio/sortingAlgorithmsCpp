#include <vector>

void bubbleSort(std::vector<int>& arr) {
  int arraySize = arr.size();
  bool swapped;
  
  for (int firstCounter = 0; firstCounter < arraySize - 1; firstCounter++) {
    swapped = false;
    for (int secondCounter = 0; secondCounter < arraySize - firstCounter - 1; secondCounter++) {
      if (arr[secondCounter] > arr[secondCounter + 1]) {
        // Troca os elementos
        std::swap(arr[secondCounter], arr[secondCounter + 1]);
        swapped = true;
      }
    }
    // Se nenhum elemento foi trocado, interrompe o loop
    if (!swapped) break;
  }
}
