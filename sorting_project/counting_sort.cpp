#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
  int maxValue = *max_element(arr.begin(), arr.end());
  int minValue = *min_element(arr.begin(), arr.end());
  int range = maxValue - minValue + 1;

  std::vector<int> count(range), output(arr.size());

  for (int i = 0; i < arr.size(); i++)
    count[arr[i] - minValue]++;

  for (int i = 1; i < count.size(); i++)
    count[i] += count[i - 1];

  for (int i = arr.size() - 1; i >= 0; i--) {
    output[count[arr[i] - minValue] - 1] = arr[i];
    count[arr[i] - minValue]--;
  }

  for (int i = 0; i < arr.size(); i++)
    arr[i] = output[i];
}
