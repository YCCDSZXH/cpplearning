#include <iostream>
using namespace std;

bool compare(int a,int b)
{
	if(a>b)
	return true;
	else
	return false;
}

void swap(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
}

bool findmin(int a,int b)
{
	if(a<b)
	return true;
	else
	return false;
}

void show(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//从小到大 
int *bob(int A[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
		if(compare(A[j],A[j+1]))//如果前面的大于后面的，交换 
		swap(A[j],A[j+1]);
		} 
	}
	return A;
}

int *insert(int A[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i;j>0&&A[j]<A[j-1];j--){
		swap(A[j],A[j-1]);
		}
	}
	return A;
} 

int *select(int A[],int n){
	int min=A[0];
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(findmin(A[j],min)){
				min=A[j];
			}
			swap(A[i],min);			
		}
	}
	return A;
}

int main(){
	int arr[10]={10,56,4,26,51,12,13,74,14,11};
	int *arr2=bob(arr,10);
	show(arr2,10);
}
