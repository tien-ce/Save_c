#include<iostream>
using namespace std;
int fun(int a){
	if(a==0)
	return a;
	return fun(a-1);
}
int main(){
	cout<<fun(5);
}
