#include<iostream>

using namespace std;

template<class T>
class Arithemetic {
  private:
    T a;
    T b;
  public:
    Arithemetic() {
      a = 1;
      b = 1;
    }
    Arithemetic(T a, T b);
    T sum();
    T sub();
};

template<class T>
Arithemetic<T>::Arithemetic(T a, T b) {
  this->a = a;
  this->b = b;
}

template<class T>
T Arithemetic<T>::sum() {
  return a + b;
}

template<class T>
T Arithemetic<T>::sub() {
  return a - b;
}

int main() {
  Arithemetic<int> ar(10, 5);
  Arithemetic<float> ar1(12.5, 2);

  cout<<"First sum: "<<ar.sum()<<", difference: "<<ar.sub()<<"\n";
  cout<<"Second sum: "<<ar1.sum()<<", difference: "<<ar1.sub()<<"\n";

  return 0;
}
