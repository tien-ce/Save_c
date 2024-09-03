#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next=nullptr;
	Node* prev=nullptr;
	
};
typedef Node* node;
class list{
private:
node firts=nullptr;
public:
node get_firts(){
	return this->firts;
}
node make_Node(int x);	
void addFirts(int x);
void addLast(int x);
void in();
void insert(int x,int pos);
int get_size();
void remove(int x);
};
node list::make_Node(int x){
	node p=new Node();
	p->data=x;
	p->next=nullptr;
	p->prev=nullptr;
	return p;
}
void list::addFirts(int x){
	node p=make_Node(x);
	if(firts==nullptr){
		firts=p;
		return;
	}
	else{	
	p->next=firts;
    firts->prev=p;
	firts=p;	
	}
}

void list::addLast(int x){
	node p=make_Node(x);
	if(firts==nullptr){
		firts=p;
	}
	else{
	while(firts->next!=nullptr){
	firts=firts->next;	
	}	
	firts->next=p;
	p->prev=firts;
	}
	while(firts->prev!=nullptr){
		firts=firts->prev;
	}	
}
void list::in(){
node p=firts;
while(p!=nullptr){
	cout<<p->data<<"\t";
	p=p->next;
}				
}
int list::get_size(){
	node p=firts;
	int dem=0;
	while(p!=nullptr){
	dem++;
	p=p->next;
	}
	return dem;
}
void list::insert(int x,int pos){
node a=make_Node(x);
	if(pos>get_size()-1||pos<0){
		cout<<"Loi vi tri\n";
		return;
	}
	else if(pos==get_size()-1){
	addLast(x);
	}
	else{
	node p=firts;	
	for(int i=0;i<pos;i++){
	p=p->next;	
	}
	p->next->prev=a;	
	a->next=p->next;
	p->next=a;
	a->prev=p;
	
	}
}
void list::remove(int x){
	node a=firts;
	while(a!=nullptr){
	if(a->data==x){		
	if(a->prev==nullptr){
	firts=firts->next;	
	firts->prev=nullptr;
	}
	else{
	a->prev->next=a->next;
	  if (a->next != nullptr) {
                    a->next->prev = a->prev;
                }

	}
	return;
	}
	a=a->next;
	}
	
}
int main(){
	Node* a = new Node();
	Node* b = a;
	Node* c = new Node();
	
	cout<<c << " , "<<(b->next);
}
