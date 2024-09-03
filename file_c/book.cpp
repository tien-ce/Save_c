#include"book.h"
#include"math.h"
#include <cstring>
using namespace std;
book::book(string title,string author,bool available)
{
	this->title=title;
	this->author=author;
	this->available=available;
	this->next=nullptr;
}	

int library::get_soluong(){
	return this->sosach;
}
void library::set_soluong(int x){
	this->sosach=x;
}

void library::addbook(){
	string title,author;
cout<<"nhap sach muon them: ";
getline(cin,title);
cout<<endl;
cout<<"nhap ten tac gia: ";
getline(cin,author);
Book a=new book(title,author,1);
if (this->bk==nullptr){
this->bk=make_list(a);	
sosach++;
}
else{
	Book new_bk=bk;
	while(new_bk->get_next()!=nullptr){
		new_bk=new_bk->get_next();
	}
	new_bk->set_next(a);
	bk=new_bk;
sosach++;
}
}

void library::addbook(Book b){

if(this->bk==nullptr){
this->bk=make_list(b);
	sosach++;
}
else{
Book c=this->bk;
while(c->get_next()!=nullptr){
c=c->get_next();	
}
this->bk->set_next(c);	
sosach++;
}

}
void library::printfbook(){
Book new_bk=bk;
int i=1;
if(new_bk==nullptr){
	cout<<"Thu vien trong vui long them sach "<<endl;
}
else{
while(new_bk!=nullptr){
cout<<"------------------ cuon sach thu "<<i<<"------------------"<<endl;
cout<<"title: "<<new_bk->get_title()<<endl;
cout<<"author: "<<new_bk->get_author()<<endl;
new_bk=new_bk->get_next();
i++;
}

}
}
int main(){
	library a;
	Book b=new book("To Kill a Mockingbird","Harper Lee",1);
	
    a.addbook(b);
    a.addbook();
    a.printfbook();
    return 0;
}
