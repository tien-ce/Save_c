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
printf("\n gia tri cua mang :\n");
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
printf("%d\t",x[i][j]);	
}
printf("\n");	
}	
}
int timkiem(int x[100][100],int m,int n,int giatri){
int kq=0;
int dem=0;

for(int i=0;i<m;i++){
for (int j=0;j<n;j++){
if(x[i][j]==giatri){
kq=1;
dem++;	
}	
}	
}
if(kq==0){
printf(" gia tri khong xuat hien trong mang");	
}
else {
printf(" gia tri co xuat hien trong mang");
printf("\n gia tri xuat hien %d lan",dem);	
}


 	
}
void timkiemgiatri(int x[100][100],int m,int n){
int k;
int giatri;
do{
printf("nhap gia tri can tim:");
scanf("%d",&giatri);
timkiem(a,m,n,giatri);
printf("\n nhap so k bat ki de tiep tuc, nhap k=0 de dung lai:");
printf("\n k= ");
scanf(" %d",&k);	
}
while(k!=0);
} 
int main(){
nhapmatran(a,m,n);
xuatmatran(a,m,n);
timkiemgiatri(a,m,n); 
}
