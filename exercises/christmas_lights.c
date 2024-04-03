#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define MAXN 200000

// input data
int N, C;
int L[MAXN];


int min_segment_length(int *lights, int N, int C) {
    int *colors = (int *)calloc(C, sizeof(int));
    int required_colors = 0;
    int min_length = INT_MAX;
    int left = 0, right = 0;
    while (right < N) {
        if (colors[lights[right]] == 0) {
            required_colors++;
        }
        colors[lights[right]]++;
        while (required_colors == C) {
            min_length = (min_length < right - left + 1) ? min_length : right - left + 1;
            colors[lights[left]]--;
            if (colors[lights[left++]] == 0) {
                required_colors--;
            }
        }
        right++;
    }
    
    free(colors);
    return min_length;
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &C));
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &L[i]));
    }
    // insert your code here
    printf("%d\n", min_segment_length(L, N, C)); // print the result
    return 0;
}
