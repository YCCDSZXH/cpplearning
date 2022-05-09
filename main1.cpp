#include <iostream>
using namespace std;
int dlta[3] = {5, 3, 1};
void print(int A[], int n) {
  for (int i = 0; i < n; i++) cout << A[i] << ' ';
  cout << endl;
}
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void BUBsort(int A[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
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
void SELsort(int A[], int n) {
  for (int i = 0; i < n; i++) {
    int min = A[i], MinIndex = i;
    for (int j = i; j < n; j++) {
      if (min > A[j]) {
        min = A[j];
        MinIndex = j;
      }
    }
    swap(A[i], A[MinIndex]);
    print(A, n);
  }
}

void SHEinsert(int A[], int n, int dlt) {
  for (int i = 1; i < n; i++) {
    int now = i;
    for (int j = i - 1; j >= 0; j -= dlt) {
      if (A[j] > A[now]) {
        int tmp = A[j];
        A[j] = A[now];
        A[now] = tmp;
        now = j;
      }
    }
  }
}
void SHEsort(int A[], int n, int dlta[], int dltan) {
  for (int i = 0; i < dltan; ++i) {
    SHEinsert(A, n, dlta[i]);
    print(A, 9);
  }
}
int main() {
  int arr[9] = {31, 73, 44, 13, 7, 28, 22, 64, 53};
  SHEsort(arr, 9, dlta, 3);
}