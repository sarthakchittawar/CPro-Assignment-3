#include <stdio.h>
#include <math.h>
int main(void)
{
    int t;
    double zero=0.0;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        double a,b,c;
        scanf("%lf", &a);
        scanf("%lf", &b);
        scanf("%lf", &c);

        double det = (b*b - 4*a*c);
        double d;
        if (det<0)
        {
            det = -det;
            d = sqrtf(det);
    
            printf("%lf %lf\n", -b/(2*a), d/(2*a));
            printf("%lf %lf\n", -b/(2*a), -d/(2*a));
        }
        else
        {
            d = sqrt(det);
            printf("%lf %lf\n", (-b/(2*a))+(d/(2*a)), zero);
            printf("%lf %lf\n", (-b/(2*a))-(d/(2*a)), zero);
        }
    }
}
