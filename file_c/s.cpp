#include<vector>
#include<iostream>
using namespace std;
void test(int &n){
	if(n==10||n==-10)
	return ;
   	test(&n+1);
	test(&n-1);
	cout<<n;
}
int main(){
test(0);
	return 0;
}

