#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct {
    char name[20];
    double price;
    int number;
}item;
//
typedef struct {
	char ma[20];
    int quantity;
    item foods[5];
    char soban[10];
    double totalPay;
}bill;
//
typedef struct {
    int number;
    item Menu[20];
}menu;
//
typedef struct {
	int numberBill;
	bill a[10];
}billDay;

////
void line42(){
	printf("\n                  |");
	for(int i=0;i<43;i++){
		if(i==21) printf("|");
		printf("_");
	}
	printf("|");
}
void line46(){
	printf("\n       *       |");
	for(int i=0;i<46;i++)
	if(i==20||i==31) printf("|");
	else
	{
		printf("_");
	} 
	printf("|     *");
}
void chuanHoa(char c[]) {
	    c[0] = toupper(c[0]);
	for(int i=1; i < strlen(c) ; i++){
		c[i] = tolower(c[i]);
	}
}
void process(char a[20]) {
	char b[20][20],c[20]="\0";
	int n=0;
	char *token = strtok(a," ");
	while(token != NULL) {
		strcpy(b[n],token);
		++n;
		token = strtok(NULL, " ");
	}
	for(int i=0;i<n;i++){
		chuanHoa(b[i]);
		strcat(c,b[i]);
		if(i!=n-1) strcat(c," ");
	}
	strcpy(a,c);
}
void showMenu(menu a){
//	char x[1] ="%";
     int n=a.number;
     printf("\n       ================================MENU================================\n                   ");
     printf("\n        Quy Khach se duoc giam gia 25%% cho don hang tu 2 trieu tro len !\n\n                   ");
     for(int i=0;i<44;i++){
     	printf("_");
     }
     for(int i=0;i<n;i++){
        printf("\n                  |%2d%15s    |%20.0lf  |",i+1,a.Menu[i].name,a.Menu[i].price);
        line42();
     }
     printf("\n       ====================================================================  \n                   ");
}
void foodMenu(menu *a){
       a->number = 10;
       strcpy(a->Menu[0].name,"Sup");
       a->Menu[0].price=200000;
       strcpy(a->Menu[1].name,"Com Ga");
       a->Menu[1].price=100000;
       strcpy(a->Menu[2].name,"Bun Bo Hue");
       a->Menu[2].price=150000;
       strcpy(a->Menu[3].name,"Ga Chien");
       a->Menu[3].price=300000;
       strcpy(a->Menu[4].name,"Cha Gio");
       a->Menu[4].price=300000;
       strcpy(a->Menu[5].name,"Muc Nuong");
       a->Menu[5].price=250000;
       strcpy(a->Menu[6].name,"Cua Hoang De");
       a->Menu[6].price=700000;
       strcpy(a->Menu[7].name,"Tom Alatka");
       a->Menu[7].price=1000000;
       strcpy(a->Menu[8].name,"Bo Bit Tet");
       a->Menu[8].price=400000;
       strcpy(a->Menu[9].name,"Banh Loc");
       a->Menu[9].price=150000;
}
void addItem(menu *a,char name[],double price){
    int n = a->number;
    a->number+=1;
    strcpy(a->Menu[n].name,name);
    a->Menu[n].price = price;
}
void delItem(menu *a,int k){
    int n =a->number;
      for(int i=k-1;i<n-1;i++){
           strcpy(a->Menu[i].name,a->Menu[i+1].name);
           a->Menu[i].price=a->Menu[i+1].price;
      }
      a->number-=1;
}
void delItem2(menu *a,char name[]){
	int n = a->number;
	for(int i =0 ;i <n;i++){
