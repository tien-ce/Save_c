#include "iostream"
#include"math.h"
using namespace std;
struct node{
	int data;
	node *next;
			
};
 typedef node* Node;
Node makenode(int x){
 	Node a=new node();
 	a->data=x;
 	a->next=NULL;
 	return a;
 }
 // kiemtra
 bool kiemtra(node* a){
 	return a==NULL;
 }
 int size(Node a){
 	int dem=0;
 while (a!=NULL){
 	a=a->next;
 	++dem;
 }
 return dem;
 }
void themdau(Node &a,int x){
	Node temp=makenode(x);
	if(a==NULL){
	a=NULL;	
	}
	else{
		temp->next=a;
		a=temp;
	}
}
/// them cuoi
	void themcuoi(Node &a,int x){
		Node temp=makenode(x);
		if(a==NULL){
		a=temp;	
		}
		else{
	  Node p=a;	
		while(p->next!=NULL){
		p=p->next;	
		}
		p->next=temp;
		}
	}
	void themvitri_k(Node &a,int k,int x){
		Node temp=makenode(x);
		Node p=a;
		for(int i=0;i<k;i++){
		p=p->next;	
		if(p==NULL) return;
		}
		if(p==NULL){
		themcuoi(a,x);
		}
		temp->next=p->next;
		p->next=temp;
	}
int main(){
node* head = NULL;
Node a;
a=makenode(2);
themcuoi(a,3);
themdau(a,2);
cout<<size(a);
return 0;
}
