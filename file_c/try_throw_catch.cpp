#include<iostream>
using namespace std;
int main(){
	try{
		int tuoi_con=2;
		int tuoi_me =15;
	if(tuoi_con<0){
		throw "ERROR";
	}
	if(tuoi_me<18){
	throw "ERROR";	
	}
	if(tuoi_con>tuoi_me){
		throw "ERROR";	
    }
    
    else{
    cout<<"Tuoi con:"<<tuoi_con<<endl;
	cout<<"Tuoi me:"<<tuoi_me<<endl;		
	} 
	
	}
	catch(const char  *x){
		cout<<x;
	}
	
}
