#include <iostream>
#include <cmath>

class point3D{
private:
    double coordx;
    double coordy;
    double coordz;
public:
    point3D(double x,double y, double z) :coordx(x), coordy(y),coordz(z){
    }
    point3D(){
        coordx=0;
        coordy=0;
        coordz=0;
    }

    double calculateDistance(point3D p){
        return sqrt(pow(coordx-p.coordx,2.0)+pow(coordy-p.coordy,2.0)+pow(coordz-p.coordz,2.0));
    }
};
class lineSegment3D{
private:
    point3D startpoint;
    point3D endpoint;

public:
    lineSegment3D(point3D p1,point3D p2): startpoint(p1), endpoint(p2){
    }

    double calculateLength(){
        return startpoint.calculateDistance(endpoint);
    }
};
class sphere {
private:
    point3D center;
    double radius;
public:
    sphere(){
        radius=0;
        point3D center(0,0,0);
    }

    sphere(point3D obj, double val):center(obj),radius(val){
    }

    double calculateArea(){
        return (4*M_PI*pow(radius,2.0));
    }

    double calculateVolume(){
       return ((4/3)*M_PI*pow(radius,3.0));
    }
};


int main() {
point3D p1(5,4,8);
point3D p2(3,2,8);
point3D p3;
lineSegment3D l(p1,p2);

std::cout<< l.calculateLength()<< std::endl;
    return 0;
}
