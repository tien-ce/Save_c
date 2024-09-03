#include <fstream>
#include <sstream>
#include "string.h"
#include <iostream>
using namespace std;
int main(){
	FILE *f;
	char hiepsi[100];
	char masukien[100];
	char filecandung[100];
	f=fopen("testcase_input","r");
	fflush(stdin);
	fgets(hiepsi,100,f);
	fgets(masukien,100,f);
	fgets(filecandung,100,f);
	cout<<hiepsi<<endl;
	cout<<masukien<<endl;
	cout<<filecandung<<endl;
}
