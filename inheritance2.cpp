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
    polygon p1(6,7);
    p1.setValues(3,4);

    rectangle r(5,10);
    triangle t1(5,10);

    std::cout<< r.calculateArae()<<std::endl;
    std::cout<< t1.calculateArea()<<std::endl;

    return 0;
}