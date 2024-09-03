#include"stdio.h"
struct sinhvien{
char ten[50];
int tuoi;
int mssv;	
};	
int checksinhvien(struct sinhvien sv){
if(sv.tuoi<18||sv.tuoi>30){	
return 0;
}
if(sv.mssv<2000000||sv.mssv>3000000){
return 0;	
}

return 1;	
}
void nhapsinhvien(struct sinhvien &sv){
printf("\n nhap ten sinh vien:");
fgets(sv.ten,sizeof(sv.ten),stdin);
printf("\n nhap vao tuoi:");
scanf("%d",&sv.tuoi);
printf("\n nhap vao ma so sinh vien:");
scanf("%d",&sv.mssv);	
}
void insinhvien(struct sinhvien sv){
printf("%s-%d-%d",sv.ten,sv.tuoi,sv.mssv);	
}
int main(){
struct sinhvien sv;	
nhapsinhvien(sv);
insinhvien(sv);	
int kiemtra=checksinhvien(sv);
if(kiemtra==1){
printf("\n hop le");	
}
else{
printf("\n khong hop le");	
}
}
