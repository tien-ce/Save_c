#include "stdio.h"
int main(){
	int i=0,n;
	int giaithua=1;
	 do{
		printf("nhap n>0:\n n= ");
		scanf("%d",&n);
	}while (n<=0);

	/*do{
	i++;
	giaithua=giaithua*i;
	
		
	}
	while (i<n);
	printf("giai thua cua n =%d",giaithua);
	
     
	while(i<n){
		i++;	
	
		giaithua=giaithua*i;
		
	}
		printf("i=%d",i);
	printf("\n giaithua=%d",giaithua);
	*/
	for(i=1;i<=n;i++){
	giaithua=giaithua*i;
	
	}
	printf("giaithua=%d",giaithua);	
	}
