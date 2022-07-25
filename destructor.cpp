#include <iostream>
class experiment{
private:
    double *measurements;
    int mcount;
    int mindex;
public:
    experiment(int count):mcount(count){
        measurements=(double*) malloc(mcount*sizeof(double));
        mindex=0;
    }
void addmeasurement(double m){
        if(mindex<mcount){
            measurements[mindex]=m;
            mindex++;
        }
        else{
            std::cout << "Measurement "<< m <<" can not be added."<<std::endl;
        }
    }
    void printmeasurement(){
        for(mindex=0; mindex<mcount; mindex++){
            std::cout<< "Measurement "<<mindex<<" is: "<< measurements[mindex];
        }
    }

    ~experiment(){
        free(measurements);
    };
};
int main(){

    return 0;
}