#include <stdio.h>

double abs(double n)
{
    if (n < 0)
    {
        return -n;
    }
    else
    {
        return n;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int ar[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i][n]);
    }

    double g[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &g[i]);
    }
    double err[n];
    int q=1;
    while (q==1)
    {
        for (int i = 0; i < n; i++)
        {
            double sum = ar[i][n];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum -= ar[i][j] * g[j];
                }
            }
            double k = g[i];
            g[i] = sum / ar[i][i];
            err[i] = abs(k-g[i])/g[i]*100;
        }
        for (int i = 0; i < n; i++)
        {
            printf("%lf %lf\n", g[i], err[i]);
        }
        scanf("%d", &q);
    }
}
