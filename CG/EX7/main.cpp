#include <iostream>
using namespace std;
int main()
{
    int n,m,a[21][21]={0};
    cin>>m>>n;
    int i,j;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            if (i==1&&j==1)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j]+a[i][j-1];
        }
    cout<<a[m][n]<<endl;
}