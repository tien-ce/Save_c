#include <iostream>
#include<cstring>
using namespace std;
class Student{
	private:
	string name;
	int age;
    float poin;
    public:
    Student(string name,int age,float poin){
    	this->name=name;
    	this->age=age;
    	this->poin=poin;
	}
	string get_name(){
		return this->name;
	}    
	int get_age(){
		return this->age;
	}
	float get_poin(){
		return this->poin;
	}
};
typedef Student* stu; 
class Node{
	private:
	stu st;
	Node* next=nullptr;
	public:
	Node* get_next(){
		return this->next;
	}
void set_next(Node* next){
	this->next=next;
}
stu get_student(){
	return this->st;
}
void set_student(stu st){
	this->st=st;
}
};
typedef Node* node;
class Class{
	private:
	node firts=nullptr;
	public:

	node make_Node(stu st);
	void add_student(stu st);
	void remove_student(stu st);
	bool search_student(stu st);
	void printf();
	
};
typedef Class* cl;
node Class::make_Node(stu st){
node p=new Node();
p->set_student(st);
p->set_next(nullptr);
return p;
}
void Class::add_student(stu st){	
node p=make_Node(st);
if(firts==nullptr){
	firts=p;
}
else{
	node m=firts;
	while(m->get_next()!=nullptr){
		m=m->get_next();
	}
	m->set_next(p);

}
}
void Class::printf(){
	node p=firts;
	int i=1;
	while(p!=nullptr){
		cout<<"------------------------------Sinh vien thu "<<i<<"------------------------------\n";
		cout<<"Name: ";
		cout<<p->get_student()->get_name()<<endl;
		cout<<"Age: ";
		cout<<p->get_student()->get_age()<<endl;
		cout<<"Point: ";
		cout<<p->get_student()->get_poin()<<endl;
			p=p->get_next();
			i++;
	}

}
void Class::remove_student(stu st){
     node p=firts;
     node temp=nullptr;
     while(p!=nullptr){
     if(p->get_student()->get_name()==st->get_name()){
     if(temp==nullptr){
     	firts=firts->get_next();
	 return;
	 }	
	 temp->set_next(p->get_next());
	  return;
	  }
	temp=p;  
    p=p->get_next();
	 }
	 cout<<"Khong the tim thay sinh vien can xoa";
}
bool Class::search_student(stu st){
	node p=firts;
	while(p!=nullptr){
	if(p->get_student()->get_name()==st->get_name()){
	cout<<"Sinh vien co trong danh sach lien ket\n";
	return true;	
	}
	p=p->get_next();	
	}
	cout<<"Sinh vien khong co trong danh sach lien ket\n";
return false;
}
int main(){
	stu a=new Student("Nguyen Van Tien",18,10);
    cl m=new Class();
    m->add_student(a);
    stu b=new Student("Dang Toan Quoc",18,10);
    stu c =new Student("dsnadnas",5,6);
    m->add_student(c);
	m->add_student(b);
	m->search_student(c);
    m->printf();
}

