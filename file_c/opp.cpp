#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    int size;
    T * p;	
public:
    Array(int size, T initValue);
    ~Array(){
    delete[] p;	
	}

    void setAt(int idx, const T & value);
    T getAt(int idx);
    
    void print();


};
template <typename T>
Array <T> ::Array(int size, T initValue){
	this->size=size;
	p=new T[size];
	for(int i=0;i<this->size;i++){
	p[i]=initValue;	
	}	
}
template <class T>
void Array<T>:: setAt(int idx,const T& value){
	if(idx<0|| idx >=this->size){
		throw -1;
	}
	else{
    this->p[idx]=value;		
	}
}
template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}
template <class T>
T Array<T>:: getAt(int idx){
	if (idx<0||idx>=size){
		throw -1;
	}
	else{
	return this->p[idx];	
	}
}
int main(){
	Array<int> * a7 = new Array<int>(10, 2);
    a7->print();
    try {
        a7->setAt(-1, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(10, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(2, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    delete a7;
}
