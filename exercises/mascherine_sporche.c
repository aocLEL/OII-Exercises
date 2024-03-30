#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int N, K, *C, i;

void riprogramma(int N, int K, int C[]){
    if(K == 2) {
        int *arr1 = malloc(sizeof(int)*N);
        int *arr2 = malloc(sizeof(int)*N);
        size_t occ1 = 0, occ2 = 0;
        for(size_t i = 0; i < N; i++) {
            if(i & 1)
                arr1[i] = 2;
            else
                arr1[i] = 1;
            if(arr1[i] != C[i])
                occ1++;
        }
        for(size_t i = 0; i < N; i++) {
            if(i & 1)
                arr2[i] = 1;
            else
                arr2[i] = 2;
            if(arr2[i] != C[i])
                occ2++;
        }
        int *p = occ1 < occ2 ? arr1 : arr2;
        for(size_t i = 0; i < N; i++)
            C[i] = p[i];
        free(arr1);
        free(arr2);
    }
    else {
        int prec = 0;
        for(size_t i = 0; i < N; i++) {
            if(C[i] == prec) {
                int new_mask = C[i];
                do {
                    new_mask = (++new_mask % K) + 1;
                } while(new_mask == C[i] || new_mask == C[i + 1]);
                C[i] = new_mask;
            }
            prec = C[i];
        } 
    }
}

int main() {
  // se preferisci leggere e scrivere da file
  // ti basta decommentare le seguenti due righe:

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  assert(scanf("%d %d", &N, &K) == 2);
  C = malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    assert(scanf("%d", &C[i]) == 1);
  }
  riprogramma(N, K, C);
  for (i = 0; i < N; i++) {
    printf("%d ", C[i]);
  }
  printf("\n");
  return 0;
}


