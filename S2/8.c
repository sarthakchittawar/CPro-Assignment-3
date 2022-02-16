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
double dif(int n, double ar[n + 1], double x)
{
    double ans;
    for (int i = n; i > 0; i--)
    {
        double r = ar[i] * i;
        for (int j = 0; j < i - 1; j++)
        {
            r *= x;
        }
        ans += r;
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
    scanf("%lf", &root[0]);
    scanf("%lf", &root[1]);

    while (q == 1)
    {
        root[i + 1] = root[i] - (eval(n, ar, root[i]) * (root[i] - root[i - 1]) / (eval(n, ar, root[i]) - eval(n, ar, root[i - 1])));

        double err = abs(root[i + 1] - root[i]) / root[i + 1] * 100;

        printf("%lf %lf\n", root[i + 1], err);

        if (q == 1)
        {
            scanf("%d", &q);
        }

        i++;
    }
}
