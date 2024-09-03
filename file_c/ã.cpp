#include"iostream"
using namespace std;
class Base {
protected:
    
public:
	static int num; 
    void setNum(int n) {
         num = n;
    }
};
int Base::num=0;
class Derived : public Base {
public:
    void setNum(int n) {
     num+=n+ 1; // truy c?p bi?n num c?a l?p cha ? ph?m vi protected
    }
};

int main() {
    Base obj1;
    obj1.setNum(10);
    obj1.num=5;
    cout<<obj1.num;
    cout<<"\n";
    Derived obj2;
    obj2.setNum(20);
    cout << 	obj1.num << endl; // in ra 10
    cout << obj2.num << endl; // in ra 21 (do obj2 dã c?ng thêm 1 vào giá tr? c?a num)
    return 0;
}
