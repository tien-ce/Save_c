#include "stdio.h"
int main(){
	int n;
	printf("nhap n=");
	scanf("%d",&n);
	switch(n){
		case(1):
			printf("/n chu nhat");
			break;
		case 2:
		    printf("thu 2");
		    break;
		case 3:
		    printf("thu 3");
		    break;
		case 4:
		    printf("thu tu");
		    break;	
        case 5:
		    printf("thu 5");
		    break;     
		case 6:
		    printf("thu 6");
		    break; 
		case 7:
		    printf("thu 7");
		    break;
		default:
		    printf("nhap n khong thoa man") ;		
		}
	}
