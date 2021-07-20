#include <stdio.h>
#include <math.h>
int main()
{
    double A, B, V;
    scanf("%lf %lf %lf", &A, &B, &V);
    printf("%.0lf\n", ceil(((V - B) / (A - B))));
    return 0;
}