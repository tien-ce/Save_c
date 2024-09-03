#include<iostream>
#include<cstring>
#include <sstream>
using namespace std;
int max(int x,int y){
if(x>y){
	return x;
}
else{
return y;	
}	
}
bool pythalor(int x){
	a=x/100;
	b=(x/10)%10;
	c=x/10;
	int max=max(a,max(b,c));
	int sum=a*a+b*b+c*c;
	if(2*max*max==sum){
		return true;
	}
	return false;
}
bool kiemtrasonguyento(int x){
if(x<=1){
	return false;
}
else if(x==2){
	return true;
}
else{
for(int i=2;i<x;i++){
	if(x%i==0){
		return false;
	}
	
}
return true;	
}	
}
void xoaxuongdong(char x[]){
if(x[strlen(x)-1]=='\n'){
x[strlen(x)-1]= '\0';	
}	
}


class BaseOpponent {
protected:
    int masukien;
    int basedamage;
    int sukienthu;
    int level0;
public:
    BaseOpponent() {
        level0 = (sukienthu + masukien) % 10 + 1;
    }
};

class MadBear : public BaseOpponent {
public:
    MadBear() {
    masukien = 1;
    basedamage = 10;
    }
};

class Bandit : public BaseOpponent {
public:
    Bandit() {
        masukien = 2;
        basedamage = 15;
    }
};

class LordLupin : public BaseOpponent {
public:
    LordLupin() {
        masukien = 3;
        basedamage = 45;
    }
};

class Elf : public BaseOpponent {
public:
    Elf() {
        masukien = 4;
        basedamage = 75;
    }
};

class Troll : public BaseOpponent {
public:
    Troll() {
        masukien = 5;
        basedamage = 95;
    }
};

class Tornbery : public BaseOpponent {
public:
    Tornbery() {
        masukien = 6;
    }
};

class QueenOfCards : public BaseOpponent {
public:
    QueenOfCards() {
        masukien = 7;
    }
};

class NinaDeRings : public BaseOpponent {
public:
    NinaDeRings() {
        masukien = 8;
    }
};

class DurianGarden : public BaseOpponent {
public:
    DurianGarden() {
        masukien = 9;
    }
};

class OmegaWeapon : public BaseOpponent {
public:
    OmegaWeapon() {
        masukien = 10;
        int solangap ;
    }
};

class Hades : public BaseOpponent {
public:
    Hades() {
        masukien = 11;
        int sokhien ;
        int solangap ;
    }
};
char events_1[100],so_event1[100];
class Events {
private: char ten_event;
int so_event;	
int *event;
public:
	Events(const string &file_events);
    int count() const;
    int get(int i) const;
};
Events::Events(const string &file_events){	
char const *ten_event=file_events.c_str();
FILE *f;
f=fopen(ten_event,"r");
fflush(stdin);fgets(so_event1,100,f);
xoaxuongdong(so_event1);
chuyendoi(so_event1,so_event);
event=new int[so_event];
fflush(stdin);
fgets(events_1,so_event,f);
xoaxuongdong(events_1);
chuyendoi1(events_1,event);
}
Events::count() const{
return so_event;	
}
Events::get(int i) const{
return event[i];
delete []event;
}
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
//////////////////////////////////////////////////////////////////////
class BaseItem {
public:
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
	BaseBag * bag;
    KnightType knightType;
public:
	int phoenixdownI;
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

////
class	PaladinKnight:public BaseKnight{
public:
	PaladinKnight(){	
	knightType=PALADIN;
	}
};
class LancelotKnight:public BaseKnight{
	public:
	Lancelotknight(){
		knightType=LANCELOT;
	}	
};
class DragonKnight : public BaseKnight{
   DragonKnight(){
   	knightType=DRAGON;
   }
};
class NormalKnight:public BaseKnight{
	NormalKnight(){
		knightType=NORMAL;
	}
};

/////

BaseKnight* BaseKnight :: create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
BaseKnight *f=new BaseKnight();
f->id=id;
f->maxhp=maxhp;
f->level=level;
f->gil=gil;
f->antidote=antidote;
f->phoenixdownI=phoenixdownI;
return f;
}

/////////

class ArmyKnights {
private :
	char sohiepsi_1[100];
public:
	static char thongtinhiepsi_1[100];
	static int thongtinhiepsi[100];
	static int sohiepsi;
    ArmyKnights (const string & file_armyknights);
    ArmyKnights();
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
    ArmyKnights *p;
};
ArmyKnights::ArmyKnights() {}
char ArmyKnights::thongtinhiepsi_1[100];
int ArmyKnights::thongtinhiepsi[100];
int ArmyKnights::sohiepsi;
ArmyKnights::ArmyKnights(const string & file_armyknights){
	char const *tenfile=file_armyknights.c_str();
	FILE *f;
	f=fopen(tenfile,"r");
	fgets(sohiepsi_1,100,f);
    xoaxuongdong(sohiepsi_1);
	chuyendoi(sohiepsi_1,sohiepsi);	
	p=new ArmyKnights[sohiepsi];
	for(int i=0;i<sohiepsi;i++){
	fgets(p[i].thongtinhiepsi_1,100,f);
	chuyendoi1(p[i].thongtinhiepsi_1,p[i].thongtinhiepsi);	
	}
}
ArmyKnights::fight(BaseOpponent *opponent){
	Events f;
	BaseOpponent *p=opponent;
	for(int i=0;i<f.count(),i++){
	if(f.get(i)==1){
	
	}
	
	}
}
	ArmyKnights::adventure(Events *event){
		
	}
/*
ArmyKnights::fight(BaseOpponent *opponent){
	
}
*/
ArmyKnights f;
/////////////

/*

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};


class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};
/////////////////////////////////////////////////////////////
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}


void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
*/
struct thongtinhiepsi{
    int id;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    KnightType knightType;
};

struct Nodehs{
    thongtinhiepsi hs;
    Nodehs* next;
};

Nodehs* themhiepsi(ArmyKnights& f, int i){
    thongtinhiepsi hs;
    hs.id = i + 1;
    hs.maxhp = f.p[i].thongtinhiepsi[0];
    hs.level = f.p[i].thongtinhiepsi[1];
    hs.gil = f.p[i].thongtinhiepsi[2];
    hs.antidote = f.p[i].thongtinhiepsi[3];
    hs.phoenixdownI = f.p[i].thongtinhiepsi[4];
    if(maxhp==888){
    hs.knightType=LANCELOT;	
	}
	else if(kiemtrasonguyento(maxhp)==1){
	hs.knightType=PALADIN;	
	}
	else if(100<=maxhp &&999>=maxhp &&pythalor(maxhp)==1){
	hs.knightType=DRAGON;
	// rong lor	
	}
	else{
	hs.knightType=NORMAL;
	// thuong dan	
	}
    Nodehs* a = new Nodehs;
    a->hs = hs;
    a->next = NULL;
    return a;
}

int main(){
    string file_armyknights = "army_knight.txt";
    ArmyKnights f(file_armyknights);
  
}
