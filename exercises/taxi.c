#include <stdio.h>
#include <assert.h>

#define MAXN 10001

int viaggia(int N, int C[]) {
    int current_price = C[0];
    int sum = 0;
    sum+=current_price; 
    int i = 0;
    while(i < N) {
        if(current_price < C[i + 1])  {
            current_price +=1;
                    sum+= current_price;
        }
        else {
            current_price =  C[i + 1];
                    sum+= current_price;
        }

        i++;
                    
    }
    return sum;
}


int C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));

    fprintf(fw, "%d\n", viaggia(N, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
