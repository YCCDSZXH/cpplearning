#include <iostream>
using namespace std;

void print(int A[], int n) {
  for (int i = 0; i < n; i++) cout << A[i] << ' ';
  cout << endl;
}
void swap(int &a,int &b){
  int tmp = a;
  a = b;
  b = tmp;
}
void BUBsort(int A[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j],A[j+1]);
      }
    }
    print(A, 9);
  }
}

void INSsort(int A[], int n) {
  for (int i = 1; i < n; i++) {
    int now = i;
    for (int j = i - 1; j >= 0; j--) {
      if (A[j] > A[now]) {
        int tmp = A[j];
        A[j] = A[now];
        A[now] = tmp;
        now = j;
      }
    }
    print(A, 9);
  }
}
void SELsort(int A[],int n){
  for(int i = 0; i < n;i++){
    int min = A[i],MinIndex = i;
    for(int j = i; j < n;j++){
      if(min>A[j]){
        min = A[j];
        MinIndex = j;
      }
    }
    swap(A[i],A[MinIndex]);
    print(A,n);
  }
}
int main() {
  int arr[9] = {31, 73, 44, 13, 7, 28, 22, 64, 53};
  SELsort(arr, 9);
}