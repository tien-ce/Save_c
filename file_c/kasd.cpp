#include <iostream>
using namespace std;
int *test(){
	int *a;
	*a=5;
	return a;
}
int main(){
int *a;
int b=5;

a=&b;
a=new int[2];
*(a+1)=2;
cout<<*a;
}
