#include"stdio.h"
void myfun(int n){
printf("%d",n);
if(n<5){
++n;	
myfun(n);
}
printf("%d",n);
}
int main(){
myfun(0);
}
