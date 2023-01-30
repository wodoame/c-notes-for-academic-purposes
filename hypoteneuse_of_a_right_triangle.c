#include <stdio.h>
#include <math.h>

int main(){
    //calculate the hypoteneuse of a right-angled triangle
    double a, b, c;

    printf("\na = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b); 
    c = hypot(a, b);  // c = sqrt((a * a) + (b * b)) or c = sqrt(pow(a, 2) + pow(b, 2)) were alternatives I didn't like 
    printf("the hypoteneuse of the right-angled triangle is %.2lf\n", c);
    
    
    
    
}