#include <iostream>
using namespace std;
int dlta[3] = {5, 3, 1};
void print(int A[], int n) {
  for (int i = 0; i < n; i++) cout << A[i] << ' ';
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
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {

	int i,j,k;
 
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;
 
	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
    print(A,9);
}

// Recursive function to sort an array of integers.
void MERsort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing.
 
	mid = n/2;  // find the mid index.
 
	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = new int[mid];
	R = new int [n - mid];
 
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
 
	MERsort(L,mid);  // sorting the left subarray
	MERsort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	// the delete operations is very important
	delete [] R;
	delete [] L;
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
  MERsort(arr, 9);
  print(arr, 9);
}