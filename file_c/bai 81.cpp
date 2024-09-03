#include"stdio.h"
#include "math.h"
struct phanso{
int tuso;
int mauso;	
};
void nhapphanso(struct phanso *ps){
printf("nhap tu so:");
scanf("%d",&ps->tuso);
do{
printf("nhap mau so:");
scanf("%d",&ps->mauso);	
}
while(ps->mauso==0);
for(int i=abs(ps->mauso);i>0;i--){
if(ps->tuso%i==0&&ps->mauso%i==0){
ps->tuso/=i;
ps->mauso/=i;
break;	
}	
}
}
void printfphanso(struct phanso ps){
if(ps.mauso<0){
ps.tuso*=-1;
ps.mauso*=-1;	
}	
if (ps.mauso==1){
printf("%d",ps.tuso);	
}
else{
printf("%d/%d",ps.tuso,ps.mauso);	
}
}
int main(){
phanso ps;
nhapphanso(&ps);
printfphanso(ps);
	
}
