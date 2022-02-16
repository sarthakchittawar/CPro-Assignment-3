#include <stdio.h>

#define m 1000000007

long int mod(long int x)
{
    if (x<0)
    {
        return (x+m)%m;
    }
    else
    {
        return x%m;
    }
}

long int det(long int n, long int ar[n][n])
{
    long int sum=0;
    int flag = 0;
    if (n>2)
    {
        for (long int i=0; i<n; i++)
        {
            long int a[n-1][n-1];
            for (long int p=1; p<n; p++)
            {
                flag=0;
                for (int q=0; q<n; q++)
                {
                    if (q!=i)
                    {
                        a[p-1][q-flag] = ar[p][q];
                    }
                    else
                    {
                        flag=1;
                    }
                }    
            }
            sum = mod(sum) + mod((mod(ar[0][i])*mod(det(n-1, a))));
        }
    }
    else if (n==1)
    {
        return ar[0][0];
    }
    else
    {
        sum += mod(ar[0][0])*mod(ar[1][1]) + mod(ar[1][0])*mod(ar[0][1]);
    }
    return sum;
}
int main(void)
{
    int q,  b;
    scanf("%d", &q);
    
    long int n;
    scanf("%ld", &n);
    if (q==1)
    {
        scanf("%d", &b);
    }
    long int ar[n][n];

    for (long int i=0; i<n; i++)
    {
        for (long int j=0; j<n; j++)
        {
            scanf("%ld", &ar[i][j]);
        }
    }
    int x = mod(det(n, ar));
    int y[31];
    int c=-1;
    if (q==1)
    {   if (q == 1)
        {
            while (x!=0)
            {
                c++;
                y[c] = x%b;
                x = (x-x%b)/b;
            }
        }
        for (int j=c; j>=0; j--)
        {
            if (y[j]<=9)
            {
                printf("%d", y[j]);
            }
            else
            {
                printf("%c", y[j]+87);
            }
        }
        printf("\n");
    }
    else
    {
        printf("%d\n", x);
    }
}
