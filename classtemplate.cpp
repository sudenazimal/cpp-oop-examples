#include <iostream>
template< class T>
class pair{
private:
    T a,b;
public:
    pair(T first,T second): a(first),b(second){}
    T getMax(){
        if (a<b){
            return b;
        }
        else {
            return a;
        }
    }
};
int main (){

  pair<int> intPair(6,12);
  pair<char> charPair('h','9');
  pair<std::string> stringPair("SUDE","NAZ");
  pair <double> doublePair(4.6,5.3);

  std::cout << intPair.getMax()<<std::endl;
  std::cout << charPair.getMax()<<std::endl;
  std::cout << stringPair.getMax()<<std::endl;
  std::cout << doublePair.getMax()<<std::endl;
    return 0;
}