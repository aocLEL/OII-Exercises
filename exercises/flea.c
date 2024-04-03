// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 100

// input data
int N;
char S[MAXN+1];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    assert(1 == scanf("%s", S));

    // insert your code here
    int jumps = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R')
            jumps--;
        else
            jumps++;
    }
    printf("%d\n", abs(jumps)); // print the result
    return 0;
}

