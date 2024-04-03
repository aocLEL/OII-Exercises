// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXN 100000

// input data
int N, X;
int L[MAXN];

int cmp(const void *p1, const void *p2) {
    return *((int*)p1) - *((int*)p2);
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &X));
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &L[i]));
    }
    unsigned ans = 0;
    if(N == 1)
        ans = 1;
    //ordino l'array;
    else {
        qsort(L, N, sizeof(int), cmp);
        int sum = X;
        for(size_t i = 0; i < N-1; i++) {
            sum -= L[i];
            L[i] = 0;
            if(sum - L[i + 1] >= 0) {
                ans++;
                L[i+1] = 0;
                i++;
            }
            else
                ans++;
            sum = X;
        }
        if(L[N-1] != 0)
            ans++;
    }
    // insert your code here
    // ogni volta prendi i due snack minori, mangiali e incrementa di un minuto

    printf("%d\n", ans); // print the result
    return 0;
}

