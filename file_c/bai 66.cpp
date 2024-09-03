# include "stdio.h"
# include "stdlib.h"
int main(){
int n;
printf("nhap so luong phan tu: ");
scanf("%d",&n);
int *ptr=(int*)malloc(n*sizeof(int));
if(ptr==NULL){
printf("\n error: Khong cap phat duoc bo nho");
return 0;
}
else{
for(int i=0;i<n;i++){
scanf("%d",ptr+i);	
}	
}
for(int i=0;i<n;i++){
printf("%d \t ",*(ptr+i));
}
free(ptr);	
}
