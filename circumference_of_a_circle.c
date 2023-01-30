#include <stdio.h>
#include <math.h>

int main(){
    //calculate the circumference of a circle

    double radius; 
    const double PI = M_PI; 
    printf("\nenter the radius of the circle >> "); 
    scanf("%lf", &radius);
    double circumference = 2 * PI * radius; 
    printf("The circumference of the circle is %lf units\n", circumference);
    return 0;
}