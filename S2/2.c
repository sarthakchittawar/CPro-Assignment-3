#include <stdio.h>
int abs(int n)
{
    if (n < 0)
    {
        n = -n;
    }
    return n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    n = n - 1;
    int ar[n + 1];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }

    int dif[n + 1][2];

    for (int i = 0; i <= n; i++)
    {
        dif[i][0] = 0;
        dif[i][1] = 0;
    }
    int p = 0;
    for (int i = n; i > 0; i--)
    {
        if (ar[i] != 0)
        {
            dif[p][0] = i * ar[i];
            dif[p][1] = i - 1;
            p += 1;
        }
    }
    int a = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (dif[i][0] != 0)
        {
            if (a != 0 && dif[i][0] > 0)
            {
                printf(" + ");
            }
            if (dif[i][0] < 0)
            {
                if (a != 0)
                {
                    printf(" - ");
                }
                else
                {
                    printf("-");
                }
            }
            if (dif[i][1] == 0)
            {
                printf("%d", abs(dif[i][0]));
            }
            else if (dif[i][1] == 1)
            {
                if (abs(dif[i][0]) != 1)
                {
                    printf("%dx", abs(dif[i][0]));
                }
                else
                {
                    printf("x");
                }
            }
            else
            {
                if (abs(dif[i][0]) != 1)
                {
                    printf("%dx^%d", abs(dif[i][0]), dif[i][1]);
                }
                else
                {
                    printf("x^%d", dif[i][1]);
                }
            }
            a += 1;
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] != 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        if (dif[n][1] == 0 && dif[n][0] == 0)
        {
            printf("0");
        }
    }
    printf("\n");
}
