#include "stdio.h"
void nhapmang( int x[100],int &n){
	do{
	printf("nhap n (o<n<=100):n=");
	scanf("%d",&n);
}while (n<1||n>100);
for(int i=0;i<n;i++){
	printf("x[%d]=",i);
	scanf("%d",&x[i]);
}
}
void xuatmang(int x[100],int n){
	printf("gia tri cua mang ");
	for(int i=0;i<n;i++){
		printf("%d ",x[i]);
	}
}
int timkiem(int x[100],int n,int giatri){
	int kq=0;
    for (int i=0;i<n;i++){
    if (x[i]==giatri){
    	kq=1;
	}	
	}
	return kq;	
}
int thuchientimkiem(int x[100],int n){
	int giatricantim;
	printf("\n nhap gia tri can tim:");
	scanf("%d",& giatricantim);
    int kq=timkiem(x,n,giatricantim);
    if(kq==1){
	printf("tim thay");
	}else{
	printf("khong tim thay");
	}
 }
 int timsogiatri(int x[100],int n,int giatri){
 	 int sogiatri=0;
	  for(int i=0;i<n;i++){
 	 	if (x[i]<giatri){
 	 	sogiatri+=1;		 		
		  }
		  }
	return sogiatri;
	}
int thuchientimsogiatri(int x[100],int n){
	int giatri;
	printf("\n nhap gia tri de so sanh:");
	scanf("%d",&giatri);
	int r=timsogiatri(x,n,giatri);
	return r;
	
}	  
	  	
int main(){
	int a[100],n;
	nhapmang(a,n);
	xuatmang(a,n);
	thuchientimkiem(a,n);
	int r=thuchientimsogiatri(a,n);
	printf("so gia tri thoa man dieu kien la:%d ",r) ;
}
