#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int       N;
int       S[MAXN];
unsigned long long A;


int cmp(const void *p1, const void *p2) {
    return *((int*)p1) - *((int*)p2);
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    
    for (size_t i = 0; i < N; ++i)
        assert(1 == scanf("%d", &S[i]));
    A = 0;
    qsort(S, N, sizeof(int), cmp);
    if(N > 3) {
        int l1 = -1, l2 = -1;
        int j;
        int prev = S[N-1];
        for(j = N - 2; j >= 0; j--) {
            if(S[j] == prev) {
                if(l1 == -1) {
                    l1 = S[j];
                    j--;
                }
                else {
                    l2 = S[j];
                    break;
                }
            }
            prev = S[j];
        }
        if(l2 != -1 && l1 != -1)
            A = (unsigned long long)l1 * l2;
    }
    printf("%llu\n", A);

    return 0;
}
