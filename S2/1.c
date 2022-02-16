#include <stdio.h>
int abs(int n)
{
    if (n<0)
    {
        n=-n;
    }
    return n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    n=n-1;
    int ar[n+1], c=0, c0=0;
    for (int i=0; i<=n; i++)
    {
        scanf("%d", &ar[i]);
        if (ar[i]!=0 && i!=1 && i!=0)
        {
            c+=1;
        }
        if (ar[i]!=0)
        {
            c0++;
        }
    }
    int a=0;
    for (int i=n; i>=0; i--)
    {
        if (ar[i]!=0)
        {
            if (a!=0 && ar[i]>0 && c!=0)
            {
                printf(" + ");
            }
            if (ar[i]<0)
            {
                if (a!=0)
                {
                    printf(" - ");
                }
                else
                {
                    printf("-");
                }
            }
    
            if (i==0)
            {
                printf("%d", abs(ar[i]));
            }
            else if (i==1)
            {
                if (abs(ar[i])!=1)
                {printf("%dx", abs(ar[i]));}
                else
                {printf("x");}
            }
            else
            {
                if (abs(ar[i])!=1)
                {printf("%dx^%d", abs(ar[i]), i);}
                else
                {printf("x^%d", i);}
            }
            a+=1;
        }
    }
    if (c0==0)
    {
        printf("0");
    }
    printf("\n");
}
