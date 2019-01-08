#include <iostream>
#include <math.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void taomenu(int &a, int &b)
{
	
	printf("\nNhap hai so a va b: ");
	scanf("%d%d", &a, &b);
	while(true)
	{
		//system("cls");
		printf("\t\t\t ============MENU==================================\n");
    	printf("\t\t\t |1. Tong hai so a va b                   	|\n");
    	printf("\t\t\t |2. Hieu hai so a va b               		|\n");
    	printf("\t\t\t |3. Tich hai so a va b                    	|\n");
    	printf("\t\t\t |4. Thoat                                    	|\n");
    	printf("\t\t\t ==================================================\n");
        
		int luachon;
		
		printf("\nNhap lua chon:");
		scanf("%d", &luachon);
		if(luachon==1)
			printf("\nTong a va b la: %d", a+b);
		else if(luachon==2)
			printf("\nTong a va b la: %d", a-b);
		else if(luachon==3)
			printf("\nTong a va b la: %d", a*b);
		else if(luachon==4)
			break;
		else
			printf("\nNhap khong hop le!");		
	}
}

int main(int argc, char** argv) {
	int a, b;
	
	taomenu(a,b);
	system("pause");
	return 0;
}
