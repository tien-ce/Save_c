#include<iostream>
template<class T>
class smartpointer{
	private:
	T * poniter;
	public:
	smartpointer(T* otherpointer) : poniter( otherpointer){
		if(poniter==NULL) 
		std::cout<< "WARNING : NOT DATA IN POINTER";
		else
		{
			std::cout<< "data "<< *poniter<<std::endl;
			delete []poniter;
		}
	}
};
template <class T> 
class my_vector{
	private:
	T* address;
	int m_size;
	public:
	my_vector(int size,T vaule) : m_size(size){
		std::cout<< "copy construction\n";
		address = new T[m_size];
		for(int i=0;i<m_size;i++){
		address[i]=vaule;	
		}
	}
	my_vector(){
	std::cout<< "copy construction\n";
	}
	my_vector<T> (const my_vector <T>&orther) : m_size(orther.m_size){
	std::cout<<"copy construction\n";
	address=new T [m_size];
		for(int i=0;i<m_size;i++){
			address[i] = orther.address[i];
		}
	}
	void print(){
	for(int i=0;i<m_size;i++)
	std::cout<<address[i];
	std::cout<<"\n";
	}
	~ my_vector(){
    delete [] address;	
	}
};
class point2D{
private:
float x,y;
public:
point2D (float _x,float _y) : x(_x), y(_y){}
};
 class point3D{
	private:
	point2D a;
	float z;
	public:
	point3D(float _x,float _y,float _z) : a(point2D(_x,_y)) ,z(_z){}
};

/*
class point3D{
	private:
	point2D a;
	float z;
	public:
	point3D(float _x,float _y, float _z){
		a.x=_x;
		a.y=_y;
		z=_z;
	}
};
*/
int main() {
   my_vector <int> a(6,5);
   my_vector <int> b=a;
   return 0;
}
