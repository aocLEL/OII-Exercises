#include <stdio.h>
#include <stdlib.h>
//#define N 8


int parabat(int v[], int alt, int N);

int binary_parabat(int v[], int alt, int N);

int main(void) {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N;
  scanf("%d", &N);

  int *v = (int*)malloc(sizeof(int) * N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
  }

  printf("%d", parabat(v, 5000, N));
  

  return 0;
}



int parabat(int v[], int alt, int N) {
  int *vk = (int*)malloc(sizeof(int) * N);

  for (size_t i = 0; i < N; i++)
  {
    alt+= v[i];
    vk[i] = alt;
  }


  for (size_t i = 0; i < N; i++) {
    for (size_t j = i + 1; j < N; j++) {
      if (vk[i] > vk[j]) {
        int temp = vk[i];
        vk[i] = vk[j];
        vk[j] = temp;
      }
    }
  }


    size_t i = 0;
    int temp = 0, major = 0;

    while(i < N) {
      if(temp < binary_parabat(vk, vk[i], N)) {
            temp = binary_parabat(vk, vk[i], N);
            major = vk[i];
      }
            
      i++;
    }
      return major;
  };

  



//CUSTOM BINARY SEARCH FOR SEARCH THE NUMBER OF OCCURENC(occorrenze) OF A NUMBER IN AN  sorting ARRAY
int binary_parabat(int v[], int to_find, int N) {
      size_t i = 0, j = N;
  int counter = 0;
  while (j - i > 1) {
      // (i + j) / 2
      size_t mid = (i + (j - i) / 2); 
 
      if (v[mid] < to_find)
        i = mid; 
      if (v[mid] > to_find)
        j = mid; 
      if (v[mid] == to_find) {
          counter++;
          int temp = mid;
          while(v[--mid] == to_find || v[++temp] == to_find)
                counter++;
          
          break;
    }
  }
  return counter;
} 