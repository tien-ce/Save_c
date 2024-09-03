#include "stdio.h"
#include "math.h"
int main(){
	int a,b,c;
	float x1,x2;
	printf("a=");
	scanf("%d",&a);
	switch(a){
		case(0):
			printf("\n phuong trinh bac nhat");
		break;
		default:
		printf("b=");
		scanf("%d",&b);
		printf("c=");
		scanf("%d",&c);	
		float denta=pow(b,2)-4*a*c;
		printf("denta=%.2f",denta);
		if(denta<0){printf("\n phuong trinh vo nghiem");
		}else if (denta==0){
		float x1=(float)-b/(2*a);
		printf("\n phuong trinh co nghiem kep x1=x2=%.2f",x1);
			
		}else{
		    x1=(-b+sqrt(denta))/(2*a);
			x2=(-b-sqrt(denta))/(2*a);
			printf("\n phuong trinh co 2 nghiem \n x1=%.2f \n x2=%.2f",x1,x2);
		
		}
		}
		
		
	}
