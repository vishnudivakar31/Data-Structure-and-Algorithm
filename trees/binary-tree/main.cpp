#include<iostream>
#include"tree.h"

using namespace std;

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  Tree tree;
  try {
    for(int i = 0; i < 7; i++) {
      tree.append(arr[i]);
    }
    cout<<tree.countNodes()<<endl;
  } catch(const char *err) {
    cerr<<err<<endl;
  }
  return 0;
}
