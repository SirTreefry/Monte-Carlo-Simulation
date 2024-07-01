//Andrew Trefry
//Monter carlo simulation for a neutron transport
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//struct 1 probaility dustribution equation
#define M_PI 3.141592
//3.14159265358979323846
//put specific values for C_C and C_S for cross section of capture and trasnport

void sum_loop(float seed_value){
int repeat_t,TIMES;;
double x,u ,L,d,U_chance ;//u is the 0,1 and L is the length value
float n = seed_value; //total neutrons used
double T = 1; //thickness of sheet
double t_10 = 10, coeff = -28;
double C_C = 5.5*pow(t_10,coeff);//cross section of catpure
double C_s = 4.74*pow(t_10,coeff);//cross section of scatter
double neutron_c = C_C + C_s;//total cross section
double a = 1,C;
double total_val,total_val_1,total_val_2;
double reflect_count=0;
double absorb_count=0;//absorbtion counter
double trans_count=0; //transmission through the plate counter x > Tdouble reflect_count; //reflection count x < 0
srand((unsigned int)time(NULL));

while(seed_value > 0){
    repeat_t = 0;
    x = 0;
    while(repeat_t == 0){
    u = ((double)rand()/(double)(RAND_MAX)) * a;
    L = -1*(1/ neutron_c )*log(u);
    d = ((double)rand()/(double)(RAND_MAX)) * M_PI;
    x = L*cos(d) + x;
    if(x > T){
       trans_count++;
       repeat_t = 1;
            }//trasnmitted
    else if(x < 0){
       reflect_count++;
       repeat_t = 1;
            }//trasnmitted
    else{
    C = C_C / neutron_c;
    U_chance = ((double)rand()/(double)(RAND_MAX)) * 1;

    if(C > U_chance){
            TIMES++;
            absorb_count++;
            repeat_t = 1;
            }//absorbed
        }

    }
    seed_value--;}
total_val = absorb_count / n;
    printf(" absorption fraction: %f\n", total_val);

total_val_1 = trans_count / n;
    printf(" transmission fraction: %f\n", total_val_1);

total_val_2 = reflect_count / n;
printf(" reflection fraction: %f\n", total_val_2);


}

int main(){
float pre_val;
int calc = 1;
while(calc > 0){
printf("Number of iterations:");
scanf("%f",&pre_val);//number of iterations to run;
printf("\n");
sum_loop(pre_val);//function for simulation
calc--;
}



return 0;
}
