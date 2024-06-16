#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Criar arrays temporários
  std::vector<int> L(n1), R(n2);

  // Copiar dados para arrays temporários L[] e R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Mesclar as arrays temporárias de volta para arr[l..r]
  i = 0; // Índice inicial do primeiro subarray
  j = 0; // Índice inicial do segundo subarray
  k = l; // Índice inicial do subarray mesclado
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copiar os elementos restantes de L[], se houver algum
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copiar os elementos restantes de R[], se houver algum
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
  if (l < r) {
    // Encontrar o ponto médio
    int m = l + (r - l) / 2;

    // Classificar primeira e segunda metades
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Mesclar as metades classificadas
    merge(arr, l, m, r);
  }
}
