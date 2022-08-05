#include <iostream>

class polygon {
protected:
    int width;
    int height;
public:
    polygon():width(0),height(0){
    }
    polygon(int wpoly,int hpoly):width(wpoly),height(hpoly){
    }

    void setValues(int w, int h){
        width=w;
        height=h;
    }
};
class rectangle: public polygon{
public:
    rectangle():polygon(){
    }
    rectangle(int w, int h):polygon(w,h){
    }

    int calculateArae(){
        return width*height;
    }
};
class triangle :public polygon {
public:
    triangle():polygon(){
    }
    triangle(int w, int h):polygon(w,h){
    }

    int calculateArea(){
        return (width*height)/2;
    }
};

int main (){

    rectangle r1(5,10);
    triangle t1(5,10);

// some additions for explaining pointer to base class
    polygon *pPtr1= &r1;
    polygon *pPtr2=&t1;


    std::cout<< "Rectangle 1's area is: "<<r1.calculateArae()<<std::endl;
    std::cout<<"Triangle 1's area is : "<<t1.calculateArea()<<std::endl;

// some additions for explaining pointer to base class 
    pPtr1->setValues(8,10);
    std::cout<< "Rectangle 1's area is: "<<r1.calculateArae()<<std::endl;


    return 0;
}