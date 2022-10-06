#include <iostream>
#include <memory>

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
    tank (const tank &t){
        armorRating=t.armorRating;
        std::cout <<"(Constructed) Tank object - Copy constructor,Armor Rating is "<< armorRating<<std::endl;
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

void inflictDamage(int *damage, std::shared_ptr<tank> sT)
{
    sT->sustainDamage(*damage);
    std::cout<<"Inflict Damage function: "<<sT.use_count()<<std::endl;
    std::cout<<"Inflict Damage function unique: "<<sT.unique()<<std::endl;
    std::cout<< "Address of the object: "<<&sT <<std::endl;
    *damage=*damage+1;
}

//main part

int main (){
    int dmg=8;
    /*
    tank fifthDivisionTank(20);
    tank fourthDivisionTank;
     */
    tank *ptrThirdDivisionTank= new tank(30);

    std::unique_ptr<tank> ptrSecondDivisionTank= std::make_unique<tank>(39);
    std::shared_ptr<tank> ptrFirstDivisionTank  = std::make_shared<tank>(27);
    std::cout <<"Main function: "<< ptrFirstDivisionTank.use_count()<<std::endl;
    std::cout <<"Main function unique: "<< ptrFirstDivisionTank.unique()<<std::endl;

    inflictDamage(&dmg,ptrFirstDivisionTank);
    std::cout <<"Main function: "<< ptrFirstDivisionTank.use_count()<<std::endl;
    std::cout <<"Main function unique: "<< ptrFirstDivisionTank.unique()<<std::endl;

/*
    std::cout<<"Damage value is "<<dmg<<std::endl;
    inflictDamage(&dmg,fifthDivisionTank);
    std::cout<<"Damage value is "<<dmg<<std::endl;
*/
    delete (ptrThirdDivisionTank);

    return 0;
}
