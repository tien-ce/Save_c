#ifndef book_h
#define book_h
#include <iostream>
#include <cstring>
using namespace std;

class book{
	private:
	string title;
	string author;
	bool available;
	book* next=nullptr;
	public:
	book * get_next(){
		return this->next;
	}
	void set_next(book * a){
	this->next=a;	
	}
	
	
	book(){		
	}
	book(string title, string author,bool available);
	
	string get_title(){
		return this->title;
	}
	
	string get_author(){
		return this->author;
	}	
};
typedef book* Book;

class library{
	private:
	int sosach=0;		
	Book bk=nullptr;
	public:
	void set_book(Book bk){
		this->bk=bk;
	}
    int get_soluong();
    void set_soluong(int x);
    void addbook();
	void printfbook();	
	void addbook(Book a);
};
Book make_list(Book a){
	Book p=new book();
	p=a;
	p->set_next(nullptr);
	return p;
}
#endif
