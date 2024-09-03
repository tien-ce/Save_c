#include "link_list.h"
// TODO arraylist
template<class T>
class arrlist : public List <T>{
	protected:
	T* pD;
	int size,cap;
	public:
	arrlist(int size) : cap(size) {	pD=new T[cap];	}
	~arrlist (){delete []pD;}
	int getsize() {return size;}
	bool isEmpty(){return !size;}
    bool isfull(){return size==cap;}
    virtual void clear()=0;
    virtual void reverse()=0;
    virtual List<T>* merger(List<T>* pl)=0;
    virtual List<T>* split(int index)=0;
    virtual List<T>* clone(int fIdx=0, int tIdx=-1)=0;
    
    
    void insert(const T &val,int index){
    	for(int i=index;i<size;i++) pD[i+1]=pD[i];
    	pD[index] = val;
	}
    virtual void insert( T **val,int index)=0;
    virtual void remove(int index)=0;
    virtual T* find(const T &val)=0;
    virtual int findIdx(const T&val)=0;
    virtual const T& get(int index) =0;
    virtual void set(const T& val,int index)=0;
    virtual T& operator[](int index)=0;
	 
};
int main(){
	
}
