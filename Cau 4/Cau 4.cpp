#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
ifstream f("test4.txt", ifstream::in);
void ChinhHeap (int a[100], int n, int i)
{
	while (i <= n/2 - 1)
	{
		int c1 = 2*i + 1;
		int c2 = 2*i + 2;
		int lc = c1;
		if (c2 < n && a[c2] > a[lc])
			lc = c2;
		if (a[i] < a[lc])
			swap(a[i],a[lc]);
		i = lc;
	}
}
void XayHeap (int a[100], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		ChinhHeap(a,n,i);
}
void HeapSort (int a[100], int n)
{
	XayHeap(a,n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0],a[i]);
		ChinhHeap(a,i,0);
	}
}
int main()
{
	int n;
	int a[100];
	f >> n;	
	cout<<"1. Nhap tu file, nhan 1: "<<endl;
	cout<<"2. Nhap ngau nhien, nhan 2: "<<endl;
	int k;
	cin>>k;
	switch(k)
	{
		case 1: 
			for (int i = 0; i < n; i++)
				f >> a[i];
			break;	
		case 2:
			srand(time(0));
			for (int i = 0; i < n; i++)
				a[i] = 1 + rand()%(20-1+1);
			break;
	}	
	cout<<"Truoc khi sap xep: "<<endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout<<endl<<endl;
	cout<<"Sau khi sap xep: "<<endl;
	HeapSort(a,n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
