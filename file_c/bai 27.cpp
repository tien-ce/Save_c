#include "stdio.h"
#include "math.h"
int KTsonguyento(int x){
	int i;
	if(x<=1){
		return 0;
		
	}else{
	for	(i=2;i<=x-1;i++){
	if(x % i !=0){
	return 0;	
	}
	return 1;
		
		
	}
	
	}
}
int main(){
	int n;
	printf("nhap n = ");
	scanf("%d",&n);
	int kt=KTsonguyento(n);
    if(kt==0){
    	printf("n la so nguyen to");
    	
	}else{
		printf("n khong phai so nguyen to");
	}	

}
	
	
