#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr) {
  int maxValue = *max_element(arr.begin(), arr.end());
  int minValue = *min_element(arr.begin(), arr.end());
  int bucketSize = maxValue - minValue + 1; // tamanho do balde

  std::vector<std::vector<int>> bucket(bucketSize);

  for (int i = 0; i < arr.size(); i++) {
    int bucketIndex = (arr[i] - minValue) / bucketSize; // Índice no balde
    bucket[bucketIndex].push_back(arr[i]);
  }

  // Sort genérico de cada balde
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
