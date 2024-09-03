#include "stdio.h"
int main (){
	int a,b;
	int ucln;
	printf("tim ucln cua a va b");
	printf( "\n nhap gia tri cua a=");
	scanf("%d",&a);
	printf("\n nhap gia tri cua b=");
	scanf("%d",&b);
	
	if(a==0||b==0){
		ucln=a+b;
		printf("\n ucln=%d",ucln);
		
	}else{while(a!=b){
	
		while (a>b){
			a=a-b;
		}while (b>a){
			b=b-a;
		}}
        ucln=b;
		printf("\n ucln=%d",ucln);     	
				 
				 }
}
