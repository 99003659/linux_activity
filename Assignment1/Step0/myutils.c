#include "stdarg.h"
#include "myutils.h"
#include <stdio.h>

#define TRUE   1    //TRUE
#define FALSE  0    //FALSE


int factorial(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    printf("%d",f);
    return 0;
}

int ispalindrome(int m)
{
    int temp=0,reminder,rev=0;
    temp=m;
    while(m!=0)
    {
        reminder=m%10;
        rev=rev*10 + reminder;
        m=m/10;
    }
    if( rev == temp)
     printf("palindrome");
    else
     printf("not palindrome");
}


/*int isprime(int n)
{
    int i,flag = 0;
    for(i=2;i<=n/2;++i)
    {
        //condition for not prime
        if(n%i == 0)
        {
            flag=1;
            break;
        }
    }
    if(n==1)
        printf("not prime");
    else
        printf("prime");
}*/

int isprime(int n) 
{
    int i, flag = 0;
    int ans=0;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
        //return -1;
    }
    else {
        if (flag == 0)
            printf("prime number.");
            //return 1;
        else
            printf("not a prime number.");
            //return 0;
    }

    return 0;
}


int vsum(int num,...)
{
    va_list valist;

    int sum = 0, i;

    va_start(valist, num);
    for (i = 0; i < num; i++)
        sum += va_arg(valist, int);

    va_end(valist);
  
    return sum;
}
