#include "stdio.h"
int a[100][100];
int n,m;

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
void sapxeptang(int x[100][100],int n,int m){
int k=m*n;
for(int i=0;i<k-1;i++){
for(int j=i+1;j<k;j++){
if(x[i/m][i%m]>x[j/m][j%m]){
hoandoi(x[i/m][i%m],x[j/m][j%m]);	
}	
}	
}	
}
int main(){
nhapmatran(a,n,m);
xuatmatran(a,n,m);
sapxeptang(a,n,m);
printf("\n \n \n");
xuatmatran(a,n,m);
}
