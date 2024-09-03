#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
int my_strlen(char s[]);
int max(int x,int y);
bool pythalor(int x);
bool kiemtrasonguyento(int x);
int chuyendoi1(char x1[],int x[]);
void chuyendoi(char x[], int &x1);
void xoaxuongdong(char x[]);
class Events {
private:
int sosukien;
int *sk;	
public:
	Events ( const string & file_events );
	~Events();
    int count () const ;	
    int get(int i) const;
};
enum ItemType {ANTIDOTE, I, II, III, IV};
class BaseKnight;
class BaseBag;
	class BaseItem {
	protected:
	ItemType itemtype;	
	public:
	virtual ~BaseItem();
	void set_itemtyep(ItemType itemtype);
	BaseItem* next=NULL;
    ItemType get_itemtype();
	virtual bool canUse(BaseKnight* knight) {	
	}
	virtual void use(BaseKnight* knight){
	}
	};
typedef BaseItem* baseitem;

class BaseBag {
public:
	baseitem firts=NULL;
	int cont_items=0;
    BaseKnight *knight;
    virtual ~BaseBag();
    
    virtual bool insertFirst(BaseItem *item);

    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const ;
};
typedef BaseBag* basebag;


enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int maxhp;
    int level;
    int gil;
    KnightType knightType;
    basebag bag;
public:
	
	int antidote;
    void set_bag(BaseBag *bag);
    int hp;
  bool trungdoc;
	int phoenixdownI;
	int get_maxhp();
    int get_level();
	int get_gil();
	int get_antidote();
	int get_phoenixdownI();
    KnightType get_type();
	void set_hp(int newhp);
	void set_level(int newlevel);
	void set_gil(int newgil);
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};
typedef BaseKnight* baseknight;

