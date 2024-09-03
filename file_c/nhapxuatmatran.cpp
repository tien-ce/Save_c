#include"stdio.h"
int a[100][100], n,m;
void nhapmatran1(int x[100][100],int &n,int &m){
A:
printf("nhap gia tri n(0<n<=100):");
scanf("%d",&n);
if (n<0||n>100){
printf("vui long nhap lai n thoa man");	
goto A;
}
printf("nhap gia tri m(0<m<=100):");
scanf("%d",&m);
B:
if (m<0||m>100){
printf("vui long nhap lai m thoa man");
goto B;	
}

for(int i=0;i<m;i++){
for (int j=0;j<n;j++){
printf("x[%d][%d]= ",i,j);
scanf("%d",&x[i][j]);
}	
}
}
void xuatmatran1(int x[100][100],int n, int m){

printf("gia tri cua ma tran:\n ");
for( int i=0;i<m;i++){
for (int j=0;j<n;j++){

printf("%d\t",x[i][j]);	
}	
}	
}

int main(){
nhapmatran1(a,n,m);
xuatmatran1(a,n,m);	
}
