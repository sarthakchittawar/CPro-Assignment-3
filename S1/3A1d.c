#include <stdio.h>
int main(void)
{
    long int m, n;
    scanf("%ld", &m);
    scanf("%ld", &n);

    long int ar[m][n];
    for (long int i=0; i<m; i++)
    {
        for (long int j=0; j<n; j++)
        {
            scanf("%ld", &ar[i][j]);
        }
    }
    long int vec[n][1];
    for (long int i=0; i<n; i++)
    {
        scanf("%ld", &vec[i][0]);
    }
    long int prod[m][1], p;
    for (long int i=0; i<m; i++)
    {
        p=0;
        for (long int j=0; j<n; j++)
        {
            p+= ar[i][j] * vec[j][0];
        }
        prod[i][0] = p;
    }
    for (long int i=0; i<m; i++)
    {
        printf("%ld\n", prod[i][0]);
    }
}