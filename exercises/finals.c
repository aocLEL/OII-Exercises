// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXN 100

// input data
int N, P;
int S[MAXN][3];

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    assert(2 == scanf("%d %d", &N, &P));
    int maxes[N];
    int prev_max = 0;
    assert(3 == scanf("%d %d %d", &S[0][0], &S[0][1], &S[0][2]));
    maxes[0] = S[0][0] + S[0][1] + S[0][2];
    for (int i = 1; i < N; i++) {
        assert(3 == scanf("%d %d %d", &S[i][0], &S[i][1], &S[i][2]));
        maxes[i] = S[i][0] + S[i][1] + S[i][2];
        if(maxes[i] > prev_max)
            prev_max = maxes[i];
    }

    // insert your code here
    int pt_diff = (100*P)-(maxes[0] - prev_max) + 1;
    if(pt_diff < 0)
        pt_diff = 0;
    //printf("prev_max: %d\n", prev_max);
    printf("%d\n", pt_diff); // print the result
    
    return 0;
}

