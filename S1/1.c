#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    int ar[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i!=j && i<j)
            {
                int p = ar[i][j];
                ar[i][j] = ar[j][i];
                ar[j][i] = p;

            }
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}
