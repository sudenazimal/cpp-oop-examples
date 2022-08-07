#include <iostream>

class landVehicle{
protected:
    int topSpeed;
public:
    landVehicle(){
        topSpeed=0;
    }

    landVehicle(int s): topSpeed(s){
    }

    virtual void travel (int distance, int speed){
    }
};

class iceVehicle: public landVehicle{
protected:
    double fuelLevel;
    double fuelConsumptionByHour;
public:
    iceVehicle():landVehicle(),fuelLevel(0),fuelConsumptionByHour(100){
    }
    iceVehicle(int s, double fl, double fcbh):landVehicle(s),fuelLevel(fl),fuelConsumptionByHour(fcbh){
    }


//any child classes of iceVehicle can override travel function
    virtual void travel(int distance, int speed){
        if(speed> topSpeed){
            speed=topSpeed;
        }

        double fuelRequired;
        fuelRequired=(distance/(double)speed)*fuelConsumptionByHour;

        if(fuelRequired<= fuelLevel){
            fuelLevel-= fuelRequired;
            std::cout<< "Arrived at destinaion"<< std::endl;

        }
        else{
            std::cout<< "Not enough fuel."<< std::endl;
        }
    }

};

class electricVehicle: public landVehicle{
protected:
    double batteryLevel;
    double batterConsumptionByHour;
public:
    electricVehicle():landVehicle(),batteryLevel(0),batterConsumptionByHour(100){
    }
    electricVehicle(int ts,double bl, double bcbh):landVehicle(ts),batteryLevel(bl), batterConsumptionByHour(bcbh){
    }

     void travel(int distance, int speed){

        if(speed>topSpeed){
            speed=topSpeed;
        }

        double batteryRequired;
        if(speed<=(topSpeed/2)){
            batteryRequired=(double)(distance/speed)*batterConsumptionByHour*0.3;
        }
        else{
            batteryRequired=(double)(distance/speed)*batterConsumptionByHour;
        }

        if(batteryRequired> batteryLevel){
            std::cout<< "Not enough battery."<< std::endl;

        }
        else{
            batteryLevel-=batteryRequired;
            std::cout <<"Arrived at destination"<<std::endl;
        }
    }
};


int main (){
    iceVehicle fordFiesta1(180,45,1.7);
    electricVehicle teslaRoaster(156,54,1.4);

    landVehicle *pCar1=&fordFiesta1;
    landVehicle *pCare2=&teslaRoaster;

    pCar1->travel(458,100);
    pCar1->travel(700,120);
    pCar1->travel(9800,300);



    return 0;
}