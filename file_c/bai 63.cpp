#include"stdio.h"
int main(){
// DIA CHI BIEN
int var;	
printf("nhap var=");
scanf("%d",&var);
printf("\n gia tri cua var=%d",var);
printf("\n dia chi cua bien var trong bo nho la: %p",&var);
// PC LUU TRU DIA CHI CUA C
int* pc,c;
c=5;
pc=&c;
// lAY GIA TRI CUA C QUA DIA CHI
*pc=2;
printf("\n c=%d",*pc);
printf("\n c=%d",c);
printf("\n dia chi cua c la %p",pc);
}
