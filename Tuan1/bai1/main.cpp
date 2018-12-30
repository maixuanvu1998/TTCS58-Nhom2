#include<iostream>
using namespace std;
void In(int a[5][5],int m , int n){
	int i;
	if(m==n)
		cout << a[n][n];
	else {
		for( i=m ; i<=n ; i++)
			cout << a[m][i] << " ";
		for(i=m+1 ; i<=n ;i++)
			cout << a[i][n] << " ";
		for(i = n-1 ; i>=m ; i--)
			cout << a[n][i] << " ";
		for(i=n-1 ; i>=m+1 ; i--)
			cout<< a[i][m] << " ";
		In(a,m+1,n-1);
    }
}
int main(){
	int a[5][5]={10, 5, 6, 4, 7,2,9,8,6,3,8,10,5,7,8,11,7,9,12,6,12,9,10,11,10};
	cout << "Output :" << endl;
	In(a,0,4);
	return 0;
}
