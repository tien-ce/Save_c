#include "stdio.h"
#include "limits.h"
int main(){
int luachon;	
int a[100],n;
do{
nhapmang(a,n);
xuatmang(a,n);
printf("chon 0 de thiet lap mang 1 chieu moi");
printf("chon 1 de thiet lap mag dao nguoc");
printf("chon 2 de xoa phan tu trong mang");
printf("chon 3 de xac dinh phan tu xuat hien trong mang");
printf("chon 4 de them phan tu vao mang");
printf("chon 5 de sap xep gia tri cua mang");
scanf("\n",&luachon);
}
while(luachon!=0);
}
