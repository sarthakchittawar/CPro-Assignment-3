#include <stdio.h>
int main(void)
{
    long int m, n, p;
    scanf("%ld", &m);
    scanf("%ld", &n);
    scanf("%ld", &p);

    long int ar1[m][n];
    for (long int i = 0; i < m; i++)
    {
        for (long int j = 0; j < n; j++)
        {
            scanf("%ld", &ar1[i][j]);
        }
    }
    long int ar2[n][p];
    for (long int i = 0; i < n; i++)
    {
        for (long int j = 0; j < p; j++)
        {
            scanf("%ld", &ar2[i][j]);
        }
    }
    long int prod[m][p], q;
    for (long int i = 0; i < m; i++)
    {

        for (long int j = 0; j < p; j++)
        {
            q = 0;
            for (long int k = 0; k < n; k++)
            {
                q += ar1[i][k] * ar2[k][j];
            }
            prod[i][j] = q;
        }
    }
    for (long int i = 0; i < m; i++)
    {
        for (long int j = 0; j < p; j++)
        {
            printf("%ld ", prod[i][j]);
        }
        printf("\n");
    }
}
