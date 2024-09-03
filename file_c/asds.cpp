#include<iostream>
using namespace std;
void shallowCopy(int*& newArr, int*& arr) {
    // TODO
    newArr=new int[sizeof(arr)/sizeof(int)];
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
    newArr[i]=arr[i];
    }
}
int main(){
int* arr = new int[2];
arr[0] = 2; arr[1] = 3;
int* newArr = NULL;
shallowCopy(newArr, arr);
cout << newArr[0] << ' ' << newArr[1];
delete[] arr;
}
