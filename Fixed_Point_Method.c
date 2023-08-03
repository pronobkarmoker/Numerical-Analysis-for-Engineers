#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
//#define F(x) ((x)*(x)*(x) + 4*(x)*(x) -10)

double F(double x){
   return ((x)*(x)*(x) + 4*(x)*(x) -10);
}

double G(double x){
	return sqrt((10- (x)*(x)*(x))/4);
	}

int main(void){
	int n = 100 ,i;
	double a = 1.5 , c;
	
	
	printf("--------------------------------------------------------------------------\n");
	printf("iter  	 a             c        f(a)             f(c)\n");
	printf("--------------------------------------------------------------------------\n");
	
	for(i=1; i<n ; i++){
	       
	       c = G(a);
		
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf\n", i,a,c, F(a),F(c));
		if(fabs(F(c)) < EPS){
		printf("ROOT(FP) = %lf\n" , c);
		exit(0);
		}
		else{
			a=c;
		
		}     	 	 
	}
}		     
