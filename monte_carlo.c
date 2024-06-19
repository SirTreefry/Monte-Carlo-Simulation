//Andrew Trefry
//Monter carlo simulation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//struct 1 probaility dustribution equation

void sum_loop(){
float seed_value = 100000;
float seed = seed_value;
float x;
float y;
float sum = 0;
float a = 1;
float total_val;
srand((unsigned int)time(NULL));
//x^2+y^2 > 1 circle values
//x^2+y^2 <= 1
while(seed_value > 0){
    x  = ((float)rand()/(float)(RAND_MAX)) * a;
    y  = ((float)rand()/(float)(RAND_MAX)) * a;
    //printf("%f",x);
    //printf("%f",y);
        if((x*x + y*y) <= 1){
    sum++;
    }
    seed_value--;}
total_val =4*sum*((1)/(seed));
printf(" estimated value:");
printf("%f",total_val);
}

int main(){
sum_loop();//function for simulation


return 0;
}
