#include <iostream>
using namespace std;
template<typename T>
class Array2D {
private:
    int rows;
    int columns;
    T** arr;

public:
	void prin(){
		for(int i=0;i<this->rows;i++){
			for(int j=0;j<this->columns;j++){
				cout<<arr[i][j]<<endl;
			}
		}
}
	int get_rows(){
		return this->rows;
	}
	int get_columns(){
		return this->columns;
	}
   Array2D(int rows,int columns,T a){
   	this->rows=rows;
   	this->columns=columns;
   	for(int i=0;i<this->rows;i++){
   		for (int j=0;j<this->columns;j++){
   			arr[i][j]=a;
		   }
	   }
   }
    T* operator[](int index) {
        return arr[index];
    }

    Array2D* operator*(const Array2D<T> & a) {
        try {
            if (this->columns != a.columns) {
                throw -1;
            }
            Array2D<T>* result=new Array2D(this->rows, a.columns, 0);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < a.columns; j++) {
                    for (int k = 0; k < this->columns; k++) {
                        result->arr[i][j] += this->arr[i][k] * a.arr[k][j];
                    }
                }
            }
            return result;
        }
        catch (int x) {
            return nullptr;
        }
    }

    ~Array2D() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
	
    Array2D<int>* result =new Array2D<int>(1,2,3);
   
    result->prin();
    return 0;
}
