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
void xoahang(int x[100][100],int &n,int m,int hang){
for(int j=0;j<m;j++){
x[hang][j]=x[hang+1][j];	
}
n--;	
}
void thuchienxoahang(int x[100][100],int &n,int m){
int hang;
do{
printf("\n nhap hang muon xoa(hang < n) : ");
scanf("%d",&hang);
}
while(hang>=n);
xoahang(x,n,m,hang);
}
void xoacot(int x[100][100],int n,int &m,int cot){
for(int i=0;i<n;i++){
x[i][cot]=x[i][cot+1];
	
}
m--;	
}
void thuchienxoacot(int x[100][100],int n,int &m){
int cot;
do{
printf("nhap cot muon xoa(cot < m): ");
scanf("%d",&cot);	

}
while(cot>=m);	
xoacot(x,n,m,cot);

}
int main(){
nhapmatran(a,n,m);
xuatmatran(a,n,m);
thuchienxoahang(a,n,m);
printf("\n \n \n");
xuatmatran(a,n,m);
thuchienxoacot(a,n,m);
xuatmatran(a,n,m);
}
