#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
class Stack{
private:
	int top=-1;
	int *arr;
	int size;
	public:
	Stack(int size){
	this->size=size;	
	arr=new int[size];
	top=-1;
	}
	void push(int x){
	if(this->size-top>1){
	
	top++;
	arr[top]=x;
	}
	else{
	cout<<"FULL\n";	
	}
}
	void pop(){
		if(this->top>=0){
		top--;
	
		}
		else{
		cout<<"NOT DATA\n";	
		}
		
	}
	
	int peek(){
	if(top>=0 && top<size)
    return arr[top];
    else
	cout<<"Stack is Emptly\n";
	return -1;
	}
	
	bool isEmpty(){
	if(top==-1)
	return true;
	return false;	
	}
};

class Two_Stack{
	private:
	int top_1;
	int top_2;
	int *arr;
	int size;
	public:
	public:
	Two_Stack(int size){
		this->size=size;
		top_2 =size;
		top_1=-1;
		arr=new int [size];	
	}	
	void push_1(int vaule){
		if(top_2-top_1>1){
		top_1++;	
		arr[top_1]=vaule;	
		}
		else{
		cout<<"FULL DATA"<<endl;
			
		}
		
	}
	void push_2(int vaule){
		if(top_2-top_1>1){
	 top_2--;
	arr[top_2]=vaule; 		
	}
	else{
		cout<<"FULL DATA"<<endl;
	}
	}
	int pop_1(){
	if(top_1>=0){
	int temp=arr[top_1];	
	top_1--;	
	return temp;
	}
	else{
	cout<<"Stack is Empty"<<endl;	
	return -1;
	}
				
	}
	int pop_2(){
	if(top_2<size){
	int temp=arr[top_2];
	top_2++;	
	return temp;
	}	
	else{
	cout<<"Stack is Empty";	
	return -1;
	}
	}
	
};
class N_stack{
	private:
	int n;
	int *arr;
	int *top;
	int *next;
	int freeSpot;
	public:
	N_stack(int n,int size){
	arr=new int [size];
	arr[0]=0;
		this->top=new int[n];
		for(int i=0;i<n;i++){
			top[i]=-1;
		}
	next=new int [size];
	freeSpot=0;
    for(int i=0;i<size-1;i++){	
    next[i]=i+1;
	}
next[size-1]=-1;

	}

	void push(int x,int m){
	int index=freeSpot;
	freeSpot=next[index];
    
	arr[index]=x;
    
	next[index]=top[m-1];
	top[m-1]=index;
	cout<<arr[0];
	}
	
};
int main(){
int *arr;	
N_stack a(3,5);

a.push(10,1);
return 0;	
}
