#include "stdio.h"
int main(){
 int a,b;
 float x;
 printf("giai phuong trinh ax+b=0");

 printf("\n a=");
 scanf(" %d",&a);
 printf("\n b=");
 scanf("%d",&b);
 if (a==0 && b==0){printf("vo so nghiem");
 } else if (a==0 && b!=0){printf("vo nghiem");
 }else {printf("x=%.2f",(float)a/-b);
 }
 
 
	
	
	}
