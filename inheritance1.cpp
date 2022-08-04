#include <iostream>
class person{
private:
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
int main (){
    person p("sude",100,"Istanbul", 5000);
    p.eat(10);
    p.travel("Ankara");

    return 0;
}