#include "stdio.h"
int main(){
	int i=0,n;
	Nhap:
	printf("nhap n>0 n= ");
	scanf("%d",&n);
	if(n<=0){	
    goto Nhap;
    }else {
    	while(i<n){
    	i++;
    	if(i%2!=0) continue;
		printf("\n %d",i);	
		
		}
    	
	}
    	
	
	
	
}
