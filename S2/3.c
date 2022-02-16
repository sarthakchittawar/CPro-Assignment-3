#include <stdio.h>
int main(void)
{
    int n, a;
    scanf("%d", &n);
    int ar[n+1];
    for (int i=n; i>=0; i--)
    {
        scanf("%d", &ar[i]);
    }
    scanf("%d", &a);
    double ans=0, p;
    for (int i=n; i>=0; i--)
    {
        p=1;
        for (int j=0; j<i; j++)
        {
            p = p*a;
        }
        ans += ar[i]*p;
    }
    printf("%lf\n", ans);
}
