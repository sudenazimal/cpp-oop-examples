#include <iostream>
 class Fraction {
public:
    int num;
    int denom;
    Fraction(int n, int d): num(n), denom(d){
        std::cout<<"(Constructed). Normal constructor.: " << num << "/" << denom << std::endl;
    }
     Fraction():num(0), denom(0){
        std::cout << "(Constructed). Default constructor: "<< num << "/" << denom << std::endl;
    }
    ~Fraction(){
        std::cout <<"(Dectructed)..:" << num << "/" << denom << std::endl;
    }

    Fraction operator + (const Fraction &operand){
        Fraction result;
        if(denom== operand.denom){
            result.denom= denom;
            result.num= num + operand.num;
        }
        else{
            result.denom= denom*operand.denom;
            result.num= num*operand.denom + operand.num*denom;
        }
        return result;
    }

     Fraction operator - (const Fraction &operand){
         Fraction result;
         if(denom== operand.denom){
             result.denom= denom;
             result.num= num - operand.num;
         }
         else{
             result.denom= denom*operand.denom;
             result.num= num*operand.denom - operand.num*denom;
         }
         return result;
     }
     Fraction operator * (const Fraction &operand){
//         Fraction result;
//
//         result.denom= denom * operand.denom;
//         result.num= num * operand.num;

         return Fraction(num* operand.num ,denom*operand.denom);
     }

    void print()
    {
        std::cout << num << "/"<< denom << std::endl;
    }
 };
int main(){

    Fraction f1(9,5);
    Fraction f2(3,2);
    Fraction sum;

    sum = f1 + f2;

    sum.print();
    return 0;
}