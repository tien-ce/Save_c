#include <iostream>

using namespace std;
class student{
private:
static int mssv;
static string hoten;
static float diemtoan;
static float diemli;
static float diemhoa;
public:
void get_mssv(){
cout<<"nhap ma so sinh vien:";
cin>>mssv;	

}
void get_hoten(){
cout << "Nhap ho ten: ";
cin.ignore();
getline(cin, hoten);

}
void get_diemtoan(){
	cout<<"nhap diem toan";
	cin>>diemtoan;
}
void get_diemli(){
cout<<"nhap diem li:";
cin>>diemli;
}
void get_diemhoa(){
cout<<"nhap diem hoa:";
cin>>diemhoa;
}
	
};
int student::mssv = 0;
string student::hoten = "";
float student::diemtoan = 0;
float student::diemli = 0;
float student::diemhoa = 0;
int main(){
	int x;
	cout<<"nhap so luong sinh vien:";
	cin>> x;
student *p=new student[x];
for(int i=0;i<x;i++){
cout<<"sinh vien thu "<<i+1<<":";;
p[i].get_mssv();
cout<<"\n";
p[i].get_hoten();
cout<<"\n";
p[i].get_diemtoan();
cout<<"\n";
p[i].get_diemli();
p[i].get_diemhoa();
}
}
