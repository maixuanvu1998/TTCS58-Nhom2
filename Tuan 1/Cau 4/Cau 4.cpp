#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
ifstream f("test4.txt", ifstream::in);
int m;
void Color(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void xuat1(int a[100], int n, int d, int c1, int c2)
{
	for (int i = 0; i < n; i++)
	{
		if (i == d)
			Color(12);
		else
			if (i == c1)
				Color(10);
			else
				if (i == c2)
					Color(9);
				else
					Color(15);
		cout<<a[i]<<" ";			
	}
	Color(15);
}
void xuatb2(int a[100], int k)
{
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
			Color(13);
		else
			if (i > k)
				Color(11);
			else
				if (i == k)
					Color(14);
				else
					Color(15);
		cout<<a[i]<<" ";
	}
	Color(15);
}
void xuata2(int a[100], int k)
{
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
			Color(13);
		else
			if (i >= k)
				Color(11);			
			else
				Color(15);
		cout<<a[i]<<" ";
	}
	Color(15);
}
void xuat3(int a[100], int n)
{
	for (int i = 0; i < n; i++)
		cout<<a[i]<<" ";
}
void ChinhHeap (int a[100], int n, int i, int flag)
{
	while (i <= n/2 - 1)
	{
		int c1 = 2*i + 1;
		int c2 = 2*i + 2;
		int lc = c1;
		if (flag == 0)
		{
			cout<<"Xac dinh nut cha (vi tri ";
			Color(12);
			cout<<i;
			Color(15);
			cout<<") va cac nut con cua no (vi tri ";
			Color(10);
			cout<<c1;
			Color(15);
			if (c2 < n)
			{
				cout<<" va ";
				Color(9);
				cout<<c2;
				Color(15);
				cout<<"):"<<endl;
			}
			else
				cout<<"):"<<endl;
			xuat1(a,n,i,c1,c2);
		}	
		
		cout<<endl;
		if (c2 < n && a[c2] > a[lc])
			lc = c2;
		if (a[i] < a[lc])
			swap(a[i],a[lc]);
		if (flag == 0)
		{			
			cout<<"Sau khi chinh Heap nut cha: "<<endl;
			xuat1(a,n,i,c1,c2);
		}
		else
		{
			cout<<"Sau khi hoan vi, chinh Heap voi phan con lai trong mang: "<<endl;
			xuata2(a,n);
		}
		cout<<endl<<endl;
		i = lc;
	}
}
void XayHeap (int a[100], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		ChinhHeap(a,n,i,0);
}
void HeapSort (int a[100], int n)
{
	XayHeap(a,n);
	cout<<"Mang co duoc sau khi xay dung heap lan dau tien: "<<endl;
	xuat3(a,n);
	cout<<endl<<endl<<endl;
	for (int i = n - 1; i > 0; i--)
	{
		cout<<"Hoan vi phan tu lon nhat (vi tri ";
		Color(13);
		cout<<"0";
		Color(15);
		cout<<") voi phan tu o vi tri cuoi cung (vi tri ";
		Color(14);
		cout<<i;
		Color(15);
		cout<<"):"<<endl;
		xuatb2(a,i);
		cout<<"--> ";
		swap(a[0],a[i]);
		xuatb2(a,i);
		ChinhHeap(a,i,0,1);
	}
}
int main()
{
	Color(15);
	int n;
	int a[100];
	f >> n;	
	m = n;
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
				a[i] = 1 + rand()%(30-1+1);
			break;
	}	
	cout<<"Truoc khi sap xep: "<<endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout<<endl<<endl;
	HeapSort(a,n);
	Color(15);
	cout<<endl<<endl<<"Sau khi sap xep: "<<endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
