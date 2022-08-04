#include <iostream>
class person{
protected:
    std::string name;
    int hungerLevel;
    std::string location ;
    int money;
public:
    person(): name(""),location(""),hungerLevel(100), money(0){
    }

    person (std::string n, int h, std::string l, int m): name(n), location(l),money(m){
      if (h<0){
        hungerLevel=0;
      }
      else if(h>100){
      hungerLevel=100;
      }
      else{
          hungerLevel=h;
      }
    }


    void travel(std::string target){
        location=target;
    }
    void eat(int foodQuality){
        if(hungerLevel+foodQuality>100){
            hungerLevel=100;
        }
        else{
            hungerLevel+=foodQuality;
        }
    }
};

class sultan:public person{
private:
    std::string kingdom;
public:
    //calling the parent class's constructor in child class's constructor.
    sultan(std::string n, int hl, std::string l, int m, std::string k):person(n,hl,l,m), kingdom(k){
    }

    void tax(int taxRevenue){
        money+=taxRevenue;
    }
};

class merchant:public person{
private:
    std::string shop;
public:
    merchant(std::string n, int hl, std::string l, int m, std::string s):person(n,hl,l,m), shop(s){
    }

    void trade(int tradeRevenue){
        money+=tradeRevenue;
    }
};


int main (){
    person p("sude",100,"Istanbul", 5000);
    p.eat(10);
    p.travel("Ankara");

    return 0;
}