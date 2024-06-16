#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high]; // pivô
  int i = (low - 1); // Índice do menor elemento

  for (int j = low; j <= high - 1; j++) {
    // Se o elemento atual é menor que o pivô
    if (arr[j] < pivot) {
      i++; // incrementar o índice do menor elemento
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    // pi é índice de particionamento, arr[pi] está no lugar certo
    int pi = partition(arr, low, high);

    // Separadamente classificar elementos antes
    // e depois do particionamento
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
