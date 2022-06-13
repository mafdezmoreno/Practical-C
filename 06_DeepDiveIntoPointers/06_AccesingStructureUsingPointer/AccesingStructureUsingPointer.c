#include <stdio.h>
#include <stdlib.h>

struct cart
{
    int orderno; //order number
    char emailaddress[30];
    char password[30];
};

void main()
{

    // Init of variables
    struct cart mycart;             // cart struct creation
    struct cart *ptrcart, *ptrcust; // pointers to type cart
    ptrcart = &mycart;


    // Setting up order (using variable)
    printf("Enter order number: ");
    scanf("%d",&mycart.orderno);
    printf("Enter email address: ");
    scanf("%s",mycart.emailaddress);
    printf("Enter password: ");
    scanf("%s",mycart.password);
    // Accessing using pointer (arrow operator)
    printf("\nDetails of the customer are as follows:\n");
    printf("Order number : %d\n", ptrcart->orderno);
    printf("Email address : %s\n", ptrcart->emailaddress);
    printf("Password : %s\n", ptrcart->password);

    // Setting up order (using pointer)
    // See: https://stackoverflow.com/questions/162941/why-use-pointers
    printf("\nEnter new email address: ");
    scanf("%s",ptrcart->emailaddress);
    printf("Enter new password: ");
    scanf("%s",ptrcart->password);
    // Accessing using variable (dot operator)
    printf("\nModified customer's information is:\n");
    printf("Order number: %d\n", mycart.orderno);
    printf("Email address: %s\n", mycart.emailaddress);
    printf("Password: %s\n", mycart.password);

    // Setting up order (using dynamic memory allocation)
    // See: https://stackoverflow.com/questions/8800482/when-and-why-to-use-malloc
    ptrcust=(struct cart *)malloc(sizeof(struct cart));
    printf("\nEnter information of another customer:\n");
    printf("Enter order number: ");
    scanf("%d",&ptrcust->orderno);
    printf("Enter email address: ");
    scanf("%s",ptrcust->emailaddress);
    printf("Enter password: ");
    scanf("%s",ptrcust->password);
    printf("\nDetails of the second customer are as follows:\n");
    printf("Order number : %d\n", ptrcust->orderno);
    printf("Email address : %s\n", ptrcust->emailaddress);
    printf("Password : %s\n", ptrcust->password);
}