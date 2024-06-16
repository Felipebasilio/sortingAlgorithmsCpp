#include <vector>
#include <cmath>

int getMax(const std::vector<int>& arr) {
  int mx = arr[0];
  for (int i = 1; i < arr.size(); i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

void countSort(std::vector<int>& arr, int exp) {
  std::vector<int> output(arr.size());
  int count[10] = { 0 };

  // Armazenar contagem de ocorrências em count[]
  for (int i = 0; i < arr.size(); i++)
    count[(arr[i] / exp) % 10]++;

  // Alterar count[i] para que count[i] agora contenha a posição real deste dígito em output[]
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Construir o array de saída
  for (int i = arr.size() - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Copiar o array de saída para arr[], para que arr[] agora contenha números classificados de acordo com o dígito atual
  for (int i = 0; i < arr.size(); i++)
    arr[i] = output[i];
}

void radixSort(std::vector<int>& arr) {
  int m = getMax(arr);
  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, exp);
}
