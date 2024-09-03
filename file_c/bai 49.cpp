#include "stdio.h"
#include "limits.h"
void nhapmang (int x[],int &n,int size){
	
do {
printf("\n nhap gia tri n (0<n<=%d) : n= ",size);
scanf("%d",&n);
}
while (n<1||n>size);	
for (int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);	
}
	
}
void xuatmang(int x[],int n,int phanbiet){
printf("gia tri cua mang %c:",phanbiet)	;
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
int kiemtramangconlientiep(int x1[],int x2[],int n1,int n2){
int k=0;
if (n2<=n1){	
for(int i1=0;i1<n1;i1++){
if(x1[i1]==x2[0]){int i2;
for(i2=0;i2<n2;i2++){
if (x2[i2]!=x1[i1+i2])
break;	
}
if (i2==n2)
k=1;		
}
}
}
return k;
}
int main(){
int a[100],b[200];
int n1,n2;
nhapmang(a,n1,100);
xuatmang(a,n1,'A');
nhapmang(b,n2,200);
xuatmang(b,n2,'B');
int kiemtra=kiemtramangconlientiep(a,b,n1,n2);
if (kiemtra==1){
printf("\n b la mang con lien tiep cua a");	
}else {
printf("\n b khong phai la mang con lien tiep cua a");	
}	
}
