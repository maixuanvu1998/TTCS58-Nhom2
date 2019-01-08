#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Taomangngaunhien(int a[], int &n)
{
	printf("\nHay nhap so phan tu mang:");  scanf("%d", &n);

	for(int i=0;i<n;i++)
		a[i] = rand()%51;	
}

void xuatmang(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%5d", a[i]);
	}
	
}

// ham hoan vi
void Hoanvi(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}


// ham dieu chinh heap
void Heapify(int a[], int n, int i)
{
	while(i <= n/2 -1)
	{
		int child1 = 2*i + 1;
		int child2 = 2*i + 2;
		int nut;
		if(child1 < n && a[child1] > a[i])
		nut = child1;
		else
		nut = i;
		if(child2 < n && a[child2] > a[nut])
		nut = child2;
		if(i!=nut)
		{
			Hoanvi(a[i],a[nut]);
			Heapify(a,n,nut);
		}
	}
}

/*
– T?t c? các ph?n t? trên m?ng có ch? s? [n/2] d?n [n – 1] d?u là node lá
– M?i node lá du?c xem là Heap có duy nh?t 1 ph?n t?
– Th?c hi?n thao tác Heapify trên các ph?n t? có ch? s? t? [n/2 – 1] => 0 ta s? t?o du?c 1 Heap có n ph?n t?
*/
// ham xay heap

void BuildHeap(int a[], int n)
{
	for(int i = n/2 -1; i>=0; i--)	
	Heapify(a,n,i);
}

// heap sort
void Heapsort(int a[], int n)
{
	BuildHeap(a, n);
	for(int i=n-1;i>0;i--)
	{
		Hoanvi(a[0], a[i]);
		Heapify(a,i,0);
	}
}


int main() 
{
	// KHai bao mang
	int a, b, n;
	int array[10];
	
//	srand(time(NULL));
	//printf("a = %d\n", rand()%100);
//	printf("b = %d\n", rand()%51);
	
	// tqo mqng...
	Taomangngaunhien(array,n);
	printf("\nMang sau khi nhap la:");
	xuatmang(array, n);
	printf("\nSap xep theo head sort:");
	Heapsort(array,n);
	xuatmang(array, n);
	
	
	
	
	return 0;
}
