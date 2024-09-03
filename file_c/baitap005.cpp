#include "stdio.h"
int main(){
	int x;
	float y;
	printf("nhap_vao_gia_tri_x=");
	scanf("%d",&x);
	printf("\n nhap_vao_gia_tri_y=");
	scanf("%f",&y);
	float tong=x+y;
	printf("tong=%d+%.2f=%.2f",x,y,tong);
	float hieu=x-y;
	printf("\n hieu=%d-%.2f=%.2f",x,y,hieu);
    float tich=x*y;
	printf("\n tich=%d*%.2f=%.2f",x,y,tich);
	float thuong=x/y;
	printf ("\n thuong=%d/%.2f=%.2f",x,y,thuong);	
	int t =x % (int)y;
	printf("\n t= %d chia_lay_du %.2f=%.d",x,y,t);
	
	y--;
	printf("\n y--=%.2f",y);
	
	}
