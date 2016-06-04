#include <stdio.h>
#include "functional.h"

int main()
{
    float a, b, c, x1, x2, discr; 
    int rootz;

    printf("\n Input coefficients and const.:\n\n a*x^2+b*x+c=0\n\n Input a: ");
    scanf("%f", &a);

    if (a == 0) {
        printf("\n a=0, the equation isn't squre!\n Input correct a: ");
        scanf("%f", &a);
    }

    printf("\n Input b: ");
    scanf("%f", &b);

    printf("\n Input c: ");
    scanf("%f", &c);

    printf("\n (%.2f)*x^2+(%.2f)*x+(%.2f)=0\n", a, b, c);

    rootz = worx(a, b, c, &discr, &x1, &x2);
	
	printf("\n Discriminant: %f\n", discr);
	
    if (!rootz) {
        printf(" No real roots\n");
    } else if (rootz == 1) {
        printf(" x1 = %f\n", x1);
    } else {
        printf(" x1 = %f\n", x1);
        printf(" x2 = %f\n", x2);
    }

    return 0;
}
