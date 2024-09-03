#include "stdio.h"
#include "math.h"
int kiemtra1SNT(int a){
	int i;
	if(a<=1){
		return 0;
	}
    for(i=2;i<=a-1;i++){
    	if(a % i==0)
    		return 0;
}
		return 1;
		
	
	}



int main(){
	int k,n;
	printf("xuat cac so nguyen to nho hon n");
	do{
	printf("\n nhap n>=1 n=");
	scanf("%d",&n);} while(n<=1);
	
	for (k=2;k<n;k++){
		int kt;
    kt=kiemtra1SNT(k);
	if(kt==1){
		printf("\n %d",k);
		
	}
		
		
	}
}


