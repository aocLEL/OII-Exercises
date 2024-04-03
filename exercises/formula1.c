// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// constraints
#define MAXN 100

// input data
int N, i;
int H[MAXN], V[MAXN];

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &H[i]));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &V[i]));
    
    unsigned int min = UINT_MAX, ham_sum = 0, ver_sum = 0, fast_lap;
    for(int i = 0; i < N; i++) {
        ham_sum += H[i];
        ver_sum += V[i];
        if(H[i] < min) {
            min = H[i];
            fast_lap = 1;
        }
        if(V[i] < min) {
            min = V[i];
            fast_lap = 0;
        }
    }
    
    printf("%s\n", ham_sum < ver_sum ? "Hamilton" : "Verstappen");
    printf("%s\n", fast_lap ? "Hamilton" : "Verstappen");

    //printf("%d\n", 42); // print the result
    return 0;
}

