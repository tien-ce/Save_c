#include<iostream>
#include<cstring>
using namespace std;
class animal{
	protected:
		string name;
		string giotinh;
		int tuoi;
	public:
virtual void speak()=0;
virtual void in_name(){
	cout<< this->name;
}

};
class cat : public animal{
	public:
	cat(){
	this->name="cat";	
	}	
	void speak(){
	cout<<"meo meo";
	}
};
class dog : public animal{
	public:
	dog(){
	name="dog";	
	}	
	void speak(){
		cout<<"gau gau";
	}
};
class run_time{
	animal* ani;
	public:
	void animals(animal * ani){
	this->ani=ani;
	}
	void run(){
	ani->in_name();	
	cout<<"\n";
	ani->speak();
	}
	
};
int main(){
	animal *a=new dog();
	run_time b;
	b.animals(a);
	b.run();
}

