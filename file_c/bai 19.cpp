#include "stdio.h"
#include "math.h"
int main(){

float xa,xb,xc,ya,yb,yc;
float AB,BC,CA;
printf("\n nhap toa do cac diem");
printf("\n A");
scanf(" %f %f",&xa,&ya);
printf("\n B");
scanf("%f %f",&xb,&yb);
printf("\n C");
scanf("%f %f",&xc,&yc);
printf("do dai cac canh");
AB=sqrt(pow(xb-xa,2)+pow(ya-yb,2));
BC=sqrt(pow(xc-xb,2)+pow(yc-yb,2));
CA=sqrt(pow(xa-xc,2)+pow(ya-yc,2));
printf("\n AB=%f",AB);
printf("\n BC=%f",BC);
printf("\n CA=%f",CA);
if(	AB+BC>CA && BC+CA>AB && AB+CA>BC){printf(" \n 3 canh tao thanh tam giac");
if(AB==BC || BC==CA|| AB==CA)
{printf(" \n day la tam gia can");}
float p,chuvi,dientich;
chuvi=(AB+BC+CA);
printf(" \n chuvi=%.2f",chuvi);
p=chuvi/2;
printf("\n p=%.2f",p);
dientich=p*(p-AB)*(p-BC)*(p-CA);
printf("\n dien tich=%.2f",dientich);
}else{printf("\n 3 canh khong tao thanh tam giac");
}

}
