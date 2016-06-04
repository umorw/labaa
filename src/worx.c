#include <math.h>

int worx(float a, float b, float c, float *discr, float *x1, float *x2)
{
    int nroots;
	*discr = b * b - 4 * a * c;
	
	if ((a == 0 && b == 0 && c == 0) || *discr < 0) {
	   	nroots = 0;
    	return nroots;
    }
     
	if (*discr == 0) {
        *x1 = (-b) / (2 * a);
        nroots = 1;
    }

    if (*discr > 0) {
        *x1 = (-b - sqrt(*discr)) / (2 * a);
        *x2 = (-b + sqrt(*discr)) / (2 * a);
        nroots = 2;
    }

    return nroots;
}
