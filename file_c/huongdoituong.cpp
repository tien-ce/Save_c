#include"iostream"
#include"time.h"
#include"stdlib.h"

using namespace std;
int x=5;
int main(){
int *p;
int n;
printf("nhap n:");
cin>>n;
srand((unsigned ) time(NULL));
p=new int[n];	
for(int i=0;i<n;i++){
cout<<rand()<<"\n";	
*(p+i)=rand()%99+1;	
}
for(int i=0;i<n;i++){
cout<<*(p+i)<<"\t";	
}
delete(p); 
}
