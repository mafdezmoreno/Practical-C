#include <stdio.h>
void main()
{
    char str[255], *ptr1, *ptr2, temp ;
    int n,m;
    printf("Enter a string: ");
    scanf("%s", str);
    ptr1=str; //Point to the begin of the string
    n=1;
    while(*ptr1 !='\0') //Loop to find the end of the string
    {
        ptr1++; // Increment pointer
        n++;    // Letter counter
    }
    ptr1--; //Now it's pointing to the last letter
    ptr2=str; //Point to the begin of the string
    m=1;
    while(m<=n/2)
    {
        // swap of letters
        temp=*ptr1;
        *ptr1=*ptr2;
        *ptr2=temp;
        ptr1--;
        ptr2++;
        m++;
    }
    printf("Reverse string is %s\n", str);
}