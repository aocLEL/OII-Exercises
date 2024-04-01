// NOTE: it is recommended to use this even if you don't understand the following code.


#include <stdio.h>


#define MAXS 128
#define MAXN 100

int  N, T, i, test;
int  P[MAXN];
char ans[MAXS];

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    unsigned points[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    unsigned p0 = points[0], p1 = points[1];
    scanf("%d", &T);
    for (test = 0; test < T; ++test) {
        scanf("%d", &N);
        
        for (i = 0; i < N; ++i)
            scanf("%d", &P[i]);
        // INSERT YOUR CODE HERE
        unsigned dan_points = 0, opp_points = 0;
        for(size_t i = 0; i < N; i++) {
            if(P[i] <= 10) 
                dan_points += points[P[i] - 1];
            if(P[i] != 1)
                opp_points += p0;
            else
                opp_points += p1;
        }
        printf("%s\n", dan_points >= opp_points ? "Champion" : "Practice harder");
    }
    return 0;
}

