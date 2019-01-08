#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


using namespace std;

void nhapmatran(int a[10][10],int &n)
{
	int i, j;
	printf("\nNhap n:");
	scanf("%d", &n);
	while(n<3 || n>10)
	{
		printf("\nSo chieu khong hop le, xin vui long nhap lai kich thuoc ma tran!");
		printf("\nNhap dim:");
		scanf("%d", &n);
	}
	// - T?o ma tr?n g?m có nxn s? nguyên ng?u nhiên trong kho?ng t? 0 d?n 100 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]	= rand()%100;					
}

void inmatran(int a[10][10], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t", a[i][j]);
	printf("\n");
	}
		
}

void inmatransaukhixoacot(int a[10][10], int n)
{
	int i, j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t", a[i][j]);
	printf("\n");
	}
}
void inmatransaukhixoahang(int a[10][10], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
			printf("%d\t", a[i][j]);
	printf("\n");
	}		
}

void xoa_cot(int a[10][10], int n)
{
	int col;
	int i, j;
	printf("\nNhap cot can xoa:");
	scanf("%d", &col);
	for(j=col;j<n-1;j++)
	{
		for(i=0;i<n;i++)
			a[i][j]= a[i][j+1];
	}
	n--;
	inmatransaukhixoacot(a,n);
}
void xoa_hang(int a[10][10], int n)
{
	int line;
	int i, j;
	printf("\nNhap hang can xoa:");
	scanf("%d", &line);
	for(i=line;i<n-1;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]= a[i+1][j];
	}
	n--;
	inmatransaukhixoahang(a,n);
	
}

int kiemtradoixung(int a[10][10], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(a[i][j]=!a[j][i])
			{
				//ma tran khong doi xung neu ton tai 1 phan tu khong thoa man tinh doi xung
				return 0;
			}
	}
	// ma tran co doi xung
	return 1; 
}

int kiemtrahoanghau(int a[10][10], int pt, int hang, int cot, int n)
{
	int i, j;
	
	// kiem tra tren dong thu 'hang'
	for(j=0;j<n;j++)
	{
		if(pt < a[hang][j])
			//khong phai la hoang hau
			return 0;
	}
	// kiem tra tren cot thu 'cot'
	for(i=0;i<n;i++)
	{
		if(pt < a[i][cot])
			//khong phai la hoang hau
			return 0;
	}
	// kiem tra tren dong thu 'hang'
	for(j=0;j<n;j++)
	{
		if(pt < a[hang][j])
			//khong phai la hoang hau
			return 0;
	}
	
	
	// la phan tu hoang hau
	return 1; 
}

int main(int argc, char** argv) {
	int a[10][10];
	int n;
	int dx, hh;
	
	nhapmatran(a, n);
	inmatran(a,n);
	// xoa hang nhap tu ban phim
	xoa_hang(a,n);
	// xoa cot nhap tu ban phim
	xoa_cot(a,n); 

	// Kiem tra mt doi xung?
	dx = kiemtradoixung(a,n);
	
	if(dx == 1)
		printf("\nMa tran la doi xung");
	else
		printf("\nMatran khong doi xung");
		
	hh = kiemtrahoanghau(a, a[2][2],2,2,n);
	
	if(hh == 1)
		printf("\nSo do la hoang hau");
	else
		printf("\nSo do khong la hoang hau");
	return 0;
}
