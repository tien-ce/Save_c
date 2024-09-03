#include<iostream>
#include <stdexcept> 
using namespace std;

class student{
	public:
	int id;
	string name;
	
	student(const int & _id,const string& _name) : id(_id), name(_name){}
};
template <class T>
class Node{
	public:
	T data;
	Node* next;
	Node(){}
	Node(const T& _data) : data(_data) , next(nullptr){}
};
template <class T>
class SLinkedList{
	private:
	int count;
	Node<T>* tail;
	Node<T>* head;
	public:
	SLinkedList() : tail(nullptr) , head(nullptr) , count(0){};
	int size(){return count;}
	void inserthead(const T&data)
	{
	Node<T> *cur=new Node<T> (data);
	if(head==nullptr)
	tail=cur;
	cur->next=head;
	head=cur;
	count++;
	}
	void insertAt(int index, const T&data) {
	if(index <0 || index> count-1)
	throw out_of_range ("ERROR Index");
	Node<T>*  cur= new Node<T>(data);
	if(index==count-1)
	{
	tail->next	= cur;
	tail= cur;
	}
	else {
	Node <T>* temp=head;
	for(int i=0;i<index;i++)
	temp=temp->next;
	temp->next=cur;	
	}
	count++;
	}
	T removeAt(int index);
	bool removeItem(const T& imtem);
	void clear();
	const T & truyxuat_at(int index){
		if(index<0||index>count-1)
		throw out_of_range("Invalid ");
		Node<T> * temp = head;
		for(int i=0;i<index;i++)
		temp=temp->next;
		return temp->data;
	}
};
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
  if (index < 0 || index > count-1) {
        throw out_of_range("Invalid index");
    }
   
    T clone;
    if (count == 1) {
        clone = head->data;
        delete head;
        head = tail = NULL;
        count = 0;
    }
    else if (index == 0) {
        Node<T> * temp = head;
        head = head->next;
        clone = temp->data;
        delete temp;
        --count;
    }
    else if (index == count -1) {
        Node <T>* p = head;
        for (int i = 0; i < count-2; ++i) {
            p = p->next;
        }
        clone = tail->data;
        delete tail;
        tail = p; tail->next = NULL;
        --count;
    }
    else {
        Node <T>* pre = NULL;
        Node <T>* cur = head;
        for (int i = 0; i < index; ++i) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        clone = cur->data;
        delete cur;
        --count;
    }
    return clone;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int foundIdx = indexOf(item);
    if (foundIdx == -1) {
        return false;
    }
    else {
        removeAt(foundIdx);
        return true;
    }
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (head) {
        Node <T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL; count = 0;
}
int main(){
	SLinkedList <student> control;
	control.inserthead(student(2213467,"Nguyen Van Tien"));
	student Quy(2213406,"Nguyen Phu Quy");
	control.insertAt(0,Quy);
	student temp= control.truyxuat_at(1);
	cout<<temp.id<<"name "<<temp.name<<endl;
	cout<<"size "<<control.size();
	return 0;
}

