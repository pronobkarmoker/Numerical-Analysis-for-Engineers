#include<stdio.h>
#include<math.h>
int main(){
	double a  = 0;
    double b= 2 * 3.1416;
	double m = 100;
	double h = (b-a)/m;
	
	printf("\"x\", \"sin(x)\"\n");
	double x= a;
	for( int i=0 ; i <= m ; i++){
	    x+=h;
	    printf("%lf , %lf\n",x,sin(x));
	    printf("\n");
	    }
	//x= b;
	//printf("%lf , %lf\n",x,sin(x));    
	return 0;
}