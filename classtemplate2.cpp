#include <iostream>
template<class T>
class die{
private:
    int sideCount;
    T *valueOfSides;
public:
    die(int sides, T *values){
        sideCount=sides;
        valueOfSides= new T[sideCount];

        for(int i=0; i<sideCount;i++){
            valueOfSides[i]=values[i];
        }
    }

    T randomResult(){
        return valueOfSides[rand()%sideCount];
    }
    ~die(){
        delete(valueOfSides);
    }
};

int main(){
    int arrsix[]={1,2,3,4,5,6};
    int arreight[]={1,2,3,4,5,6,7,8};
    std::string arrfour[]={"hit","miss","miss","miss"};

    die<int> sixSided(6,arrsix);
    die<int> eightSided(8,arreight);
    die<std::string> fourSided(4,arrfour);

    std::cout<<sixSided.randomResult()<<std::endl;
    std::cout<<eightSided.randomResult()<<std::endl;
    std::cout<<fourSided.randomResult()<<std::endl;


    return 0;
}