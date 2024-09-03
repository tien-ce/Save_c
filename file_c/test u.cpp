#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
class max_heap{
	private:
	int arr[100];
	int size=0;
	
	public:
	void in(){
		for(int i=0;i<size;i++){
			cout<<arr[i];
		}
	}
	void insert(int data){
		cout<<data<<" ";
		size+=1;
		if(size==1)
		arr[0]=data;
		else
		{
		int index=size-1;
		arr[index]=data;
		while	(index>0){
		int temp=(index+1)/2-1;
		if(arr[index]>arr[temp])
		swap(arr[index],arr[temp]);
		else 
		break;	
		}
		
		}
	}
	int* get_ar(){
		return arr;
	}
	int get_size(){
		return this->size;
	}
};
int main(){
max_heap a;
a.insert(50);
a.insert(30);
a.insert(20);
a.in();
}
