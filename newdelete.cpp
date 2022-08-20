#include <iostream>

class tank{
protected:
    int armorRating;
public:
    tank():armorRating(0){
        std::cout << "(Constructed) Tank object  Default constuctor, Armor Rating is 0"<<std::endl;
    }
    tank(int ar):armorRating(ar){
        std::cout << "(Constructed) Tank object - 1 parameter constructor, Armor Rating is "<< armorRating<<std::endl;
    }
    ~tank(){
        std::cout << "(Destructed) Tank object, Armor Rating is "<<armorRating<<std::endl;
    }

    void sustainDamage(int damage){
            armorRating-= damage;
        }

    void evaluateStatus(){
        if(armorRating>=0){
            std::cout << "Tank is still operational"<<std::endl;
        }
        else{
            std::cout<<"Tank is inoperable"<<std::endl;
        }
    }
};

void inflictDamage(int *damage, tank t){
    t.sustainDamage(*damage);
    *damage=*damage+1;
}


int main (){
    int dmg=8;
    tank fifthDivisionTank(20);
    tank fourthDivisionTank;
    tank *ptrThirdDivisionTank= new tank(30);

    std::cout<<"Damage value is "<<dmg<<std::endl;
    inflictDamage(&dmg,fifthDivisionTank);
    std::cout<<"Damage value is "<<dmg<<std::endl;

    delete (ptrThirdDivisionTank);


    return 0;
}
