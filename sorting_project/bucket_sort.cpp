#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr) {
  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());
  int bucketSize = max - min + 1; // tamanho do balde

  std::vector<std::vector<int>> bucket(bucketSize);

  for (int i = 0; i < arr.size(); i++) {
    int bi = (arr[i] - min) / bucketSize; // Índice no balde
    bucket[bi].push_back(arr[i]);
  }

  for (auto& b : bucket) {
    std::sort(b.begin(), b.end());
  }

  int index = 0;
  for (int i = 0; i < bucketSize; i++) {
    for (int j = 0; j < bucket[i].size(); j++) {
      arr[index++] = bucket[i][j];
    }
  }
}
