#include <iostream>
#include <string>

using namespace std;

int main()  {
    // TODO
    int dem=0;
    string s;	
    int t,dem1,k;
    int max=0;
    getline(cin,s);
    for(int i=0;i<s.length()-1;i++){
    t=1;
    dem=s.substr(i+t,s.length()-i-1).find(s[i])+1;
    cout<<"dem="<<dem<<"\n";
	dem1=s.length()-i;
    while(dem!=-1){ 	
    dem1=dem+t;	    
    	cout<<"dem1="<<dem1<<"\n";
    dem=s.substr(i+t,dem-1).find(s[i+t]);
	t++;
	}

	if(dem1>max){
	max=dem1;
	k=i;	
	}
	
	}
	cout<<s.substr(k,max);
}
