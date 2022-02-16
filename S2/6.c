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
double eval(int n, double ar[n + 1], double x)
{
    double ans = ar[n];
    for (int i = n; i > 0; i--)
    {
        ans = ans * x + ar[i - 1];
    }
    return ans;
}
int main(void)
{
    int n;
    scanf("%d", &n);

    double ar[n + 1];
    for (int i = n; i >= 0; i--)
    {
        scanf("%lf", &ar[i]);
    }

    int q = 1, i = 1;
    double root[100];
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    root[0] = (a + b) / 2;
    printf("%lf\n", root[0]);

    while (q == 1)
    {
        double mid = (a + b) / 2;

        if (eval(n, ar, a) * eval(n, ar, mid) < 0)
        {
            b = mid;
        }
        else if (eval(n, ar, a) * eval(n, ar, mid) > 0)
        {
            a = mid;
        }
        else
        {
            q = 0;
        }

        root[i] = (a + b) / 2;

        double err = abs(root[i] - root[i - 1]) / root[i] * 100;
        printf("%lf %lf\n", root[i], err);

        if (q == 1)
        {
            scanf("%d", &q);
        }

        i++;
    }
}
