#include<iostream>
#include"windows.h"
using namespace std;

int WINAPI WinMain(HINSTANCE a,HINSTANCE b,LPSTR c,int d) {
	HWND hwnd=CreateWindow("lop window","helloword",SW_SHOWNORMAL,0,0,800,600,nullptr,nullptr,nullptr,nullptr);
	ShowWindow(hwnd,SW_SHOW);
	return 0;
}
