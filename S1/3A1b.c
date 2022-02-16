#include <stdio.h>
int main(void)
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int max;
    if (m > n)
    {
        max = m;
    }
    else
    {
        max = n;
    }
    int ar[max][max];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }

    for (int i = 0; i < max; i++)
    {
        for (int j = i; j < max; j++)
        {
            int p = ar[i][j];
            ar[i][j] = ar[j][i];
            ar[j][i] = p;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}