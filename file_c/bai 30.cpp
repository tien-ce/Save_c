#include "stdio.h"
int songaycuathang(int thang , int nam){
	
	switch(thang){
	case 1:	
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	return 31;
	break;
	case 4:
	case 6:
	case 9:
	case 11:
	return 30;
	break;
	case 2:
	if(nam%400==0||(nam %4==0 && nam %100!=0)){
	return 29;
	}else{
	return 28;
	}
		
	}
}
int ngayhomtruoc(int ngay){
	ngay=ngay-1;
	
	return ngay;
}

int songaytrongnam(int ngay,int thang , int nam){
	
int songay;
int i;
for(i=1;i<thang;i++){
	songay+=songaycuathang(i,nam);
	songay+=ngay;
}

 return songay;
}
int ngayke(int ngay){

ngay=ngay+1;
return ngay;}
int main(){
	 int ngay,thang,nam;
	do{
		printf("nhap ngay thang nam:");
		scanf("%d%d%d",&ngay,&thang,&nam);
	} while(ngay<1||ngay>31||thang<1||thang>12||nam<0);
	 printf("cau a");
	int kt;
	kt=songaycuathang(thang,nam);
	printf("\n so ngay cua thang do la %d :",kt);
	
    
    printf("\n cau b");
    int k;
    k=songaytrongnam(ngay,thang,nam);
    printf("\n songaytrongnam=%d",k);
    
    printf("\n cau c");
    int h =ngayhomtruoc(ngay);
    printf("\n ngay hom truoc la:ngay %dthang %d nam %d",h,thang,nam);
    printf("\n cau d");
    int a=ngayke(ngay);
	printf("\n ngay ke do la : ngay %d thang %d nam %d",a,thang,nam);
  }
  
    
    




