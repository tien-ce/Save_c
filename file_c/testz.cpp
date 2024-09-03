#include<iostream>
using namespace std;
class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next){
        	this->val=val;
            this->next=next;
		}
		void clear(){
			if(this!=nullptr&&this->next!=nullptr){
				delete this->next;
			}
		}
};
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    if(l1==nullptr&&l0==nullptr)
    return nullptr;
    LLNode* temp0=l0;
    LLNode* temp1=l1;
    int ans=0,c=0;
   
    while(temp0!=nullptr&&temp1!=nullptr){
        ans=temp1->val+temp0->val+c;
        if(ans>=10){
            ans-=10;
            c=1;
        }
        else{
            c=0;
        }
    
    temp1->val=ans;
     if(temp1->next==nullptr&&temp0->next!=nullptr){
        temp1->next=temp0->next;
        temp1=temp1->next;
        temp0->next=nullptr;
        break;
    }
    if(temp1->next==nullptr&&temp0->next==nullptr&&c==1){
    	temp1->next=new LLNode(1,nullptr);
    	return l1;
	}
    else{
    temp1=temp1->next;
    temp0=temp0->next;
    }
    }
    while(temp1!=nullptr){
        ans=temp1->val+c;
         if(ans>=10){
            ans-=10;
            c=1;
        }
        else{
            c=0;
        }
        temp1->val=ans;
    if(temp1->next==nullptr&&c==1){
        temp1->next=new LLNode(1,nullptr);
        return l1;
    }
    temp1=temp1->next;
    }
    LLNode*temp=l1;

    return temp;
}
int main(){
LLNode* head1=new LLNode(2,nullptr);
head1->next=new LLNode(9,nullptr);
LLNode* head2=new LLNode(0,nullptr);
head2->next=new LLNode(5,nullptr);
LLNode* newhead = addLinkedList(head1, head2);
while(newhead!=nullptr){
	cout<<newhead->val<<",";
	newhead=newhead->next;
}
head1->clear();
head2->clear();
newhead->clear();
}
