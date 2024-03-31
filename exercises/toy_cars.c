#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXN 100000


int K, N, i;
int P[MAXN];

void shift(int *arr, size_t size, size_t pos) {
    int *tmp_arr = malloc(sizeof(int) * pos);
    memcpy(tmp_arr, arr+(size-pos) ,sizeof(int) * pos); 
    memmove(arr+pos, arr, sizeof(int) * (size - pos));
    memcpy(arr, tmp_arr, sizeof(int) * pos);
}

int is_sorted(int *arr, size_t n) {
    for(size_t i = 1; i < n; i++)
        if(arr[i] < arr[i-1])
            return 0;
    return 1;
}

int min_rotations(int arr[], size_t n) {
    size_t min_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    if(!min_index) {
        if(is_sorted(arr, n))
            return 0;
        else
            return -1;
    }
    int remaining = n - min_index;
    shift(arr, N, remaining);
    if(is_sorted(arr, N))
        return remaining;
    else
        return -1;
}

int main(void) {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; ++i)
        assert(1 == scanf("%d", &P[i]));
    K = 0;
    K = min_rotations(P, N);
    printf("%d\n", K);
    return 0;
}

