#include <iostream>


class weapon {
protected:
    std::string name;
    double weight;
    int durability;
public:
    weapon(): name("slashing"), weight(1.0), durability(0){
    }

    weapon(std::string n, double w, int d): name (n){
        if(w>0){
            weight=w;
        }
        else {
            weight=1.0;
        }
        if (d>=0 && d<=100){
            durability=d;
        }
        else{
            durability=100;
        }

    }

    virtual double dealDamage(int hp, int armor, std::string type,int range)=0;

    virtual void reportStatus()=0;
};

class rangedWeapon{
protected:
    int range;
    int ammo;
    int rangedDamage;

public:
    rangedWeapon(): range(10),ammo(1),rangedDamage(1){
    }
    rangedWeapon(int r, int a, int rdmg): range(r), ammo(a), rangedDamage(rdmg){
    }

    void reload(int newAmmo){
        ammo+=newAmmo;
    }
};


class meleeWeapon{
protected:
    std::string damageType;
    int meleeDamage;
    int maxMeleeDamage;
public:
    meleeWeapon(): damageType(""), meleeDamage(1), maxMeleeDamage(1){
    }
    meleeWeapon(std::string t, int mdmg, int maxMDmg):damageType(t),meleeDamage(mdmg), maxMeleeDamage(maxMDmg){

        if(meleeDamage>maxMeleeDamage) {
            meleeDamage = maxMeleeDamage;
        }
    }

    void prepare(int repairAmount){
       if(repairAmount+ meleeDamage> maxMeleeDamage) {
           meleeDamage = maxMeleeDamage;
       }
       else{
           meleeDamage+= repairAmount;
       }
    }

};

class sword :public weapon, public meleeWeapon {
protected:
    bool isTwoHanded;
    bool hasHilt;
public:
    sword():weapon(),meleeWeapon() {
        isTwoHanded=false;
        hasHilt=false;
    }
    sword(std::string n, double w, int d,std::string t, int mdmg,int maxMDmg,bool twoH, bool hilt):weapon(n,w,d),meleeWeapon(t, mdmg,maxMDmg), isTwoHanded(twoH), hasHilt(hilt){
    }

    double dealDamage(int hp, int armor, std::string type, int range){
        if (range >1){
          return 0;
        }
        else{
            if(this->type == "slashing "&& type =="cloth"){
                return (meleeDamage*1.4-armor);
            }
            else if(this-> type == "slashing" && type=="leather"){
                return (meleeDamage*1.3-armor);
            }
        }
    }
};

class rifle:public  weapon, public rangedWeapon, public meleeWeapon{
protected:
    bool haslaserSights;
    std::string mode;
public:
    rifle(std::string n, double w, int d,std::string t, int mdmg,int maxMDmg,bool twoH, bool hilt):weapon(n,w,d),meleeWeapon(t, mdmg,maxMDmg){
    }
    rifle(bool lght, std::string m): haslaserSights(lght), mode(m){
    }


    double dealdamage(int hp,int armor, std::string type, int range){
    }

};