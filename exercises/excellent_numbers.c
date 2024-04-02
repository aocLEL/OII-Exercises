#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int sum_digits(char* string) {
    int sum = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        sum += string[i] - '0';
    }
    return sum;
}

void generate_string(int N, char* string) {
    srand(time(NULL));
    size_t timer = 0;
    do{
        for (int i = 0; i < N; i++) {
            string[i] = rand() % (2) ? '1' : '5';
        }
        timer++;
        if(timer == 100) { // 100 will be enough for the purpose of the exercise
            string[0] = '-';
            string[1] = '1';
            string[2] = '\0';
            break;
        }
        string[N] = '\0'; 
    }while(sum_digits(string) % 3 != 0); 
}

int main() {
    int N;
    scanf("%d", &N);

    char string[N + 1];
    generate_string(N, string);
    printf("%s\n", string);

    return 0;
}

