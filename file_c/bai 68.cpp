#include"stdio.h"
int main(){
char *ptr;

char ten[50];
int tuoi;
printf("nhap tuoi cua ban:");
scanf("%d",&tuoi);
getchar();
printf("ten cua ban : ");
fgets(ten, sizeof(ten),stdin);
printf("%s",ten);
printf("\n tuoi: %d",tuoi);	
ptr=ten;
printf("\n ki tu thu 2: %c",*(ptr+1));
}
