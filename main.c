#include <stdio.h>
#include <time.h>
#define max 5

void criaHeap(int *v, int inicio, int final) {
  int aux = v[inicio];
  int j = inicio * 2 + 1;
  while (j <= final) {
    if (j < final) {
      if (v[j] < v[j + 1]) {
        j++;
      }
    }
    if (aux < v[j]) {
      v[inicio] = v[j];
      inicio = j;
      j = 2 * inicio + 1;
    } else {
      break;
    }
  }
  v[inicio] = aux;
}

void heapSort(int *v) {
  for (int i = (max - 1) / 2; i >= 0; i--) {
    criaHeap(v, i, max - 1);
  }
  for (int i = max - 1; i > 0; i--) {
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    criaHeap(v, 0, i - 1);
  }
}

void imprimeVetor(int *v) {
  for (int i = 0; i < max; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int v[max] = {5, 2, 1, 3, 4};
  heapSort(v);
  imprimeVetor(v);
  return 0;
}
