#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 10
void Nhap(int m,int n, int a[][MAX])
{
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout<<endl<<"nhap vao phan tu A["<<i<<"]["<<j<<"] : ";
			cin>>a[i][j];
		}
	}
}
void Xuat(int a[][MAX], int m, int n){
	for(int i = 0;i < m; i++)
	{
		for(int  j = 0 ; j< n ; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void xoanoc(int a[5][5], int n, int k)
{
	
	if(k == n) 
	{
		cout << a[k][k];
	}
	else{
		for(int i = k; i <n; i++)
		{
			cout<< a[k][i]<< " ";		//in hang m
		}
		for(int i = k+1; i< n; i++)
		{
			cout<<a[i][n-1]<< " ";
		}
		for(int i = n-2; i>= k; i--)
		{
			cout<< a[n-1][i] << " ";
		}
		for(int i = n-2; i>k; i--)
		{
			cout<<a[i][k]<< " ";
		}
		xoanoc(a,n-1, k+1);
	}
}

int main()
{
	
	int a[5][5]={
11,7,15,20,10,
32,114,9,81,26,
53,49,0,87,22,
46,51,98,45,36,
13,7,82,51,93
}
	;
	int k =0;
	
	xoanoc(a,5,k);
	return 0;
	getch();
}
