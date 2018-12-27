# include <stdio.h>
# include <iostream>
# include <fstream>
using namespace std;
ifstream f("test1.txt", ifstream::in);
ofstream g("test1-output.txt", ifstream::out);
void east (int a[10][10], int &n, int &i, int &j, int &count, int M);
void south (int a[10][10], int &n, int &i, int &j, int &count, int M);
void west (int a[10][10], int &n, int &i, int &j, int &count, int M);
void north (int a[10][10], int &n, int &i, int &j, int &count, int M);
int main()
{
	int n;
	f >> n;
	int a[10][10];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			f >> a[i][j];
		}
	cout<<n<<endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)		
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	int i = 0, j = 0, count = 0;
	int M = n;
	east(a,n,i,j,count,M);
	f.close();
	g.close();
}
void east (int a[10][10], int &n, int &i, int &j, int &count, int M)
{
	while (j < n)
	{
		g <<a[i][j]<<" ";
		j++;
		count++;
	}
	if (count != M*M)
	{
		j--;
		i++;
		south(a,n,i,j,count,M);
	}
}
void south (int a[10][10], int &n, int &i, int &j, int &count, int M)
{
	while (i < n)
	{
		g <<a[i][j]<<" ";
		i++;
		count++;
	}
	if (count != M*M)
	{
		i--;
		j--;
		west(a,n,i,j,count,M);
	}
}
void west (int a[10][10], int &n, int &i, int &j, int &count, int M)
{
	while (j >= M-n)
	{
		g <<a[i][j]<<" ";
		j--;
		count++;
	}
	if (count != M*M)
	{
		j++;
		i--;
		north(a,n,i,j,count,M);
	}
}
void north (int a[10][10], int &n, int &i, int &j, int &count, int M)
{
	n--;
	while (i >= M-n)
	{
		g <<a[i][j]<<" ";
		i--;
		count++;
	}
	if (count != M*M)
	{
		i++;
		j++;
		east(a,n,i,j,count,M);
	}
}

