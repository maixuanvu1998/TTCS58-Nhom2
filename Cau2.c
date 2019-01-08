#include <stdio.h>
#include <conio.h>
#include <string.h>

struct con {
	char msc[9];
	char htc[30];
	char gt[4];
	con *tc;
};

struct xe {
	char soxe[12];
	char loaixe[6];
	char hangsx[15];
	xe *tx;
};

struct ho {
	char mh[6];
	char msnk[9];
	char hovaten[30];
	char dc[30];
	xe *dsxe;
	con *dsc;
	ho *th;	
};

ho *dau;

void khoitao(ho *&dau)
{
	dau=NULL;
}

void nhapcon(con *&dc)
{
	char msct[9]; char htct[30]; char gtt[4];
	con *p, *q;
	do
	{
		printf("\nNhap ma so con");
		fflush(stdin); gets(msct);
			if (strcmp(msct,"\0")!=0)
			{
				p= new con;
				strcpy(p->msc,msct);
				printf("\n Nhap ho ten con:");
				fflush(stdin); gets(htct);
				printf("\n Nhap gioi tinh con:");
				fflush(stdin); gets(gtt);
				strcpy(p->htc,htct);
				strcpy(p->gt,gtt);
				p->tc=NULL;
				
					if(dc==NULL)
						dc=p;
					else
						q->tc=p;
						q=p;	
			}
	}
	while (strcmp(msct,"\0")!=0);
}
void nhapxe(xe *&dx)
{
	char soxet[12]; char loaixet[6]; char hangsxt[15];
	xe *p, *q;
	do
	{
		printf("\nNhap  so xe");
		fflush(stdin); gets(soxet);
			if (strcmp(soxet,"\0")!=0)
			{
				p= new xe;
				strcpy(p->soxe,soxet);
				printf("\n Nhap loai xe:");
				fflush(stdin); gets(loaixet);
				printf("\n Nhap hang san xuat:");
				fflush(stdin); gets(hangsxt);
				strcpy(p->loaixe,loaixet);
				strcpy(p->hangsx,hangsxt);
				p->tx=NULL;
				
					if(dx==NULL)
						dx=p;
					else
						q->tx=p;
						q=p;	
			}
	}
	while (strcmp(soxet,"\0")!=0);
}


void nhapho()
{
	char mht[6];
	char msnkt[9];
	char hovatent[30];
	char dct[30];
	ho *p, *q;
do
{
	printf("\n Nhap So ho khau: ");
	fflush(stdin); get(mht);
		if (strcmp(mht, "\0")!=0)
		{
			p = new ho;
			strcpy(p->mh,mht);
			printf("\n Nhap Ma chu ho: ");
			fflush(stdin); get(msnkt);
			printf("\n Nhap Ho va ten chu ho: ");
			fflush(stdin); get(hovatent);
			printf("\n Nhap Dia chi: ");
			fflush(stdin); get(dct);
				strcpy(p->msnk,msnkt);
				strcpy(p->hovaten,hovatent);
				strcpy(p->dc,dct);
				p->dsc = NULL; p->dsxe =NULL;
			printf("\n Nhap xe: \n");
				nhapxe(p->dsxe);
			printf("\n Nhap con: \n");
				nhapcon(p->dsc);
			if(dsh==NULL)
				dsh=p;
			else
				q->th=p;
				q=p;						
		}
}
while (strcmp(mht,"\0")!=0);
	
	
}



int main()
{
	khoitao(dau);
	nhapho(dau);
	printf("\n Nhap xong du lieu \n");
	getch();
}
