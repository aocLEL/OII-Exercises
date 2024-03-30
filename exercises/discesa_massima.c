#include <stdio.h>
#include <assert.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    assert(scanf("%d", &N) == 1);
    int mat[N][N];
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j <= i; j++)
            assert(scanf("%d", &mat[i][j]) == 1);
    }
    int dp[N][N];
    for (int j = 0; j < N; j++) {
        dp[N-1][j] = mat[N-1][j];
    }
    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = mat[i][j] + MAX(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    printf("%d", dp[0][0]);
    return 0;
}

