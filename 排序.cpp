#include <iostream>
using namespace std;
int dlta[3] = {5, 3, 1};
void print(int A[], int n) {
  for (int i = 0; i < n; i++) cout << A[i] << "\t";
  cout << endl;
}
void swap(int& a, int& b) {
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
  for (int i = 0; i < n / dlt + n % dlt; i++) {
    int now = i;
    for (int k = 0; k < n / dlt; k++) {
      now = i;
      for (int j = i; j < n; j += dlt) {
        if (A[j] < A[now]) {
          int tmp = A[j];
          A[j] = A[now];
          A[now] = tmp;
          now = j;
        }
      }
    }
  }
}
void SHEsort(int A[], int n) {
  int dlta[] = {5, 3, 1};
  int dltan = 3;
  for (int i = 0; i < dltan; ++i) {
    SHEinsert(A, n, dlta[i]);
    print(A, 9);
  }
}

void Merge(int arr[], int l, int q, int r) {
  int n = r - l + 1;  //临时数组存合并后的有序序列
  int* tmp = new int[n];
  int i = 0;
  int left = l;
  int right = q + 1;
  while (left <= q && right <= r)
    tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
  while (left <= q) tmp[i++] = arr[left++];
  while (right <= r) tmp[i++] = arr[right++];
  for (int j = 0; j < n; ++j) arr[l + j] = tmp[j];
  delete[] tmp;  //删掉堆区的内存
  print(arr, 9);
}

void MERsort(int arr[], int l, int r) {
  // print(arr, 9);
  if (l == r) return;  //递归基是让数组中的每个数单独成为长度为1的区间
  int q = (l + r) / 2;
  MERsort(arr, l, q);
  MERsort(arr, q + 1, r);
  Merge(arr, l, q, r);
}

void Merge2(int arr[], int low, int mid, int high) {
  // low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
  int i = low, j = mid + 1, k = 0;  // mid+1为第2有序区第1个元素，j指向第1个元素
  int* temp = new int[high - low + 1];  // temp数组暂存合并的有序序列
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j])  //较小的先存入temp中
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)  //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
    temp[k++] = arr[i++];
  while (j <= high)  //同上
    temp[k++] = arr[j++];
  for (i = low, k = 0; i <= high;
       i++, k++)  //将排好序的存回arr中low到high这区间
    arr[i] = temp[k];
  delete[] temp;  //释放内存，由于指向的是数组，必须用delete []
  print(arr, 9);
}
void MergeSort(int arr[], int low, int high) {
  if (low >= high) {
    return;
  }  // 终止递归的条件，子序列长度为1
  int mid = low + (high - low) / 2;  // 取得序列中间的元素
  MergeSort(arr, low, mid);          // 对左半边递归
  MergeSort(arr, mid + 1, high);     // 对右半边递归
  Merge2(arr, low, mid, high);       // 合并
}

int Partition(int* array, int left, int right) {
  int partition_index = left;  // 跟踪划分的分界线
  for (int i = left; i < right; i++) {
    if (array[i] < array[right]) {
      swap(array[partition_index++], array[i]);  // 比主元小的都放在左侧
    }
  }
  swap(array[partition_index], array[right]);  // 最后把主元换回来
  return partition_index;
}
void QUIsort(int* arr, int l, int r) {
  if (r <= l) return;
  int tmp = Partition(arr, l, r);
  cout << '|' << arr[tmp] << "|  \t";
  print(arr, 9);
  QUIsort(arr, l, tmp - 1);
  QUIsort(arr, tmp + 1, r);
}

void Down(int array[], int i, int n) {  // 最后结果就是大顶堆
  int parent = i;                       // 父节点下标
  int child = 2 * i + 1;                // 子节点下标
  while (child < n) {
    if (child + 1 < n &&
        array[child] <
            array[child + 1]) {  // 判断子节点那个大，大的与父节点比较
      child++;
    }
    if (array[parent] < array[child]) {  // 判断父节点是否小于子节点
      swap(array[parent], array[child]);  // 交换父节点和子节点
      parent = child;  // 子节点下标 赋给 父节点下标
    }
    child = child * 2 + 1;  // 换行，比较下面的父节点和子节点
  }
}

void BuildHeap(int array[], int size) {
  for (int i = size / 2 - 1; i >= 0;
       i--) {  // 倒数第二排开始, 创建大顶堆，必须从下往上比较
    Down(array, i, size);  // 否则有的不符合大顶堆定义
  }
}

void HEAsort(int array[], int size) {
  BuildHeap(array, size);  // 初始化堆
  print(array, size);
  for (int i = size - 1; i > 0; i--) {
    swap(
        array[0],
        array
            [i]);  // 交换顶点和第 i 个数据
                   // 因为只有array[0]改变，其它都符合大顶堆的定义，所以可以从上往下重新建立
    Down(array, 0, i);  // 重新建立大顶堆

    printf("排序的数组：");
    print(array, size);
  }
}
int main() {
  int arr[9] = {31, 73, 44, 13, 7, 28, 22, 64, 53};
  print(arr, 9);
  HEAsort(arr, 9);
  print(arr, 9);
}