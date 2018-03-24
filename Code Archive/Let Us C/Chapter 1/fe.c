/* date: Dec 20th 2017 */

#include <stdio.h>
#include <math.h>

int main(){

    float l,b,r,pr,ar,pc,ac;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &l);
    printf("\n");

    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &b);
    printf("\n");

    printf("Enter the radius of the circle: ");
    scanf("%f", &r);
    printf("\n");

    pr = (2 * l) + (2 * b);
    ar = l * b;
    pc = 2 * M_PI * r;
    ac = M_PI * pow(r, 2.0);

    printf("Rectangle:\n  Perimeter:%f\n  Area:%f\n",pr,ar);
    printf("Circle:\n  Perimeter:%f\n  Area:%f\n",pc,ac);

    return 0;
}
