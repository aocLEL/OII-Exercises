// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// constraints
#define MAXN 6

// input data

char L[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int N;
    assert(1 == scanf("%d\n", &N));
    size_t und_num = 0;
    size_t i = 0;
    for(i = 0; i < N; i++) {
        scanf("%c ", &L[i]);
        if(L[i] == '_')
            und_num++;
    }
    L[i] = '\0';
    int ans = 1;
    // insert your code here
    for(size_t i = 26 - (strlen(L) - und_num); und_num > 0; und_num--, i--) {
        ans *= i; 
    }
    printf("%d\n", ans); // print the result
    return 0;
}


