#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[10][10],  r, c, i, j, *ptr,m;
    printf("Enter number of rows of matrix: ");
    scanf("%d", &r);
    printf("Enter number of columns of matrix: ");
    scanf("%d",&c);
    ptr = (int *)malloc(r * c * sizeof(int));
    printf("\nEnter elements of matrix:\n");
    for(i=0; i<r; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("\nEnter element %d of file %d of the matrix:\n", j, i);
            scanf("%d", &m);
             *(ptr+ i*c + j)=m; // To jump between each position of elements
        }
    }
    printf("\nMatrix using pointer is: \n");
    for(i=0; i<r; ++i)
    {
        for(j=0; j<c; ++j)
        {
           printf("%d\t",*(ptr +i*c + j));
        }
        printf("\n");
    }

    printf("\nTranspose of Matrix:\n");
    for(i=0; i<c; ++i)
    {
        for(j=0; j<r; ++j)
        {
             printf("%d\t",*(ptr +j*c + i));     // The transpose is created swapping previous loops
        }
        printf("\n");
   }
}