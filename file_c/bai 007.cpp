#include "stdio.h"
int main(){
	int x;
	printf("nhap_vao_gia_tri_x \n");
	scanf("%d",&x);

	float y;
	printf("\n nhap_gia_tri_cua_y \n");
	scanf("%f",&y);
    printf( "\n %d==%f la %d",x,y,x==y);
    printf("\n %d > %f la %d",x,y,x>y);
    printf("\n %d<= %f la %d",x,y,x<=y);
    printf("\n %d # %f la %d",x,y,x!=y);
	
	
}
