// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// constraints
#define MAXN 100

// input data
int N, i;
unsigned long long K[MAXN];

int check_arr(int arr[10]) {
    for(int i = 0; i < 10; i++)
        if(!arr[i])
            return 0;
    return 1;
}

int solve(unsigned long long num) {
    int arr[10];
    int i = 1; //multiplier
    memset(arr, 0, sizeof(int) * 10);
    while(!check_arr(arr)) {
        int tmp = num * i;
        while(tmp > 0) {
            arr[tmp%10] = 1;
            tmp /= 10;
        }
        i++;
    }
    return i - 1;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%llu", &K[i]));

    // insert your code here
    for(size_t i = 0; i < N; i++){
        printf("%d\n", solve(K[i])); 
    }// print the result
    return 0;
}

