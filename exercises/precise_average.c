
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000

int K, N, ans, i;
int P[MAXN];


int cmp(const void *p1, const void *p2) {
    return *((int*)p2) - *((int*)p1);
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    assert(2 == scanf("%d%d", &N, &K));
    for (i = 0; i < N; ++i)
        assert(1 == scanf("%d", &P[i]));
    ans = 0;
    qsort(P, N, sizeof(int), cmp);
    unsigned long long val_sum = (unsigned long long)N * K;
    unsigned long long vet_sum = 0;
    for(size_t i = 0; i < N; i++)
        vet_sum += P[i];
    for(size_t i = 0; i < N && vet_sum != val_sum; i++) {
        if(val_sum < vet_sum) {
            if(P[i] != 1) { 
                if((P[i] - 1) > vet_sum - val_sum) {
                    ans++;
                    break;
                }
                else
                    vet_sum -= P[i] - 1;
                ans++;
            }
        }
        else {
            ans = 1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
