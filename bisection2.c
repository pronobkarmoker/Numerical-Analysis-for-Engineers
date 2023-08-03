#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) -5)

int main(void){
	int n = 100 ;
	double a = 1.25 , b= 1.5 , c , x= -5 , y= 5;
	
	for(int i= 0; i< 6; i++){
		a= x + (i*(y-x)/ 6);
		b= x + ((i+1)*(y-x)/ 6);
		
		if(F(a)*F(b) >0){ 
		printf("range[%d] : [%lf ,%lf] -> NO ROOT!!!\n ",i, a,b);
		continue;
	        }
	for(int j=0; j<n ; j++){
		c=(a+b)/2;
		
		if(fabs(F(c)) < EPS){
		
		printf("range[%d] : [%lf ,%lf] ->  ",i, a,b);
		printf("ROOT(BM2) = %lf\n" , c);
		break;
		}
		if(F(a)*F(c) <0)
			b =c;
		else 
		     a =c ;	 
		}
	}
}		     


//range[0] : [-3.618037 ,-3.618031] ->  ROOT(BM2) = -3.618034
//range[2] : [-1.381969 ,-1.381963] ->  ROOT(BM2) = -1.381966
//range[3] : [0.999997 ,1.000004] ->  ROOT(BM2) = 1.000001

