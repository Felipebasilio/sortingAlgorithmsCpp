#include <vector>

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  bool swapped;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    // Caso o vetor ja esteja ordenado e não seja feito o swap
    if (!swapped)
      break;
  }
}
