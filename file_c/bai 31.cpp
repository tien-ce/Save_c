#include "stdio.h"
int truyenthamtri(int a,int b){
	int tamthoi=a;
	a=b;
	b=tamthoi;
}
int truyenthamchieu(int &a, int &b){
	int tamthoi=a;
	a=b;
	b=tamthoi;
	
}
int main(){
	int a,b;
	printf("\n nhap gia tri a,b");
	scanf("%d%d",&a,&b);
    printf("\n gia tri ban dau a=%d \n b=%d",a,b);
    truyenthamchieu(a,b);
    printf("\n gia tri a,b sau khi truyen tham chiue \n a=%d \n b=%d",a,b);
    
}
