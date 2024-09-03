#include "stdio.h"
#include "limits.h"
#include "conio.h"
void nhapmang2(int x[],int &n){

do {
printf("nhap gia tri n(0<n<=100): n="); 	
scanf("%d",&n);
}while(n<1||n>100)	;
for (int i=0;i<n;i++){
	printf("x[%d]=",i);	
	scanf("%d",&x[i]);	
}					
}
void xuatmang2(int x[],int n){
printf("gia tri cua mang la: ");
for(int i=0 ; i<n;i++){
printf(" %d ",x[i]);
}	
}
void chenphantucuoimang(int x[],int &n){
int giatri;	
int size=sizeof(x)/sizeof(x[0]);
if (size==n){
printf("da dat toi da phan tu ");	
}
else{
printf("\n nhap gia tri can them cuoi mang : ");
scanf("%d",&giatri);
x[n]=giatri;
n++;
}
}
void chenphantudaumang(int x[],int &n ){
int giatri;
printf("nhap phan tu them dau mang :");
scanf("%d",&giatri);
n++;	
for(int i=n-1;i>0;i--){
x[i]=x[i-1];	
}
x[0]=giatri;
}	
void chenphantuvaovitri(int x[],int &n){
int vitri,giatri;
printf("\nnhap vi tri muon them:");
scanf("%d",&vitri);
printf("nhap gia tri muon them:");
scanf("%d",&giatri);
n++;
for(int i=n-1;i>vitri;i--){
x[i]=x[i-1];
}	
x[vitri]=giatri;	
}
int main(){
int a[100],n;
char giatri;
do{
printf("\n MENU: chon ham muon dung \n ");
printf("1-nhapmang\n ");
printf("2-xuatmang\n ");
printf("3-them phan tu vao cuoi mang\n ");
printf("4-them phan tu vao dau mang\n ");
printf("5-them phan tu vao vi tri bat ki\n ");
printf("x-exit\n");
printf("lua chon cua ban la: ");
scanf(" %c",&giatri);
if(giatri=='1'){
nhapmang2(a,n);	
}
else if(giatri=='2'){
xuatmang2(a,n);	
}
else if(giatri=='3'){	
chenphantucuoimang(a,n);
}
else if(giatri=='4'){
chenphantudaumang(a,n);	
}
else if(giatri=='5'){
chenphantuvaovitri(a,n);	
}	
}while(giatri!='x'); 		
}	
