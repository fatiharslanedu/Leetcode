#include <stdio.h>
int main ()
{
    int x, n;
    printf("Enter an Integer: ");
    scanf("%d",&n);
    printf("The list of all positive odd integers less than %d:\n",n);
    for(x=1;x<n;x++)
    {
        if (x%2 != 0)
            printf("%d\n",x);
    }
    return(0);
}
