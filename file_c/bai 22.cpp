#include "stdio.h"
int main(){
	/* int i,n;
	int tong=0;
	printf("nhap gia tri n=");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		tong=tong+i;
		printf("\n tong=%d",tong);
	}*/
	int i=0 ,n;
	int tong=0;
	printf("gia tri n=");
	scanf("%d",&n);
	while(i<=n){
		tong=tong+i;
		++i;
			
	}
	printf("\n tong=%d",tong);
}
