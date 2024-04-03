// NOTE: it is recommended to use this even if you don't understand the following code.
// Animals_at_the_river
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int N, i;
int S[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &S[i]));
    int animals = 0;
    for(int i = 0; i < N; i++, animals++) {
        for(int j = 0; j < i; j++) {
            if(S[i] > S[j] && S[j] != 0) {
                S[j] = 0;
                animals--;
            }
        }
    }
    // insert your code here
   
    printf("%d\n", animals); // print the result
    return 0;
}
