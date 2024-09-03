#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next=nullptr;
};
typedef Node* node;

class Stack{
	private:
	node top;
	int size;
	public:
	Stack(int size){
	this->size=size;
	this->top=nullptr;	
	}
	bool isEmpty(){
	if(top==nullptr)
	return true;
	return false;	
	}
	node get_top(){
		return this->top;
	}
	bool isFull(){
	int dem=0;
	node p=top;
	while(p!=nullptr){
		dem++;
		p=p->next;
	}

	return dem==this->size;	
	}
	
	int get_size(){
		return this->size;
	}
	node make_Node(int x){
		node p=new Node();
		p->data=x;
		p->next=nullptr;
		return p;
	}
	int get_Num(){
		node p=top;
		int dem=0;
		while(p!=nullptr){
		p=p->next;
		dem++;	
		}
		return dem;
	}
	void push(int x){
	node p=make_Node(x);
	if(!isFull()){
    if(isEmpty()){
    this->top=p;	
	}
	else{
	p->next=top;
	top=p;
	}
	
	}
	else{
	cout<<"SO LUONG DAT GIOI HAN\n";	
	}
}
	void pop();
	void in(){
		node p=this->top;
		while(p!=nullptr){
			cout<<p->data<<"\t";
			p=p->next;
		}
	}
	void delete_mid();
};
typedef Stack* stack;
void Stack::pop(){
	node p=top;

	if(!isEmpty()){
	if(top->next==nullptr){
	top=nullptr;	
	}
	else{
		
	top=top->next;	
	}
	
	}
    
	}
 void Stack::delete_mid(){
 	int count=0;
 		node temp=nullptr;
	node p=this->top;
	int a=this->get_Num()/2;
	while(top!=nullptr){
	  
	if(count==a){
	pop();
  
	temp->next=top;
	top=p;
	return;
	}
	else{
		count++;
		
		temp=top;
		top=top->next;
}
}		
}
int main(){
   stack a=new Stack(10);
   a->push(1);
   a->push(2);
   a->push(3);
   a->push(4);
  a->push(5);
  a->push(6);
  a->push(7);
  a->push(8);
  a->push(9);
  a->push(10);
  a->push(11);
a->delete_mid();
   a->in();
	return 0;
}
