#include<iostream>
using namespace std;
	int fun(int x){

		if(x>10)
		return x;
		cout<<"--------------------------------------"<<endl;
		for(int i=0;i<3;i++){
			cout<<"x="<<x<<",i="<<i<<endl;
		fun(x+2);	
		}
	}
	int main(){
		cout<<fun(7);
	return 0;	
	}
