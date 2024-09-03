#include <iostream>
using namespace std;
int pow(int x,int y){
	if(y==0)
	return 1;
	return x*pow(x,y-1);
}
long int decimalToBinary_1(int decimal_number) {
    if (decimal_number == 0)
        return 0;

    int remainder = decimal_number % 2;
    long int binary_number = remainder + 10 * decimalToBinary_1(decimal_number / 2);
    return binary_number;
}

long int decimalToBinary(int x,int dem){

long int n=0;
if(x==0)
return 0;
return n+=(x%2)*pow(10,dem)+decimalToBinary((x-x%2)/2,dem+1);
}
long int decimalToBinary(int decimal_number)
{
int dem=0;
decimalToBinary(decimal_number,dem);
}

int main(){
cout<<decimalToBinary(203)-decimalToBinary_1(203);
}
