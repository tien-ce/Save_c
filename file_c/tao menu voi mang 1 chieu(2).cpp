#include"stdio.h"
#include"limits.h"

void nhapmang (int x[],int &n){
do {
printf("nhap gia tri n(0<n<=100) : n= ");
scanf("%d",&n);
for (int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);	
}
}
while (n<1||n>100);		
}
void xuatmang(int x[],int n){
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
void hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void daonguocmang(int x[], int n){
for(int i=0;i<n/2;i++){
hoandoi(x[i],x[n-i-1]);		
}
printf("\n gia tri mang dao nguoc:");	
}
void sapxeptangdan(int x[],int n){
for(int i=0;i<n-1;i++){
for (int j=i+1;j<n;j++){
if(x[i]>x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}
printf("\n sap xep tang dan:");	

}
void sapxepgiamdan(int x[],int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if (x[i]<x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}
printf("\n sap xep giam dan: ");	
}
int max(int x[],int n){
int max=x[0];
for (int i=1;i<n;i++){
if(x[i]>max){
max=x[i];	
}	
}
printf("\n gia tri lon nhat cua mang la %d:",max);	
}
int min(int x[], int n){
int min=x[0];
for(int i=1;i<n;i++){
if (x[i]<min){
min=x[i];
}	
}
printf("\n gia tri nho nhat cua mang la %d",min);	
}
void themgiatrivaocuoimang(int x[],int &n){
int giatri;
printf("\n them gia tri vao cuoi mang \n");
printf("\n nhapgiatrimuonthem:");
scanf("%d",&giatri);
x[n]=giatri;
n++;	
}
void themgiatridaumang(int x[],int &n){
n++;
int giatri;
printf("\n them gia tri vao dau mang \n ");
printf("nhap gia tri muon them: ");
scanf("%d",&giatri);
for(int i=n;i>0;i--){
x[i]=x[i-1];	
}
x[0]=giatri;	
}
void themgiatritaivitrik(int x[],int &n){
int k,giatri;
printf("\n chon vi tri muon them:k=");
scanf("%d",&k);
printf("chon gia tri muon them:");
scanf("%d",&giatri);
for(int i=n;i>=k;i--){
x[i]=x[i-1];
}
x[k]=giatri;
n++;	
}
void xoaphantuthuMtrongmang(int x[],int &n,int m){

for(int i=m;i<n-1;i++){
x[i]=x[i+1];	
}
n--; 		
}
void xoaphantucogiatriTtrongmang(int x[],int &n){
	
int t;
printf("\n nhap gia tri muon xoa: T=");
scanf("%d",&t);
for(int i=0;i<n;i++){
if(x[i]==t){
xoaphantuthuMtrongmang(x,n,i);
i--;
}	
}
}
void xoacacphantulonhonT(int x[],int &n){
int t;
printf("\n xoa cac phan tu x[i]>T:T=");
scanf("%d",&t);
for(int i=0;i<n;i++){
if(x[i]>t){
xoaphantuthuMtrongmang(x,n,i);
i--;
}	
}	
}
void xoacacphantunhohonT(int x[],int &n){
int t;
printf("\n xoa cac phan tu nho hon T: T=");
scanf("%d",&t);	
for(int i=0;i<n;i++){
if (x[i]<t){
xoaphantuthuMtrongmang(x,n,i);	
i--;
}	
}	
}
void timkiemphantu(int x[],int n){
int giatri;
int khongco=0;
printf("\n nhap gia tri can tim kiem:");
scanf("%d",&giatri);
for (int i=0;i<n;i++){
if(x[i]==giatri){	
khongco=1;	
}
}
if(khongco==0){
printf("gia tri khong xuat hien trong mang");
}
else{printf("gia tri co xuat hien trong mang");
}	
}

int main(){

int luachon;	
int a[100],n;
A:
nhapmang(a,n);
xuatmang(a,n);
A_1:
printf("\n  0: de thiet lap mang 1 chieu moi");
printf("\n  1: de thiet lap mag dao nguoc");
printf("\n  2: de xoa phan tu trong mang");
printf("\n  3: de xac dinh phan tu xuat hien trong mang");
printf("\n  4: de them phan tu vao mang");
printf("\n  5: de sap xep gia tri cua mang\n ");
scanf("\n ",&luachon);
if(luachon<0||luachon>5){
printf("vui long chi nhap tu 0-5");
goto A_1;
}
if (luachon==0)
goto A;
if (luachon==1){
int luachon1;
daonguocmang(a,n);
printf("\n 0: thoat");
printf("\n 1: tiep tuc dao nguoc mang");
scanf(" %d ",&luachon1);
if (luachon1==0)
goto A;
if (luachon1==1)
daonguocmang(a,n);	
}
if (luachon==2){
int luachon2;

B:

printf("0: exit");
printf("1: xoa phan tu tai vi tri M");
printf("2: xoa phan tu co gia tri T");
printf("3: xoa phan tu thoa man dieu kien");
scanf("\n",luachon2);
if (luachon2<0|| luachon2>3){
printf("vui long chi nhap tu 0-3");
goto B;	
}
if (luachon2==0)
goto A;
if(luachon2==1){
int vitri;	
printf("nhap vi tri muon xoa:");
scanf("%d",&vitri);	
xoaphantuthuMtrongmang(a,n,vitri);
goto B;	
}
else if(luachon2==2){
xoaphantucogiatriTtrongmang(a,n);	
goto B;
}
else if(luachon2==3){
int luachon2_1;		
C:
printf("0: exit");	
printf("1: xoa phan tu nho hon T");
printf("2: xoa phan tu lon hon T");	
scanf("%d",&luachon2_1);
if(luachon2_1<0||luachon2_1>2){
printf("vui long chi nhap tu 0-2");
goto C;	
}
if(luachon2_1==0)
goto B;
if (luachon2_1==1){
xoacacphantunhohonT(a,n);	
goto B;
}
else if(luachon2_1==2){
xoacacphantulonhonT(a,n);
goto B;
}
}
}
}

