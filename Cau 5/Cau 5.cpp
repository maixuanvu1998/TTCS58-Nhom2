#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("test5.txt", ifstream::in);
ofstream g("test5-output.txt", ifstream::out);
int mi, count;
int sumup = 0, sumdown = 0;
int mincount = 0;
//Khai bao du lieu kieu struct
struct domino{
	int up, down, status;
};
//Tim do lech nho nhat va so quan can quay it nhat de co do lech do
void DominoRotate (domino a[20], int n, int i)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i].status = j;
		if (i == n - 1)
		{
			count = 0;
			sumup = 0, sumdown = 0;
			for (int k = 0; k < n; k++)
			{
				if (a[k].status == 0)
				{
					sumup += a[k].up;
					sumdown += a[k].down;
				}
				else
				{
					sumup += a[k].down;
					sumdown += a[k].up;
					count++;
				}
			}
			if (mi >= abs(sumup-sumdown))
			{
				if (mi == abs(sumup-sumdown))
				{
					if (mincount >= count)
						mincount = count;
				}
				else
					mincount = count;				
				mi = abs(sumup-sumdown);
				
			}
		}
		else
			DominoRotate(a,n,i+1);
	}
}
//Liet ke cac cach sap xep de co do lech nho nhat voi so quan domino can quay it nhat
void List (domino a[20], int n, int i)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i].status = j;
		if (i == n - 1)
		{
			count = 0;
			sumup = 0, sumdown = 0;
			for (int k = 0; k < n; k++)
			{
				if (a[k].status == 0)
				{
					sumup += a[k].up;
					sumdown += a[k].down;
				}
				else
				{
					sumup += a[k].down;
					sumdown += a[k].up;
					count++;
				}
			}
			if (abs(sumup-sumdown) == mi && count == mincount)
			{
				for (int k = 0; k < n; k++)
					cout<<a[k].status<<" ";
				cout<<endl<<endl;
			}
		}
		else
			List(a,n,i+1);
	}
}
int main()
{
	int n;
	f >> n;
	domino a[20];
	mi = 6*n - n;
	for (int i = 0; i < n; i++)
	{
		f >> a[i].up;
		f >> a[i].down;
	}
	DominoRotate(a,n,0);
	g <<mi<<"\t"<<mincount;
	List(a,n,0);
}
