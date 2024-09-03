#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
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
    int get_level(){
    return level;
	}
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
#endif // __KNIGHT2_H__
