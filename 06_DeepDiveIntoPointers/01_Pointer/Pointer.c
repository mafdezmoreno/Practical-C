#include<stdio.h>

int main()
{
   int i;
   int *j;
   j=&i;
   printf("Address of i is %d\n", &i); 
   printf("Address of i is %d\n", j);

   printf("Value of i is %d\n", i);
   printf("Value of i is %d\n", *j);

   int **k;
   k=&j;
   printf("Address of j = %d %d \n",&j,k);
   printf("Value of i is %d %d %d %d \n", i, *(&i), *j, **k);

   return 0;
}