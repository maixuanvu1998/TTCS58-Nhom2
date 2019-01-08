#include <iostream>
#include <string.h>
#define	luongcb 5000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nhanvien{
	char msnv[10];
	char htnv[20];
	float hsl;
	char chucvu[10];
	int thang, nam;
	float hscv;
};


struct bangluong{
	nhanvien nv;
	float luong;
};

void inthongtin(struct nhanvien nv)
{
	printf("\nMa so nhan vien la: %s", nv.msnv);
	printf("\nHo ten nhan vien la: %s", nv.htnv);
	printf("\nChuc vu nhan vien la: %s", nv.chucvu);
	printf("\nHe so luong nhan vien la: %0.2f", nv.hsl);
	printf("\nHe so chuc vu nhan vien la: %0.2f", nv.hscv);
	printf("\nNam la: %d", nv.nam);
	printf("\nThang la: %d", nv.thang);
	
}

void tinhluong(struct nhanvien nv, struct bangluong &bl)
{
	float luong;
	luong = luongcb * (nv.hsl+nv.hscv);
	bl.luong = luongcb * (nv.hsl+nv.hscv);
	
	
}



int main(int argc, char** argv) {
	
	struct nhanvien Nhanvien[3]; //Nhanvien[0]
	struct bangluong bl[3];
	
	//struct nhanvien Nhanvien1;
	struct nhanvien Nhanvien2;
	struct nhanvien Nhanvien3;
	
	
	strcpy(Nhanvien[0].msnv, "58130534");
	strcpy(Nhanvien[0].htnv, "Mai Xuan Vu");
	strcpy(Nhanvien[0].chucvu, "Truongphong");
	Nhanvien[0].hsl = 6.3;
	Nhanvien[0].hscv = 2.0;
	Nhanvien[0].nam = 2019;
	Nhanvien[0].thang = 1;
	
	strcpy(Nhanvien2.msnv, "58130544");
	strcpy(Nhanvien2.htnv, "Tran Chi Bao");
	strcpy(Nhanvien2.chucvu, "Nhanvien");
	Nhanvien2.hsl = 3.3;
	Nhanvien2.hscv = 1.0;
	Nhanvien2.nam = 2019;
	Nhanvien2.thang = 1;
	
	strcpy(Nhanvien3.msnv, "58137524");
	strcpy(Nhanvien3.htnv, "Vu Ngoc Anh");
	strcpy(Nhanvien3.chucvu, "Phophong");
	Nhanvien3.hsl = 4.8;
	Nhanvien3.hscv = 1.5;
	Nhanvien3.nam = 2019;
	Nhanvien3.thang = 1;
	printf("\nThong tin nhan vien 1:");
	inthongtin(Nhanvien[0]);
	printf("\n\n");
	printf("\nThong tin nhan vien 2:");
	
	inthongtin(Nhanvien2);
	printf("\n\n");
	printf("\nThong tin nhan vien 3:");
	
	inthongtin(Nhanvien3);
	printf("\n\n");
	
	printf("\nLuong cua nhan vien 1 la :");	
	tinhluong(Nhanvien[0], bl[0]);	
	printf("%.2f", bl[0].luong); 
	printf("\n\n");
	
	printf("\nLuong cua nhan vien 2 la: ");
	//tinhluong(Nhanvien2);
	printf("\n\n");
	
	printf("\nLuong cua nhan vien 3 la: ");
	//tinhluong(Nhanvien3);
	

	return 0;
}
