#include "stdio.h"
#include "limits.h"
void nhapmang (int x[],int &n,int size){
	
do {
printf("\n nhap gia tri n (0<n<=%d) : n= ",size);
scanf("%d",&n);
for (int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);	
}
}
while (n<1||n>size);		
}
void xuatmang(int x[],int n){
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
void tachmang(int x[],int y[],int z[],int &n,int &m,int &k){
int i2=0,i3=0;
m=0,k=0;
for(int i=0;i<n;i++){
if(x[i]%2==0){
y[i2]=x[i];
i2++;
m++;	
}
else {
z[i3]=x[i];
i3++;
k++;	
}	
}
}
int main(){int a[100],b[100],c[100];
int n1,n2,n3;
nhapmang(a,n1,101,'1');
xuatmang(a,n1);
tachmang(a,b,c,n1,n2,n3);
printf("\n gia tri chan  : ");
xuatmang(b,n2);
printf("\n gia tri le : ");
xuatmang(c,n3);	
}
