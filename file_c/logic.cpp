#include<iostream>
using namespace std;

int pow(int a,int b){
if(b==0)
return 1;

if(b%2==1)
return a*(pow(a,b/2))*pow(a,b/2);
return pow(a,b/2)*pow(a,b/2);
}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	if(n==0)
	return 1;
	int res=1;
	while(n>0){
   if(n%2==1)
   res=res%m*x%m;
   x=x%m*x%m;
   n=n/2;
}
   return res;
}

int main(){
int a=pow(10000000%10000001,2);
cout<<a;
	///	cout<<modularExponentiation(10000000 ,2, 10000001);
}
