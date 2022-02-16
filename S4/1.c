#include <stdio.h>

const long long int m = 1000000007;

long long int mod(long long int x)
{
    if (x < 0)
    {
        return (x + m) % m;
    }
    else
    {
        return x % m;
    }
}

long long int det(long long int n, long long int ar[n][n])
{
    long long int sum = 0;
    int flag = 0;
    if (n > 2)
    {

        for (long long int i = 0; i < n; i++)
        {
            long long int a[n - 1][n - 1];
            for (long long int p = 1; p < n; p++)
            {
                flag = 0;
                for (int q = 0; q < n; q++)
                {
                    if (q != i)
                    {
                        a[p - 1][q - flag] = ar[p][q];
                    }
                    else
                    {
                        flag = 1;
                    }
                }
            }
            sum = mod(mod(sum) + ((i%2==0)? 1: -1) * mod(mod(ar[0][i]) * mod(det(n - 1, a))));
        }
    }
    else if (n == 1)
    {
        return ar[0][0];
    }
    else
    {
        sum += mod(ar[0][0]) * mod(ar[1][1]) - mod(ar[1][0]) * mod(ar[0][1]);
    }
    return sum;
}
int main(void)
{
    long long int n;
    scanf("%lld", &n);
    long long int ar[n][n];

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            scanf("%lld", &ar[i][j]);
        }
    }
    printf("%lld\n", det(n, ar) % m);
}
