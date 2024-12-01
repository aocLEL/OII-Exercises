// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXN 200000
#define MOD 1000000007

// input data
int N;
int A[MAXN], B[MAXN];

int sortf(const void *p1, const void *p2) {
  return *((const int*)p2) - *((const int*)p1);
}

int suitable_bound_search(int *arr, int n, int key) {
    int left = 0, right = n - 1;
    // handling cases at the bounds
    if(arr[left] < key) return 0;
    if(arr[right] >= key) return n;
    int mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(arr[mid] == key){
            while(arr[mid + 1] == key) mid++;
            return mid + 1;
        }  
        if(arr[mid] > key) left = mid + 1;
        else right = mid - 1;
    }
    return right + 1;
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &A[i]));
    }
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &B[i]));
    }

    // insert your code here
    qsort(A, N, sizeof(int), sortf);
    qsort(B, N, sizeof(int), sortf);
    int tot_perms = 1;
    int search_val = 0, prev = 0;
    for(size_t i = 0; i < N; i++) {
        if(B[i] != prev) {
            search_val = suitable_bound_search(A, N, B[i]);
            prev = B[i];
        }
        tot_perms = (tot_perms * (search_val - i)) % MOD;
    }

    printf("%d\n", tot_perms % MOD); // print the result
    
    return 0;
}

