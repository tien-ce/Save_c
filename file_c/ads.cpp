#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib> // thêm thu vi?n c?n thi?t
using namespace std;

void xoaxuongdong(char a[]){
    int l=strlen(a);
    if(a[l-1]=='\n'){
        a[l-1]='\0';
    }
}

void chuyendoi(char a[], int &n){
    n=0;
    int l=strlen(a);
    for(int i=0;i<l;i++){
        n=n*10+(a[i]-'0');
    }
}

void chuyendoi1(char a[],int b[]){
    char *p=strtok(a," ");
    int i=0;
    while(p!=NULL){
        b[i++]=atoi(p);
        p=strtok(NULL," ");
    }
}

class ArmyKnights {
private :
    char sohiepsi_1[100];
public:
    static char thongtinhiepsi_1[100];
    static int thongtinhiepsi[100];
    static int sohiepsi;
    ArmyKnights(const string & file_armyknights);
    ArmyKnights();
    ArmyKnights *p;
};

ArmyKnights::ArmyKnights() {}

ArmyKnights::ArmyKnights(const string & file_armyknights) {
    char const *tenfile = file_armyknights.c_str();
    FILE *f;
    f = fopen(tenfile, "r");
    if (f == NULL) {
        cout << "Error: Cannot open file " << file_armyknights << endl;
        return;
    }
    fgets(sohiepsi_1, 100, f);
    xoaxuongdong(sohiepsi_1);
    chuyendoi(sohiepsi_1, sohiepsi);
    p = new ArmyKnights[sohiepsi];
    for (int i = 0; i < sohiepsi; i++) {
        fgets(p[i].thongtinhiepsi_1, 100, f);
        chuyendoi1(p[i].thongtinhiepsi_1, p[i].thongtinhiepsi);
    }
    fclose(f);
}

char ArmyKnights::thongtinhiepsi_1[100];
int ArmyKnights::thongtinhiepsi[100];
int ArmyKnights::sohiepsi;

struct thongtinhiepsi {
    int id;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
};

struct Nodehs {
    thongtinhiepsi hs;
    Nodehs* next;
};

typedef Nodehs* nodehs;

nodehs themhiepsi(thongtinhiepsi hs, int i) {
    hs.id = i + 1;
    nodehs a = new Nodehs;
    a->hs = hs;
    a->next = NULL;
    return a;
}

int main() {
    string file_armyknights = "army_knight.txt";
    ArmyKnights f(file_armyknights);
  
nodehs a=NULL;
for(int i=0;i<f.sohiepsi;i++){
a=themhiepsi(f.p[i].thongtinhiepsi,i);	
}

    return 0;
}

