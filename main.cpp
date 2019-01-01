#include <iostream>
#include<stdio.h>
#include"songuyen.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[100],n=5;
	nhapso(a,n);
	int tong = phepcong(a,n);
	printf("\ntong cac so nguyen : %d ",tong);
	int hieu = pheptru(a,n);
	printf("\nhieu cac so nguyen : %d ",hieu);
	int nhan = phepnhan(a,n);
	printf("\nnhan cac so nguyen : %d ",nhan);
	return 0;
}
