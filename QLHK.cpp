#include<iostream>
#include<string>
#include <conio.h>
using namespace std;


struct CON{
	string manhankhau;
	string hoten;
	string gioitinh;
	CON *cnext;
};

struct XE{
	string soxe;
	string hieuxe;
	string loaixe;
	XE *xnext;

};
struct HOKHAU{
	string sohokhau;
	string manhankhau;
	string tenchuho;
	string diachi;
	HOKHAU *hknext;

	CON *con;
	XE *xe;
	
};
//----------------------------------------------------------

void khoitaohokhau(HOKHAU *&dau)
{
	dau = NULL;
}

//-----------------------------------------------------------
void NHAPCON(CON *&dau)
{
	CON *p, *q =new CON;
	string manhankhau1;
	do{
		p = new CON;
		cout<<endl<< "nhap ma nhan khau(con): ";
		getline(cin,manhankhau1);
		if(manhankhau1.compare("\0") !=0)
		{
			p->manhankhau = manhankhau1;
			cout<<endl<<"nhap ho ten (con): ";
			getline(cin,p->hoten);
			cout<<endl<<"nhap gioi tinh(con): ";
			getline(cin,p->gioitinh);
			p->cnext = NULL;
			
			if(dau == NULL)
			{
				dau = p;
			}
			else
			{
				q->cnext = p;
			}
			q= p;
		}
	}while(manhankhau1.length()!=0);
}

void NHAPXE(XE *&dau)
{
	XE *p, *q =new XE;
	string soxe1;
	do{
		
		cout<<"nhap so xe";
		getline(cin,soxe1);
		if(soxe1.compare("\0")!=0)
		{
			p = new XE;
			p->soxe=soxe1;
			cout<<endl<<"nhap loai xe";
			getline(cin,p->loaixe);
			cout<<endl<<"nhap hieu xe: ";
			getline(cin,p->hieuxe);
			
			p->xnext = NULL;
			if(dau == NULL) 
			{
				dau = p;
			}
			else
			{
				q->xnext = p;
			}
		q = p;
		}
	}while(soxe1.length() !=0) ;
}


void NHAPHK(HOKHAU *&dau)
{
	HOKHAU *p, *q =new HOKHAU;
	string hktam;
	do{
		cout<<"nhap so ho khau chu ho, enter de dung: ";
		getline(cin,hktam);
		if(hktam.length() != 0)
		{
			p = new HOKHAU;
			p->sohokhau = hktam;
			cout<<endl<<"nhap ma nhan khau chu ho:";
			getline(cin,p->manhankhau);
			cout<<endl<<"nhap ten chu ho: ";
			getline(cin,p->tenchuho);
			cout<<endl<<"nhap dia chi:";
			getline(cin,p->diachi);
			p->hknext = NULL;
			p->xe = NULL;
			p->con = NULL;
			
			NHAPCON(p->con);
			NHAPXE(p->xe);
			if(dau == NULL) dau = p;
			else  q->hknext = p;
			q = p;
			
		}
	}while(hktam.length() !=0);
}


void hienThiCon(CON *p)
{
	
		
		cout<<endl<<"ho ten con: "<<p->hoten;
		cout<<endl<<"ma nhan khau con: "<<p->manhankhau;
		cout<<endl<<"gioi tinh con: "<<p->gioitinh;
		
	
}
void hienThiHK(HOKHAU *p)
{
	
		cout<<endl<<"===========Chu Ho==========";
		cout<<endl<<"ma nhan khau: "<< p->manhankhau;
		cout<<endl<<"so ho khau: "<<p->sohokhau;
		cout<<endl<<"ten chu ho: "<<p->tenchuho;
		cout<<endl<<"dia chi: "<<p->diachi;
}
void inDSThanhVien(HOKHAU *dau, string sohokhau)
{
	if(dau != NULL)			//TH ds co du lieu
	{
		HOKHAU *p = new HOKHAU;
		p = dau;
		
		while(p != NULL && p->sohokhau.compare(sohokhau) != 0)
		{
			p = p->hknext;
		}
		if(p != NULL)
		{
			hienThiHK(p);							//neu tim duoc so ho khau thi hien thong tin thanh vien cua ho
			hienThiCon(p->con);
		}
		else cout<<"Khong tim thay so ho khau yeu cau";	//khong tim thay so ho khau

	}
	else cout<<"chua co du lieu";
}



void timXe(HOKHAU *dau,string hangxe)
{
	
	HOKHAU *p = new HOKHAU;
	XE *q = new XE;
	p = dau;
	q= dau->xe;
	
	while( p != NULL)
	{
	
		while(q != NULL && q->hieuxe.compare(hangxe) !=0)
		{
			q = q->xnext;
		
		}
	
		if(q!= NULL ) 
		{
		
			break;
		}
	
		p = p->hknext;
		q=p->xe;
	}
	if(q ==NULL) 
	cout<<endl<<"khong tim thay xe";
	else 	hienThiHK(p);

}
void hienThiXe(HOKHAU *p)
{
	XE *q = new XE;
	q = p->xe;
	while( q != NULL)
	{
		cout<<endl<<"So xe : "<<q->soxe;
		cout<<endl<<"Hieu xe : "<<q->hieuxe;
		cout<<endl<<"loai xe : "<<q->loaixe;
		q = q->xnext;
	}
	
}
void xoaXe(HOKHAU *dau, string soxe)
{
	HOKHAU *p = new HOKHAU;
	XE *q = new XE;
	XE *z = new XE;
	p= dau;
	q= p->xe;

	
	while(p!= NULL)
	{
	
		while(q != NULL && q->soxe.compare(soxe) != 0)
		{
			q= q->xnext;	
		}
		if(q != NULL) 
		{
			if(q == p->xe)
			{
			
				p->xe = q->xnext;
			
			}
			else
			{
			//xoa xe o vi tri khac dau ds
				z = p->xe; 
				while(z->xnext != q)
				{
				
					z = z->xnext;
				}
				
				z->xnext  = q->xnext;
			}
			break;
		}
	
	p = p->hknext;
	q = p->xe;
	}
	if(p == NULL) cout<< "khong tim thay xe can xoa";
	else
	{
		hienThiHK(p);
		hienThiXe(p);
	}
	
}


int main()
{
	HOKHAU *hk1;
	khoitaohokhau(hk1);
	NHAPHK(hk1);
	
	string sohokhau;
	cout<<endl<<"\n\n nhap vao so ho khau can tim";
	getline(cin,sohokhau);
	inDSThanhVien(hk1,sohokhau);
	
	string hangxe;
	cout<<endl<<"\n\n nhap vao hang xe: ";
	getline(cin,hangxe);
	timXe(hk1,hangxe);
	
	string soxe;
	cout<<endl<<"nhap vao so xe can xoa:";
	getline(cin,soxe);
	xoaXe(hk1,soxe);
}
