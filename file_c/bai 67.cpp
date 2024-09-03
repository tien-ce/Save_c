#include"stdio.h"
#include"stdlib.h"
int main(){
/* int *ptr;
// CAP PHAT BO NHO DONG
ptr=(int *)calloc(4 ,sizeof(int) );
*(ptr+4)=1;
if(ptr==NULL){
printf("khong the cap phat ");
return 0;	
}
else{
realloc(ptr , 3);	
for(int i=0;i<5;i++){
printf("%d \t ",*(ptr+i));
}
}
free(ptr);*/
char c[50];
printf("nhap vao ten cua ban:");
/* scanf("%s",c);
*/
fgets(c,sizeof(c),stdin);
puts(c);

}
