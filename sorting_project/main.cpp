#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

// Protótipos das funções de ordenação
void bubbleSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int l, int r);
void quickSort(std::vector<int>& arr, int low, int high);
void shellSort(std::vector<int>& arr);
void countingSort(std::vector<int>& arr);
void bucketSort(std::vector<int>& arr);
void radixSort(std::vector<int>& arr);

// Funções auxiliares para gerar arrays
void fillSorted(std::vector<int>& arr) {
  for (size_t i = 0; i < arr.size(); i++) {
    arr[i] = i;
  }
}

void fillReverseSorted(std::vector<int>& arr) {
  size_t n = arr.size();
  for (size_t i = 0; i < n; i++) {
    arr[i] = n - i;
  }
}

void fillRandom(std::vector<int>& arr) {
  srand(time(NULL));  // Seed para a geração de números aleatórios
  for (size_t i = 0; i < arr.size(); i++) {
    arr[i] = rand() % 100000;  // Números aleatórios até 100000
  }
}

// Função para imprimir vetores
void printArray(const std::vector<int>& arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

// Função para medir tempo de execução de uma função de ordenação
template <typename Func>
void measureSort(Func sortFunc, std::vector<int>& arr, const std::string& sortName, int size, const std::string& caseType) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  sortFunc(); // Executa a função de ordenação
  gettimeofday(&end, NULL);
  long timeTaken = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
  std::cout << sortName << " - Size: " << size << ", Case: " << caseType << ", Time: " << timeTaken << " microseconds." << std::endl;
  std::cout << "Sorted Array: ";
  printArray(arr); // Imprime o array após a ordenação
}


int main() {
  std::vector<int> sizes = { 25, 200, 10000 };  // Tamanhos de teste
  std::vector<std::vector<int>> testCases(3, std::vector<int>());

  for (int size : sizes) {
    // Criando vetores de teste
    testCases[0].resize(size);
    testCases[1].resize(size);
    testCases[2].resize(size);

    fillSorted(testCases[0]);
    fillReverseSorted(testCases[1]);
    fillRandom(testCases[2]);

    // Testando cada algoritmo de ordenação para cada configuração
    for (int i = 0; i < 3; i++) {
      std::string caseType = i == 0 ? "Sorted" : (i == 1 ? "Reverse Sorted" : "Random");

      // Criar uma cópia fresca do vetor de teste para cada ordenação
      std::vector<int> copyForSort;

      copyForSort = testCases[i];
      measureSort([&]() { bubbleSort(copyForSort); }, testCases[i], "Bubble Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { insertionSort(copyForSort); }, testCases[i], "Insertion Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { selectionSort(copyForSort); }, testCases[i], "Selection Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { shellSort(copyForSort); }, testCases[i], "Shell Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { countingSort(copyForSort); }, testCases[i], "Counting Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { bucketSort(copyForSort); }, testCases[i], "Bucket Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { radixSort(copyForSort); }, testCases[i], "Radix Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { mergeSort(copyForSort, 0, testCases[i].size() - 1); }, testCases[i], "Merge Sort", size, caseType);
      copyForSort = testCases[i];
      measureSort([&]() { quickSort(copyForSort, 0, testCases[i].size() - 1); }, testCases[i], "Quick Sort", size, caseType);
    }
  }

  return 0;
}
