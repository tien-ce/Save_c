#include"stdio.h"
int a[100][100];
int m,n;
void nhapmatran(int x[100][100],int &m,int &n){
do{
printf("nhap m(0<m<=100):m= ");
scanf("%d",&m);
printf("\n nhap n(0<n<=100):n=  ");
scanf("%d",&n);	
}while(m<1||n<1||m>100||n>100);	
for(int i=0;i<m;i++){
for (int j=0;j<n;j++){
printf("x[%d][%d]= ",i,j);
scanf("%d",&x[i][j]);	
}	
}
}
void xuatmatran(int x[100][100],int m,int n){
printf("\n gia tri cua mang :\n ");
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
printf("%d\t",x[i][j]);	
}
printf("\n");	
}	
}
int main(){
nhapmatran(a,m,n);
xuatmatran(a,m,n);	
}
