#include<iostream>

using namespace std;
class Queue {
private:
int arr[100];
int first=-1;
int last=-1;
public:
    Queue() {
        // Implement the Constructor
    
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
     return first>last;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
    if(first==-1){
        arr[++first]=data;
    last++;
    }
    else{
    last++;
    arr[last]=data;
    }

    }

    int dequeue() {
        // Implement the dequeue() function
        if(!isEmpty()){
		
        return arr[first++];
      
		return -1;
    }

}
    int front() {
        // Implement the front() function
    return arr[first];
    }
};
int main(){
	Queue q;
	q.enqueue(17);
	q.enqueue(23);
	q.enqueue(11);
	cout<<dequeue();
	cout<<dequeue();
	cout<<dequeue();
cout<<dequeue();
	return 0;
}
