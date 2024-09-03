#include "stdio.h"
int max(int x,int y){
if(x>y){
	return x;
}
else{
return y;	
}	
}
bool pythalor(int x){
	if(x<100||x>999){
	return false;	
	}
	int a=x/100;
	
	int b=(x/10)%10;
    int	c=x%10;
  
	int max_1=max(a,max(b,c));
	int sum=a*a+b*b+c*c;
	if(2*max_1*max_1==sum){
		return true;
	}
	return false;
}
int main(){
	printf("%d",pythalor(345));
}
