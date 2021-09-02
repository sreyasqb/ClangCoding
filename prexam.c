#include <stdio.h>

double area_circle(int diameter){
    return 3.14159*diameter*diameter/4.0;
}
double circumference_circle(int diameter){
    return 3.14159*diameter;
}

int main(){
    int diameter;
    printf("Enter the diameter : ");
    scanf("%d",&diameter);
    printf("The Area is : %lf\n",area_circle(diameter));
    printf("The Cirumferance is : %lf\n",circumference_circle(diameter));
}