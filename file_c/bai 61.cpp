#include "stdio.h"
int a[100][100];
int n,m;
int b[10000];
int k;
void nhapmatran(int x[100][100],int &n,int &m){
printf("nhap gia tri cua hang: n=");
scanf("%d",&n);
printf("nhap gia tri cua cot: m=");
scanf("%d",&m);	
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("x[%d][%d]=",i,j);
scanf("%d",&x[i][j]);	
}
}
}

void xuatmatran(int x[100][100],int n,int m){
for(int i=0;i<n;i++){
printf("\n");
for(int j=0;j<m;j++){
printf("%d \t",x[i][j]);	
}	
}
}
void hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void matranchuyenvi(int x[100][100],int &n,int &m){
int dem=0;
int chenhlech=n-m;
if(n==m){
for(int i=0;i<n;i++){
for(int j=dem;j<m;j++){
hoandoi(x[i][j],x[j][i]);

}
dem++;	
}	
}
else{
if(chenhlech<0){
n=m;
for(int i=0;i<n;i++){
for(int j=dem;j<m;j++){
hoandoi(x[i][j],x[j][i]);	

}	
dem++;
}
m=m+chenhlech;
}
else{
m=n;
for(int i=0;i<n;i++){
for(int j=dem;j<m;j++){
hoandoi(x[i][j],x[j][i]);	

}
dem++;	
}	
n=n-chenhlech;
}
}	
}
int main(){
nhapmatran(a,n,m);
xuatmatran(a,n,m);
matranchuyenvi(a,n,m);
printf("\n \n \n");
xuatmatran(a,n,m);
}
