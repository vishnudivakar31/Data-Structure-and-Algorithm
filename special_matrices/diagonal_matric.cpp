#include<iostream>

using namespace std;

class DiagonalMatrix {
  private:
    int *matrix;
    int size;
  public:
    DiagonalMatrix(int size) {
      matrix = new int[size];
      this->size = size;
    }
    ~DiagonalMatrix() {
      delete []matrix;
    }
    void setItem(int i, int j, int item);
    int getItem(int i, int j);
    void display();
};

void DiagonalMatrix::setItem(int i, int j, int item) {
  if(i == j) {
    matrix[i - 1] = item;
  }
}

int DiagonalMatrix::getItem(int i, int j) {
  if(i == j) {
    return matrix[i - 1];
  }
  return 0;
}

void DiagonalMatrix::display() {
  for(int i = 1; i <= size; i++) {
    for(int j = 1; j <=size; j++) {
      cout<<getItem(i, j)<<"\t";
    }
    cout<<"\n";
  }
}

int main() {
  int size, item;
  cout<<"Enter the size of diagonal matrix: ";
  cin>>size;
  DiagonalMatrix matrix(size);
  for(int i = 1; i <= size; i++) {
    cout<<"Enter the item for row: "<<i<<", col: "<<i<<" : ";
    cin>>item;
    matrix.setItem(i, i, item);
  }
  matrix.display();
  return 0;
}
