#include <iostream>
#include <valarray>

class navalShip{
protected:
    std::string name;
    double coordx;
    double coordy;
    int armorRating;
    int hitPoint;
    bool isSunk;
public:
    navalShip(){
        name="";
        coordx=0.0;
        coordy=0.0;
        armorRating=0;
        hitPoint=1;
        isSunk=false;
    }
    navalShip(std::string name, double x,double y,int armorRating,int hitPoint):name(name),coordx(x),coordy(y),armorRating(armorRating),hitPoint(hitPoint){
        isSunk=false;
    }
    void sailTo(double targetcoordx, double targetcoordy){
        if(!isSunk){
            coordx=targetcoordx;
            coordy=targetcoordy;
        }
    }
    void isStillOperational(){
        if(!isSunk){
            std::cout << name<<": is still operational at ("<<coordx<< ","<<coordy<<")"<<std::endl;
        }
        else{
            std::cout << name<<": lies at the sea/ocean floor at ("<<coordx<< ","<<coordy<<")"<<std::endl;
        }
    }
    double calculateDistance(double otherShipx,double otherShipy){
        return sqrt(pow(otherShipx-coordx,2.0)+ pow(otherShipy-coordy,2.0));
    }

    void firedUpon(int firePower) {
        if (!isSunk) {
            if (firePower > armorRating) {
                int damage = firePower - armorRating;

                if (damage > hitPoint) {
                    std::cout << name << ": sustained critical hull damage and sunk..." << std::endl;
                    hitPoint = 0;
                    isSunk = true;
                } else {
                    hitPoint = hitPoint - damage;
                    std::cout << name << ": sustained hull damage of " << damage << ". Remaining hit point: "<<hitPoint<< std::endl;
                }
            } else {
                std::cout << name << ": sustained no hull damage. Attack ineffective!" << std::endl;
            }
        }
        else{
            std::cout<< "Ship is already sunk"<< std::endl;
        }
    }

    virtual void attack(navalShip *targetShip){
        }
};

class cruiser:public navalShip{
protected:
    int firePower=50;
    int weaponRange=200;
    int ammo=100;
    int hitChance=85;
public:
    cruiser():navalShip(){
    }
    cruiser(std::string name, double x, double y, int armorRating , int hitPoint):navalShip(name, x,y,armorRating,hitPoint){
    }
    void attack(navalShip *targetShip){
       if(this-> ammo>0 && targetShip->calculateDistance(this->coordx, this-> coordy) <= this->weaponRange) {
           std::cout << name << ": Target is in range, attacking"<< std::endl;
           this-> ammo --;

           if(rand()%100<= hitChance){
               std::cout << this-> name<< ": Target HIT!"<<std::endl;
               targetShip->firedUpon( this-> firePower);
           }

           else {
               std::cout<< name << ": Target MISSED!"<<std::endl;
           }
       }
       else {
           std::cout << name << ": Either this ship is out of ammo or target is OUT of range "<<std::endl;
       }
    }
};

class submarine:public navalShip{
protected:
    int firePower=100;
    int weaponRange=100;
    int ammo=50;
public:
    submarine():navalShip(){
    }
    submarine(std::string name, double x, double y, int armorRating, int hitPoint):navalShip(name, x,y,armorRating,hitPoint){
    }

    void attack(navalShip *targetShip){
        if(this-> ammo>0 && targetShip ->calculateDistance(this->coordx, this-> coordy)<= weaponRange){
            std::cout << name << ": Target is in range, firing torpedo!"<<std::endl;
            this->ammo--;

            std::cout << name <<":Target HIT!"<< std::endl;
            targetShip->firedUpon(this->firePower);
        }
        else{
            std::cout << name << " :Target is OUT of range "<< std::endl;
        }
    }
};

int main(){
    srand(time(NULL));

navalShip **turkishShips= new navalShip*[2];
turkishShips[0]= new submarine("Burakreis",100,200,45,200);
turkishShips[1]= new cruiser("Barbaros",100,200,45,200);

navalShip blackSeaPirate("Korsan 1",200,200,10,110);

turkishShips[0]->attack(&blackSeaPirate);
turkishShips[1]->attack(&blackSeaPirate);
turkishShips[0]->attack(&blackSeaPirate);

    return 0;
}