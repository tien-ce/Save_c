#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
};

int main(){
	Node* a=new Node();
	Node* b =new Node();
	a->next = b;
	cout<<b;
	a->next = nullptr;
    cout<<b;
	return 0;
}
