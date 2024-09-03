#include "stdio.h"
#include "math.h"
int main(){
	float x;
	printf("nhap gia tri cho x:x=");
	scanf("%f",&x);
	float fx;
	if(x<-5){
	fx=x;	
	}else if(x>=-5 && x<0){
	fx=1/x;
	}else if(x>0 && x<4){
	fx=pow(x,2)-4;	
	}else{
	fx=6/pow(x-4,2);	
	} 
	printf("f(x)=%f",fx);
	
}
