#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",  &n);
    int ar[n+1];
    for (int i=0; i<=n; i++)
    {
        scanf("%d", &ar[i]);
    }
    int x;
    scanf("%d", &x);

    int ans=ar[n];
    for (int i=n; i>0; i--)
    {
        ans = ans*x + ar[i-1];
    }
    printf("%d\n", ans);
}
