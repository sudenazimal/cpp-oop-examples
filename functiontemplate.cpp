#include<iostream>

template<typename T>
T add(T numa, T numb){
    T numsum= numa + numb;
    return numsum;
}
int main(){
    std::cout << add<int>(5,6)<< std::endl;
    std::cout << add<double>(5.6,7.0)<<std::endl;
    std::cout << add('g','a')<<std::endl;

    return 0;
}
// result should be 11   13.4   L