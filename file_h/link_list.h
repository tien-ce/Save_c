#include<iostream>
#include <functional>
using namespace std;
template <class T>
// TODO List
class List{
	public:
	List(){}
	~ List(){}
	virtual int getsize()=0;
    virtual bool isEmpty()=0;
    virtual bool isfull()=0;
    virtual void clear()=0;
    virtual void reverse()=0;
    virtual List<T>* merger(List<T>* pl)=0;
    virtual List<T>* split(int index)=0;
    virtual List<T>* clone(int fIdx=0, int tIdx=-1)=0;
    
    
    virtual void insert(const T &val,int index)=0;
    virtual void insert( T **val,int index)=0;
    virtual void remove(int index)=0;
    virtual T* find(const T &val)=0;
    virtual int findIdx(const T&val)=0;
    virtual const T& get(int index) =0;
    virtual void set(const T& val,int index)=0;
    virtual T& operator[](int index)=0;
    // virtual void traverse(function(T&))=0; // ham op co kieu tra ve la void nhan vao 1 doi tuong T&; 
};


