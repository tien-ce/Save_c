#include <iostream>
using namespace std;
void update(int **p){
	*p=*p+1;
}
int main(){
	int a=5;
	int a_1=6;
	int *b=&a;
	int **c=&b;
	cout<<c<<endl;
	cout<<*c<<endl;
	cout<<*b<<endl;
	cout<<"--------------\n";
	update(c);
	cout<<c<<endl;
	cout<<*c<<endl;
	cout<<*b<<endl;
}
