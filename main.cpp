#include <iostream>
using namespace std;
int main() {
  int count = 0;
  int n = 10;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) count++;

  }
  cout << count;
}