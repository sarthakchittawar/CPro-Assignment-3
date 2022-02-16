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

    double ar[n][n];
    double g[n];
    double eigen[100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &ar[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &g[i]);
    }

    double ans[n];
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += ar[i][j] * g[j];
        }
        ans[i] = sum;
    }
    eigen[0] = ans[0];
    for (int i = 0; i < n; i++)
    {
        g[i] = ans[i] / eigen[0];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", g[i]);
    }
    printf("%lf\n\n", eigen[0]);


    int e = 1, q = 1;
    while (q == 1)
    {
        double ans[n];
        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += ar[i][j] * g[j];
            }
            ans[i] = sum;
        }
        eigen[e] = ans[0];
        for (int i = 0; i < n; i++)
        {
            g[i] = ans[i] / eigen[e];
        }

        for (int i = 0; i < n; i++)
        {
            printf("%lf\n", g[i]);
        }
        double err = abs(eigen[e] - eigen[e - 1]) / eigen[e] * 100;
        printf("%lf %lf\n", eigen[e], err);

        e++;
        scanf("%d", &q);
    }
}
