#include "stdio.h"
int a[100][100];
int n,m;
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
int maxhang(int x[100][100],int n,int m){
printf("\n nhap so hang muon tim kiem max : \n");
int hang;
scanf("%d",&hang);
int maxhang=x[hang][0];	
for(int i=1;i<m;i++){
if (x[hang][i]>maxhang){
maxhang=x[hang][i];
}
}
printf("\n gia tri lon nhat cua hang %d (tinh tu 0) la:%d",hang,maxhang);	
return maxhang;
}

int main(){
nhapmatran(a,n,m);
xuatmatran(a,n,m);
maxhang(a,n,m);
}
