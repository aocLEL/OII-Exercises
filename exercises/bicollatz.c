#include <stdio.h>



int bicollatz(int A, int B);


int main(void) {

  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int A, B;

  scanf("%d %d", &A, &B);

  printf("%d", bicollatz(A, B));


  return 0;
}


int bicollatz(int A, int B) {
  int counter = 0;

  while(A > 1 || B > 1) {

    if((A % 2 == 0) && (B % 2 == 0)) {
            A /= 2;
            B /= 2;
      }
      else if(A % 2 != 0 && B % 2 != 0) {
        A = (A * 3) + 1;
        B = (B * 3) + 1;
      }
      else {
        if(A % 2 != 0)
              A += 3;
        else 
          B += 3;
      }
      if(counter > 10000)
            return -1;

      counter++;
  }
  


  return counter;
      
}