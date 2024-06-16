#include <vector>

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  bool swapped;
  
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Troca os elementos
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    // Se nenhum elemento foi trocado, interrompe o loop
    if (!swapped) break;
  }
}
