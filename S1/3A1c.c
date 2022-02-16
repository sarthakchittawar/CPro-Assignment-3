#include <stdio.h>
int main(void)
{
    long int m, n;
    scanf("%ld", &m);
    scanf("%ld", &n);
    long int ar1[m][n];
    for (long int i=0; i<m; i++)
    {
        for (long int j=0; j<n; j++)
        {
            scanf("%ld", &ar1[i][j]);
        }
    }
    long int ar2[m][n];
    for (long int i=0; i<m; i++)
    {
        for (long int j=0; j<n; j++)
        {
            scanf("%ld", &ar2[i][j]);
        }
    }

    long int ar[m][n];
    for (long int i=0; i<m; i++)
    {
        for (long int j=0; j<n; j++)
        {
            ar[i][j] = ar1[i][j] + ar2[i][j];
        }
    }
    for (long int i=0; i<m; i++)
    {
        for (long int j=0; j<n; j++)
        {
            printf("%ld ", ar[i][j]);
        }
        printf("\n");
    }
   
}