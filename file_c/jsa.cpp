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
xuatmang(x,n);	
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
xuatmang(x,n);
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
xuatmang(x,n);
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
xuatmang(x,n);	
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
xuatmang(x,n);	
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
xuatmang(x,n);
}
void xoaphantuthuMtrongmang(int x[],int &n,int m){

for(int i=m;i<n-1;i++){
x[i]=x[i+1];	
}
n--; 
xuatmang(x,n);		
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
xuatmang(x,n);	
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
xuatmang(x,n);
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
A: 
int luachon;	
int a[100],n;
printf("TAO MANG \n ");
nhapmang(a,n);
xuatmang(a,n);
B:
printf("\n\n\n\n");

printf("GIA TRI CUA MANG HIEN TAI \n");
xuatmang(a,n);
printf("\n  0: thiet lap mang 1 chieu moi");
printf("\n  1: thiet lap mang dao nguoc");
printf("\n  2: xoa phan tu trong mang");
printf("\n  3: xac dinh phan tu xuat hien trong mang");
printf("\n  4: them phan tu vao mang");
printf("\n  5: sap xep gia tri cua mang ");
printf("\n  6: tim max , min cua mang\n");
scanf("\n %d",&luachon);
if (luachon<0||luachon>6){
printf("\n vui long nhap gia tri trong khoang 0-6");
goto B;	
}
if(luachon==0) goto A;
if (luachon==1){
daonguocmang(a,n);
goto B;	
}
if (luachon==2){
C:
int luachon2;
printf("\n 0: exit");
printf("\n 1: xoa phan tu tai vi tri M");
printf("\n 2: xoa phan tu co gia tri T");
printf("\n 3: xoa phan tu thoa man dieu kien\n");
scanf("\n%d",&luachon2);
if(luachon2<0||luachon2>3){
printf("\n vui long nhap gia tri trong khoang 0-3");	
goto C;
}
if(luachon2==0){
goto B;	
}
if(luachon2==1){
int vitri;	
printf("\n nhap vi tri muon xoa:");
scanf("%d",&vitri);	
xoaphantuthuMtrongmang(a,n,vitri);	
}
else if(luachon2==2){
xoaphantucogiatriTtrongmang(a,n);	
}
else if(luachon2==3){
int luachon2_1;		
D:
printf("\n 0: exit");	
printf("\n 1: xoa phan tu nho hon T");
printf("\n 2: xoa phan tu lon hon T\n");	
scanf("\n %d",&luachon2_1);
if(luachon2_1<0||luachon2_1>2){
printf("vui long nhap gia tri trong khoang 0-2");
goto D;	
}
if(luachon2_1==0){
goto C;	
}
if (luachon2_1==1){
xoacacphantunhohonT(a,n);
goto B;	
}
else if(luachon2_1==2){
xoacacphantulonhonT(a,n);
}	
}
goto B;
}
else if(luachon==3){
timkiemphantu(a,n);	
goto B;
}
else if (luachon==4){
int luachon4;
E:
printf("\n 0:exit");
printf("\n 1:them phan tu vao dau mang");
printf("\n 2:them phan tu vao cuoi mang");
printf("\n 3:them phan tu vao vi tri bat ki\n");
scanf("\n %d",&luachon4);
if(luachon4<0||luachon4>3){
printf("vui long nhap gia tri trong khoang 0-3");
goto E; 	
}
if(luachon4==0){
goto B;	
}
if(luachon4==1){
themgiatridaumang(a,n);
goto B;	
}
else if(luachon4==2){
themgiatrivaocuoimang(a,n);
goto B;	
}
else if(luachon4==3){
themgiatritaivitrik(a,n);	

goto B;
}
	
}
else if(luachon==5){
F:
int luachon5;
printf("\n 0: exit");
printf("\n 1: sap xep tang dan");
printf("\n 2: sap xep giam dan\n");	
scanf("\n %d",&luachon5);
if(luachon5<0||luachon5>2){
printf("vui long nhap gia tri trong khoang 0-2");
goto F;	
}	
if (luachon5==0)
goto B;
if (luachon5==1){
sapxeptangdan(a,n);	
goto B;
}
else if(luachon5==2){
sapxepgiamdan(a,n);	
goto B;
}
}
else if(luachon==6){
int luachon6;
H:
printf("\n 0: exit");
printf("\n 1: tim max");
printf("\n 2; tim min\n");
scanf("\n %d",&luachon6);
if (luachon6<0||luachon6>2){
printf("vui long nhap gia tri trong khoang 0-2");	
goto H;
}
if(luachon6==0)	
goto B;
if(luachon6==1){
max(a,n);
goto B;	
}
else if(luachon6==2){
min(a,n);
goto B;	
}
}

}
