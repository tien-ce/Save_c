#include "stdio.h"
int main(){
	float r;
	printf("nhap_gia_tri_r: r=");
	scanf("%f",&r);
	float d=2*r;
	float p=2*3.14*r;
	float s=3.14*r*r;
	printf("\n gia_tri_cua_d: d=%f *2=%f",r,d);
	printf("\n gia_tri_cua_p: p=%f *2*3.14=%f",r,p);
	printf("\n gia_tri_cua_s: s=%f*%f*3.14=%f",r,r,s);

}
