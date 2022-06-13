#include <stdio.h>
#define max 100
void main()
{
    int p[max], i, n, *ptr, *mx;
    printf("How many elements are there? ");
    scanf("%d", &n);
    //n = 5;
    printf("Enter %d elements \n", n);
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
        //p[i]=i;
    mx=p;
    ptr=p;
    for(i=1;i<=n;i++) //Error in book. It's doesn't reach last element to compare
    {
        if (*mx < *ptr) //Compare values
            mx=ptr;     //If actual is higher than max, swap 
        ptr++;
    }
    printf("Largest value is %d\n", *mx);
}