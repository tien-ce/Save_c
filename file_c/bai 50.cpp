#include "stdio.h"
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
printf("\n gia tri cua mang %c:",phanbiet)	;
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
void mangconkhonggiam(int x1[],int n1,int chuoi[100]){
for(int m=0;m<n1;m++){
chuoi[m]=1;	
}
for (int i=n1-1;i>=0;i--){
if(x1[i]>=x1[i-1]){
chuoi[i-1]=chuoi[i]+1;	
}	
}
xuatmang(chuoi,n1,'C');	
}
void mangconkhonggiamdainhat(int x1[],int n1){
int chuoi[100];
mangconkhonggiam(x1,n1,chuoi);
int max=chuoi[0];

for (int i=0;i<n1-1;i++){
if (max<chuoi[i+1]){
max=chuoi[i+1];
}	
}
for(int j=0;j<n1;j++){
if (chuoi[j]==max){
printf(" \n mang con khong giam dai nhat: ");
for(int a=j;a<j+max;a++){
printf(" %d ",x1[a]);	
}	
}	
}
}


int main(){
int a[100],b[100];
int n1,n2; 
nhapmang(a,n1,100);
xuatmang(a,n1,'A');
mangconkhonggiamdainhat(a,n1);
}
