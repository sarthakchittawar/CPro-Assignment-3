#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    double a[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i][n]);
    }

    double r;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            r = a[j][i] / a[i][i];

            for (int k = 0; k < n + 1; k++)
            {
                a[j][k] -= r * a[i][k];
            }
        }
    }
    double ans[n];
    ans[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= i; j--)
        {
            double temp = a[i][j + 1] * ans[j + 1];
            a[i][n] -= temp;
        }
        ans[i] = a[i][n] / a[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.8lf\n", ans[i]);
    }
}
