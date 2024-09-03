#include <iostream>
using namespace std;

// YOU ARE NOT ALLOWED TO MODIFY INITIAL CODE, ONLY CODE IN TODO
class Node {
    int val;
    Node* next;   
   public:
    Node() : val(0), next(nullptr) {}
    Node(int x) {    // TO DO
    this->val=x;
    this->next=nullptr;
    }
  
    Node(int x, Node* next) {
        // TO DO
    this->val=x;
    this->next=next;
    }
    int getVal() {
        // TO DO
    return this->val;
	}
    Node* getNext() {
        // TO DO
        return this->next;
    }
    void setVal(int x) {
        // TO DO
        this->val=x;
    }
    void setNext(Node* next) {
        // TO DO
        this->next=next;
    }
};
class ListNode {
   public:
    Node* swap(Node* head) {
        // TO DO
        Node *p=head;
		while(p->getNext()!=nullptr){		
		int temp=p->getVal();				
		     p->setVal(p->getNext()->getVal());	
		     p->getNext()->setVal(temp);
             p=p->getNext()->getNext();
			 }
			 return head;		
    }
   void them(int x,Node * &a){
   Node *p=new Node(x);
   Node *q=a;
   while(q->getNext()!=nullptr){
   	q=q->getNext();
   }
   q->setNext(p);
   }
    Node* createList(int arr[], int n) {
    // TO DO
    Node *p=new Node(arr[0]);
    for(int i=1;i<n;i++){
    them(arr[i],p);
	}
	return p;
    }
    void printList(Node* head) {
        // TO DO
        while(head!=nullptr){
        cout<<head->getVal();
        cout<<" ";
		head=head->getNext();	
		}
    }
};
typedef Node* node;
int main(){
    node c=new Node(2);
    ListNode x;
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>arr[i];	
	}   
	 c=x.createList(arr,n);
    node b=x.swap(c);
	x.printList(b);
}