class BaseOpponent{
	private:
	int basedamage;
	int masukien;
	int level0;
	public:	
	int gilthem;
	virtual void set_masukien(int masukien);
	int get_masukien();
	virtual void set_basedamage(int basedamage);
	int get_basedamage();
	virtual void set_level0(int i);
	int get_level0();
	 virtual ~BaseOpponent();
};

	class ArmyKnights {
private:
	int id;
	int maxhp;
	int level;
	int gil;
	int phoenixdownI;
	int antidote;
public:
	ArmyKnights(){
    }
	static int khien,soitoc,giao,guom;
    int sohiepsi;
	int thongtinhiepsi[10];
	ArmyKnights **hiepsi;
	BaseKnight **p;
	BaseBag **b;
    int get_id();
	int get_maxhp();
		int get_level();
		int get_phoenixdownI();
		int  get_gil();
		int  get_antidote();
    ArmyKnights (const string & file_armyknights);
    virtual ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure (Events * events);
    void printInfo() const ;
    void printResult(bool win) const;
    int  count() const;
 BaseKnight*  lastKnight() const ;
    bool  hasPaladinShield() const;
    bool  hasLancelotSpear() const;
    bool  hasGuinevereHair() const;
    bool hasExcaliburSword() const;
};
class KnightAdventure {
private:
    ArmyKnights* armyKnights;
    Events* events;
public:
    KnightAdventure();
    void loadArmyKnights(const string &file_army);
    void loadEvents(const string &file_events);
    ~KnightAdventure();
    void run();	
};
#include "knight2.h"
int my_strlen(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    dest=new char[20];
    src=new char[20];
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int max(int x,int y){
if(x>y){
	return x;
}
else{
return y;	
}	
}
bool pythalor(int x){
	if(x<100){
	return false;	
	}
	int a=x/100;
	int b=(x/10)%10;
    int	c=x/10;
	int max_1=max(a,max(b,c));
	int sum=a*a+b*b+c*c;
	if(2*max_1*max_1==sum){
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
int chuyendoi1(char x1[],int x[]){
int dem;
int n=0;
for(int i=0;i<my_strlen(x1);i++){
dem=0;	
if (x1[i]!=' '&&x1[i]!=','){	
do{
dem++;	
}	
while(x1[i+dem]!=' ' &&  x1[i+dem]!='\0'&&x1[i+dem]!=',');    	
int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
if(x1[i]!='-'){
if(dem==1){
x[n]=0;	
x[n]+=x1[i]-48;	
}
else{	
x[n]=0;	
for(int j=0;j<dem;j++){
x[n]+=(x1[j+i]-48)*luythua[dem-j-1];		
}
}
}
else{
int v=1;	
x[n]=0;
while(x1[i+v]!=' '&&x1[v+i]!='\0'&&x1[v+i]!=','){
x[n]=x[n]*10+(x1[v+i]-48);
v++;	
}
x[n]=-x[n];
}
i+=dem-1;
n++;
}
}
return n;
}
void chuyendoi(char x[], int &x1) {
    int dem = 0, dau = 1;
    if (x[0] == '-') {
        dau = -1;
        x++;
    }
    for (int i = 0; i < my_strlen(x); i++) {
        if (x[i] != ' ' && x[i] != ',') {
            do {
                dem++;	
            } while (x[i + dem] != ' ' && x[i + dem] != '\0' && x[i + dem] != ',');    			
            int luythua[20];
            luythua[0] = 1;
            for (int j = 1; j < 10; j++) {
                luythua[j] = 10 * luythua[j - 1];	
            }
            x1 = (x[i] - 48) * luythua[dem - 1];	
            for (int j = 1; j < dem; j++) {
                x1 += ((x[i + j]) - 48) * luythua[dem - j - 1];	
            }
            x1 *= dau; 
            i += dem;	
        } 
		else {
            continue;
        }
    }
}
void xoaxuongdong(char x[]){
    int i = 0;
    while (x[i] != '\0' && x[i] != '\n' && x[i] != '\r') {
    i++;
    }
    x[i] = '\0';
}

Events :: Events ( const string & file_events ){
	char sosukien[100];
	char sukien[100];
	FILE *f;
	f=fopen(file_events.c_str(),"r");
	if(f==nullptr){
	cout<<"Error";
	exit(1);
	}
	fgets(sosukien,100,f);
	xoaxuongdong(sosukien);
	chuyendoi(sosukien,this->sosukien);
	fgets(sukien,100,f);
	xoaxuongdong(sukien);
	sk=new int[this->sosukien];
	chuyendoi1(sukien,sk);
	fclose(f);
	}
int Events::count() const {
	return this->sosukien;
}
int Events::get(int i) const {
	return this->sk[i];
}
Events::~Events() {
    delete[] sk;
}

	void BaseItem:: set_itemtyep(ItemType itemtype){
		this->itemtype=itemtype;
	}
	
	
	BaseItem::~BaseItem() {}
	ItemType BaseItem:: get_itemtype(){
	return itemtype;	
	}



/////////////////////////////////////////


/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag:: insertFirst(BaseItem *item){return false;};
 BaseItem * BaseBag:: get(ItemType itemType){
    baseitem hientai=firts;
	baseitem truoc=nullptr;
	while(hientai!=nullptr){
	ItemType type = hientai->get_itemtype(); 	
	if(hientai->get_itemtype()==itemType){
	cont_items--;	
	if(truoc==nullptr){
	firts=hientai->next;	
	}
	else{
	truoc->next=hientai->next;	
	}
	return hientai;
	}
	truoc=hientai;
	hientai=hientai->next;	
	}
	return nullptr;	
	}
	
 string BaseBag:: toString() const {
    stringstream ss;
    ss << "Bag[count=" << cont_items << ";";
    baseitem hientai = firts;
    baseitem truoc = nullptr;
    while (hientai != nullptr) {
        ItemType type = hientai->get_itemtype();
        switch (type) {
            case I:
                ss << "PhoenixI";
                break;
            case II:
                ss << "PhoenixII";
                break;
            case III:
                ss << "PhoenixIII";
                break;
            case IV:
                ss << "PhoenixIV";
                break;
            case ANTIDOTE:
                ss << "Antidote";
                break;
            default:
                break;
        }
        truoc = hientai;
        hientai = hientai->next;
        if (hientai != nullptr) {
            ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

BaseBag::~BaseBag() {
    baseitem current = firts;
    while (current != nullptr) {
        baseitem next = current->next;
        delete current;
        current = next;
    }
}

/* * * END implementation of class BaseBag * * */










/* * * BEGIN implementation of class BaseKnight * * */



void BaseKnight:: set_bag(BaseBag *bag){
    	this->bag=bag;
	}
int BaseKnight:: get_maxhp(){
	return maxhp;	
	}
int BaseKnight:: get_gil(){
	return gil;	
	}
int BaseKnight:: get_antidote(){
	return antidote;
	}
	int BaseKnight:: get_phoenixdownI(){
	return phoenixdownI;	
	}
    KnightType BaseKnight:: get_type(){
	return knightType;	
	}
	void BaseKnight:: set_hp(int newhp){
	this->hp=newhp;	
	}
	void BaseKnight:: set_level(int newlevel){
	this->level=newlevel;	
	}
	void BaseKnight:: set_gil(int newgil){
	this->gil=newgil;	
	}
 BaseKnight * BaseKnight:: create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight *p =new BaseKnight();
    p->id=id;
	p->maxhp=maxhp;
    p->level=level;
	p->gil=gil;
	p->antidote=antidote;
    p->phoenixdownI=phoenixdownI;
    p->hp=maxhp;
    BaseKnight temp;
    if (maxhp == 888) {
        temp.knightType = LANCELOT;
    }
    else if (kiemtrasonguyento(maxhp) == 1) {
        temp.knightType = PALADIN;
    }
    else if (pythalor(maxhp) == 1) {
        temp.knightType = DRAGON;
    }
    else {
        temp.knightType = NORMAL;
    }
    p->knightType = temp.knightType;
    return p;
}



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

/* * * END implementation of class BaseKnight * * */


class PhoenixDownI : public BaseItem {	
			public:
			    PhoenixDownI() {
			        itemtype = I;
			    }
			    bool canUse(BaseKnight* knight) {
			        if (knight->hp <= 0)
			        return true;
			        return false;
			    }
			    void use(BaseKnight* knight) {
			        knight->hp = knight->get_maxhp();
			    }
			};
		
		class PhoenixDownII : public BaseItem {
		public:
		    PhoenixDownII() {
		        itemtype = II;
		    }
		    bool canUse(BaseKnight* knight) {	
		        if (knight->hp < knight->get_maxhp() / 4)
		            return true;
		        return false;
		    }
		    void use(BaseKnight* knight) {
		        knight->hp = knight->get_maxhp();
		    }
		};
		
		class PhoenixDownIII : public BaseItem {
		public:
		    PhoenixDownIII() {
		        itemtype = III;
		    }
		    bool canUse(BaseKnight* knight) {
		        if (knight->hp < knight->get_maxhp() / 3)
		            return true;
		        return false;
		    }
		    void use(BaseKnight* knight) {
		        if (knight->hp <= 0) {
		            knight->hp = knight->get_maxhp() / 3;
		        }
		        else {
		            knight->hp += knight->get_maxhp() / 4;
		        }
		    }
		};
		
		class PhoenixDownIV : public BaseItem {
		public:
		    PhoenixDownIV() {
		        itemtype = IV;
		    }
		    bool canUse(BaseKnight* knight) {
		        if (knight->hp < knight->get_maxhp() / 2)
		            return true;
		        return false;
		    }
		    void use(BaseKnight* knight) {
		        if (knight->hp <= 0) {
		            knight->hp = knight->get_maxhp() / 2;
		        }
		        else {
		            knight->hp += knight->get_maxhp() / 5;
		        }
		    }
		};
		
		class Antidote : public BaseItem {
		public:
		    Antidote() {
		        itemtype = ANTIDOTE;
		    }
		    bool canUse(BaseKnight* knight) {
		        if (knight->trungdoc == true) {
		            return true;
		        }
		        return false;
		    }
		    void use(BaseKnight* knight) {
		        knight->trungdoc = false;
		    }
		};


class dragonbag:public BaseBag{
public:	
 virtual bool insertFirst(BaseItem *item){
	if(item->get_itemtype()==ANTIDOTE)
	return false;
	if(cont_items==14)
	return false;
	baseitem new_item;
	switch(item->get_itemtype()){
	case I:
	new_item=new PhoenixDownI();
	break;
	case II:
	new_item=new PhoenixDownII();
	break;
	case III:
	new_item=new PhoenixDownIII();
	break;
	case IV:
	new_item=new PhoenixDownIV();
	break;	
	}
	new_item->next=firts;
	firts=new_item;
	cont_items++;
	return true;
}	
};
class normalbag:public BaseBag{
 virtual bool insertFirst(BaseItem *item){if(cont_items==19){
	return false;	
	}
	baseitem new_item;
	switch(item->get_itemtype()){
	case I:
	new_item=new PhoenixDownI();
	break;
	case II:
	new_item=new PhoenixDownII();
	break;
	case III:
	new_item=new PhoenixDownIII();
	break;
	case IV:
	new_item=new PhoenixDownIV();
	break;
	case ANTIDOTE:
	new_item=new Antidote();
	break;	
	}
	new_item->next=firts;
	firts=new_item;
	cont_items++;
	return true;
}
};
class lancelotbag:public BaseBag{
  virtual bool insertFirst(BaseItem *item){if(cont_items==16)
   return false;
   baseitem new_item;
	switch(item->get_itemtype()){
	case I:
	new_item=new PhoenixDownI();
	break;
	case II:
	new_item=new PhoenixDownII();
	break;
	case III:
	new_item=new PhoenixDownIII();
	break;
	case IV:
	new_item=new PhoenixDownIV();
	break;
	case ANTIDOTE:
	new_item=new Antidote();
	break;	
	}
	new_item->next=firts;
	firts=new_item;
	cont_items++;
   return true;
   }
};
class paladinbag:public BaseBag{
 virtual bool insertFirst(BaseItem *item){
 baseitem new_item;
	switch(item->get_itemtype()){
	case I:
	new_item=new PhoenixDownI();
	break;
	case II:
	new_item=new PhoenixDownII();
	break;
	case III:
	new_item=new PhoenixDownIII();
	break;
	case IV:
	new_item=new PhoenixDownIV();
	break;
	case ANTIDOTE:
	new_item=new Antidote();
	break;	
	}
	new_item->next=firts;
	firts=new_item;
	cont_items++;
    return true;
}
};


BaseOpponent::~BaseOpponent() {}

void BaseOpponent:: set_masukien(int masukien){	
	this->masukien=masukien;
	}
int BaseOpponent:: get_masukien(){
		return masukien;
	}
void BaseOpponent:: set_basedamage(int basedamage){
	this->basedamage=basedamage;
	}
	int BaseOpponent:: get_basedamage(){
	return basedamage;	
	}
void BaseOpponent:: set_level0(int i){
    level0= (i + masukien)%10 + 1;
 }
	int BaseOpponent:: get_level0(){
	return level0;
	}


class MadBear : public BaseOpponent {
    public:
        MadBear() {
          set_masukien(1);
		    set_basedamage(10);
		 gilthem=100;
        }
};

class Bandit : public BaseOpponent {
    public:
        Bandit() {
        	 set_masukien(2);
            set_basedamage(15);
            gilthem=150;
        }
};

class LordLupin : public BaseOpponent {
    public:
        LordLupin() {
        	 set_masukien(3);
            set_basedamage(45);
            gilthem=450;
        }
};

class Elf : public BaseOpponent {
    public:
        Elf() {
             set_masukien(4);
            set_basedamage(75);
            gilthem=750;
        }
};

class Troll : public BaseOpponent {
    public:
    Troll() {
    set_masukien(5);
    set_basedamage(95);
    gilthem=800;
    }
};
class Tornbery:public BaseOpponent{
	public:
	Tornbery(){
	 set_masukien(6);
	}
};

//// NU HOANG XINH DEP
class QueenOfCards:public BaseOpponent{
	public:
	QueenOfCards(){
		 set_masukien(7);
	}
	
};
class NinaDeRings :public BaseOpponent{
	public:
	NinaDeRings(){
	 set_masukien(8);	
	}
};
class DurianGarden : public BaseOpponent{
	public:
	DurianGarden(){
	 set_masukien(9);
	}
};
class OmegaWeapon : public BaseOpponent{

	public:
	OmegaWeapon(){
	 set_masukien(10);
	}	
};
class Hades :public BaseOpponent{
	public:
	Hades(){	
	set_masukien(11);
}
};





/* * * BEGIN implementation of class ArmyKnights * * */

    int ArmyKnights::khien=0;
	int ArmyKnights::soitoc=0;
	int ArmyKnights::giao=0;
	int ArmyKnights::guom=0;
	
   int ArmyKnights:: get_id(){
   return id;	
   }
	int  ArmyKnights:: get_maxhp(){
		return this->maxhp;	
		}
		int  ArmyKnights:: get_level(){
		return level;	
		} 
		int  ArmyKnights:: get_phoenixdownI(){
		return this->phoenixdownI;	
		}
		int  ArmyKnights::  get_gil(){
		return this->gil;	
		}
		int  ArmyKnights::  get_antidote(){
		return this->antidote;	
		}
	 
	int ArmyKnights:: count() const{
	return sohiepsi;
	}
 BaseKnight* ArmyKnights:: lastKnight() const {
    if (sohiepsi == 0) {
        return nullptr;
    }
    return p[sohiepsi-1];
   }
    bool ArmyKnights:: hasPaladinShield() const{
	if(khien==1)
	return true;
	return false;
	}
    bool ArmyKnights:: hasLancelotSpear() const{
	if(giao==1)
	return true;
	return false;
	}
    bool ArmyKnights:: hasGuinevereHair() const{
	if(soitoc==1)
	return true;
	return false;
	}
    bool ArmyKnights:: hasExcaliburSword() const{
	if(guom==1)
	return true;
    return false;
	}
	 	
  ArmyKnights:: ArmyKnights (const string & file_armyknights){
	char sohiepsi_1[100];
    char hiepsi[100];
    FILE* f;
    f = fopen(file_armyknights.c_str(), "r");
    if (f == nullptr) {
        cout << "ERROR";
        exit(1);
    }
    fgets(sohiepsi_1, 99, f);
    xoaxuongdong(sohiepsi_1);
    chuyendoi(sohiepsi_1, this->sohiepsi);
      this->hiepsi = new ArmyKnights*[this->sohiepsi];
for (int i = 0; i < this->sohiepsi; i++) {
    this->hiepsi[i] = new ArmyKnights();
}
    for (int i = 0; i < this->sohiepsi; i++) {
        fgets(hiepsi, 99, f);
        xoaxuongdong(hiepsi);
        chuyendoi1(hiepsi, this->hiepsi[i]->thongtinhiepsi);
        this->hiepsi[i]->id = i + 1;
        this->hiepsi[i]->maxhp = this->hiepsi[i]->thongtinhiepsi[0];
        this->hiepsi[i]->level = this->hiepsi[i]->thongtinhiepsi[1];
        this->hiepsi[i]->phoenixdownI = this->hiepsi[i]->thongtinhiepsi[2];
        this->hiepsi[i]->gil = this->hiepsi[i]->thongtinhiepsi[3];
        this->hiepsi[i]->antidote = this->hiepsi[i]->thongtinhiepsi[4];
    }
    fclose(f);
     p = new BaseKnight*[this->sohiepsi];
   b= new BaseBag*[this->sohiepsi];
   for(int i=0;i<sohiepsi;i++){
   p[i]=BaseKnight::create(this->hiepsi[i]->get_id(),this->hiepsi[i]->get_maxhp(),this->hiepsi[i]->get_level(),this->hiepsi[i]->get_gil(),this->hiepsi[i]->get_antidote(),this->hiepsi[i]->get_phoenixdownI());
   p[i]->hp=p[i]->get_maxhp();
   switch(p[i]->get_type()){
   case NORMAL:
   b[i]=new normalbag();
   break;
   case LANCELOT:
   b[i]=new lancelotbag();
   break;
   case DRAGON:
   b[i]=new dragonbag();
   break;
   case PALADIN:
   b[i]=new paladinbag();
   break;	
   }
   }
    
   	BaseItem *l_1,*l_2,*l_3,*l_4,*l_5;
   	l_1=new PhoenixDownI();
	l_2=new PhoenixDownII();
	l_3=new PhoenixDownIII();
	l_4=new PhoenixDownIV();
	l_5=new Antidote();

	 for(int i=0;i<sohiepsi;i++){
	if(p[i]->get_phoenixdownI()>=1){
	for(int j=0;j<p[i]->get_phoenixdownI();j++){
	b[i]->insertFirst(l_1);	
	}	
	}
    }
for(int i=0;i<sohiepsi;i++){
if(p[i]->get_antidote()>=1){
	for(int j=0;j<p[i]->get_antidote();j++){
	b[i]->insertFirst(l_5);	
	}	
	}
	
}
   for(int i=0;i<sohiepsi;i++){
	p[i]->set_bag(b[i]);
	}	
    }	
    
 ArmyKnights::~ArmyKnights(){
    for (int i = 0; i < sohiepsi; i++) {
        delete p[i];
        delete b[i];
    }
    delete[] hiepsi;
}
	bool ArmyKnights:: fight(BaseOpponent *opponent){

    A: //////////////////////////////////////////////////////////
	BaseOpponent *a=opponent;
    BaseItem *l_1,*l_2,*l_3,*l_4,*l_5;
   	l_1=new PhoenixDownI();
	l_2=new PhoenixDownII();
	l_3=new PhoenixDownIII();
	l_4=new PhoenixDownIV();
	l_5=new Antidote();

    if(a->get_masukien()<=5&&a->get_masukien()>=1){ 
	if(p[sohiepsi-1]->get_level()>=a->get_level0()){	
	p[sohiepsi-1]->set_gil(p[sohiepsi-1]->get_gil()+a->gilthem);
	if(p[sohiepsi-1]->get_gil()>999)
	p[sohiepsi-1]->set_gil(999);
	return true;
	}
	else{	
	p[sohiepsi-1]->hp-=a->get_basedamage()*(a->get_level0()-p[sohiepsi-1]->get_level());			
	}
	}
	else if(a->get_masukien()==6){
		
	if(p[sohiepsi-1]->get_level()>=a->get_level0()){
	p[sohiepsi-1]->set_level(level++);	
	return true;
	}
	else{

	p[sohiepsi-1]->trungdoc=true;
	if(b[sohiepsi-1]->get(ANTIDOTE)!=nullptr){
	p[sohiepsi-1]->trungdoc=false;	
	}
	else{
	p[sohiepsi-1]->hp-=10;	
	if(b[sohiepsi-1]->cont_items<=3){
	b[sohiepsi-1]->cont_items=0;
	b[sohiepsi-1]->firts=nullptr;	
	}
	else{
	
	b[sohiepsi-1]->cont_items-=3;	
	baseitem hientai;
	hientai=b[sohiepsi-1]->firts;
	for(int i=0;i<3;i++){
	hientai=hientai->next;
	}
	b[sohiepsi-1]->firts=hientai;	
	}	
	}	
	}
	p[sohiepsi-1]->set_bag(b[sohiepsi-1]);		
	}
	else if(a->get_masukien()==7){
	int gil_du;	
	if(p[sohiepsi-1]->get_level()>=a->get_level0()){
	p[sohiepsi-1]->set_gil(p[sohiepsi-1]->get_gil()*2);
	if(p[sohiepsi-1]->get_gil()>999){
	gil_du=p[sohiepsi-1]->get_gil()-999;	
	p[sohiepsi-1]->set_gil(999);
	int i=sohiepsi-1;
	do{
	p[i-1]->set_gil(p[i-1]->get_gil()+gil_du);
	if(p[i-1]->get_gil()>999){
	gil_du-=p[i-1]->get_gil()-999;
	p[i-1]->set_gil(999);
    }
    else{
    gil_du=0;	
	}
	i--;
	}
	while(i>0&&gil_du>0);
	}
	return true;
	}
	else{
	p[sohiepsi-1]->set_gil(p[sohiepsi-1]->get_gil()/2);	
	}	
	}
	else if(a->get_masukien()==8){
	if(p[sohiepsi-1]->get_gil()<50)
	return true;
	else{
	if(p[sohiepsi-1]->hp<p[sohiepsi-1]->get_maxhp()/3){
	p[sohiepsi-1]->set_gil(p[sohiepsi-1]->get_gil()-50);
	p[sohiepsi-1]->hp+=p[sohiepsi-1]->get_maxhp()/5;
	}
	}
	return true;	
	}
	else if(a->get_masukien()==9){
	p[sohiepsi-1]->hp=p[sohiepsi-1]->get_maxhp();
	return true;	
	}
	else if(a->get_masukien()==10){
    if(p[sohiepsi-1]->get_type()==DRAGON||(p[sohiepsi-1]->get_level()==10&&p[sohiepsi-1]->hp==p[sohiepsi-1]->get_maxhp())){
    p[sohiepsi-1]->set_level(10);
	p[sohiepsi-1]->set_gil(999);	
	return true;
	}
	else{
	p[sohiepsi-1]->hp=0;	
	}
	}
	else if(a->get_masukien()==11){
	if(khien==1)
	return true;	
	if(p[sohiepsi-1]->get_level()==10||(p[sohiepsi-1]->get_type()==PALADIN)&&p[sohiepsi-1]->get_level()>=8){
    khien=1;
	return true;	
	}
	else{
	p[sohiepsi-1]->hp=0;	
	}
	}
	else if(a->get_masukien()==112){
	b[sohiepsi-1]->insertFirst(l_2);
	}
    else if(a->get_masukien()==113){
    b[sohiepsi-1]->insertFirst(l_3);	
	}
	else if(a->get_masukien()==114){
	b[sohiepsi-1]->insertFirst(l_4);	
	}
	else if(a->get_masukien()==95&&khien==0){
	khien++;
	}
	else if(a->get_masukien()==96&&giao==0){
	giao++;
	}
	else if(a->get_masukien()==97&&soitoc==0){
	soitoc++;	
	}
	else if(a->get_masukien()==98&&guom==0){
	guom++;	
	}
	
	if(p[sohiepsi-1]->hp<=0){
	if(b[sohiepsi-1]->get(I)!=nullptr)	{	
	if(l_1->canUse(p[sohiepsi-1])==true){
	l_1->use(p[sohiepsi-1]);
    }
	}
	else{
	
	if(p[sohiepsi-1]->get_gil()>=100){
	////// GOI PHUONG HOANG
	p[sohiepsi-1]->set_gil(p[sohiepsi-1]->get_gil()-100);
	p[sohiepsi-1]->hp=p[sohiepsi-1]->get_maxhp();
	}
}
	p[sohiepsi-1]->set_bag(b[sohiepsi-1]);
	}
	if(p[sohiepsi-1]->hp<=0){
	sohiepsi--;
	}	
	return false;	
}
	
	
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight();
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
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
void KnightAdventure::loadArmyKnights(const string &file_army){
	  armyKnights=new ArmyKnights(file_army);
	}
void KnightAdventure:: loadEvents(const string &file_events){
 	events=new Events(file_events);
	}	
void KnightAdventure:: run(){	
    BaseKnight *a[armyKnights->sohiepsi];	
    BaseOpponent** p = new BaseOpponent*[events->count()];
    for(int i=0; i<events->count(); i++) {	
    p[i] = new BaseOpponent();
    p[i]->set_masukien(events->get(i));
    switch(p[i]->get_masukien()){
	case 1:
	p[i]=new MadBear();
	break;	
	case 2:
	p[i]=new Bandit();

	break;
	case 3:
	p[i]=new LordLupin();
	
	break;
	case 4:
	p[i]=new Elf();

	break;
	case 5:
	p[i]=new Troll();

	break;
	case 6:
	p[i]=new Tornbery();
	break;
	case 7:
	p[i]=new QueenOfCards();
	break;
	case 8:
	p[i]=new NinaDeRings();
	break;
	case 9:
	p[i]=new DurianGarden();
	break;
	case 10:
	p[i]=new OmegaWeapon();
	break;
	case 11:
	p[i]=new Hades();
	break;	
	}
	p[i]->set_level0(i);
    }
    
	for(int i=0;i<events->count();i++){
    armyKnights->fight(p[i]);
    armyKnights->printInfo();	
    if(armyKnights->sohiepsi<=0){
    armyKnights->printResult(false);	
    delete[] p;	
	exit(0);
	} 
	
	}
	armyKnights->printResult(true);
	delete[] p;	
	exit(0);
	}
	

KnightAdventure::~KnightAdventure(){
delete events;
delete armyKnights;	
}

KnightAdventure::KnightAdventure() {
    events=nullptr;
    armyKnights=nullptr;
}
int main(){
	
}
/* * * END implementation of class KnightAdventure * * */