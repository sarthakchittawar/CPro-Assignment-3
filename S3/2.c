#include <stdio.h>

#define m 1000000007

int det(int n, int ar[n][n])
{
    int sum = 0;
    int sign = 1;
    if (n > 2)
    {

        for (int i = 0; i < n; i++)
        {
            int a[n - 1][n - 1];
            for (int p = 1; p < n; p++)
            {
                int q = 0, c = 0;
                while (q < n && c != n - 1)
                {
                    if (q != i)
                    {
                        a[p - 1][c] = ar[p][q];
                        c += 1;
                    }
                    q++;
                }
            }
            sum = sum + sign * (ar[0][i]) * (det(n - 1, a));
            sign = -sign;
        }
    }
    else if (n == 1)
    {
        if (ar[0][0] == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        sum += ar[0][0] * ar[1][1] - ar[1][0] * ar[0][1];
    }
    return sum;
}

int checkLU(int n, int ar[n][n])
{
    for (int i = 0; i < n; i++)
    {
        if (det(i + 1, ar) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    double u[n][n], l[n][n];
    int ar[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &u[i][j]);
            ar[i][j] = u[i][j];
            if (i == j)
            {
                l[i][j] = 1;
            }
            else
            {
                l[i][j] = 0;
            }
        }
    }
    if (n != 1 && checkLU(n, ar) == 1)
    {

        double r;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                r = u[j][i] / u[i][i];

                for (int k = 0; k < n; k++)
                {
                    u[j][k] -= r * u[i][k];
                }
                if (i != j)
                {
                    l[j][i] = r;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.5lf ", l[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.5lf ", u[i][j]);
            }
            printf("\n");
        }
    }
    else if (n == 1)
    {
        printf("1.00000\n%.5lf\n", u[0][0]);
    }
    else
    {
        printf("No LU decomposition\n");
    }
}
