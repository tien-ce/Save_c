#include "stdio.h"
int main(){
	int chon;
	float f,c;
	do {
	printf("thoat chon 1 \n chuyen f sang c chon 2 \n chuyen tu c sang f chon 3");
	printf("\n chon:");
	scanf("%d",&chon);	
	}while(chon!=1&&chon!=2&&chon!=3);
	if (chon==2){
	printf("do f:");
	scanf("%f",&f);	
	c=(float)5/9*(f-32);
	printf("%f do c",c);
	
	
	}else if (chon==3){
		printf("do c:");
		scanf("%f",&c);
		f=(float)9/5*c+32;
		printf("%f do f",f);
	}else{
	 return 0;
	}
}
