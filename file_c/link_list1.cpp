#include<iostream>
using namespace std;	
class Node{
 public:
int data;
Node* next=nullptr;
Node* last;

Node(int data){	
this->data=data;
this->next=nullptr;
this->last=this;
}


};
typedef Node* node;
void insert_head(node& l,int a){

	node p=new Node(a);
	
	if(l==nullptr){		
	l=p;
	l->last=p;
	return ;
	}
p->next=l;
l->last->next=p;
l=p;
}
void insert_last(node& l,int a){
	node p=new Node(a);
	if(l==nullptr){
	l=p;
	l->last=p;
	return;	
	}
	l->last->next=p;
	l->last=l->last->next;
	l->last->next=l;

}
void in_circle(node& l){

	node temp=l;
	if(temp!=nullptr){	
	do{
	cout<<temp->data<<" ";
	temp=temp->next;		

	}
	while(temp!=l);
}
}
int main(){
	node a=new Node(10);
	insert_head(a,0);
	insert_last(a,20);
	insert_last(a,30);
	insert_head(a,-10);
	in_circle(a);
	return 0;
}
