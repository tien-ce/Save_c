#include "stdio.h"
int sochan(int x){
	return (x%2==0);


}

int cacsochiahetchoba(int x){
	return (x%3==0);

	
	
}




int main(){int n;
do{
	printf("nhap n(0<n<=100):n=");
	scanf("%d",&n);
}	while (n<0||n>100);
int a[100],i;
for (i=0;i<n;i++){
	printf("a[%d]=",i);
	scanf("%d",&a[i]);
}
printf("\n so chan :");
for(i=0;i<n;i++){
	if(sochan(a[i])) 
	printf("\n %d ",a[i]);


}
printf("\n  so chia het cho 3:");
for(i=0;i<n;i++){
    if (cacsochiahetchoba(a[i])){
    	printf(" \n %d",a[i]);
	}
}
	
}

	

