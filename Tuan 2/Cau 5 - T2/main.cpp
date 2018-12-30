#include <stdio.h>
#include <math.h>
#include <winbgim.h>
#include <iostream>
#include <string.h>
using namespace std;
int Mx, My;
void Oxy()
{
	setcolor(15);
	line(0,My/2,Mx,My/2);	//Ox
	line(Mx/2,0,Mx/2,My);	//Oy
}
class Toado{
	protected:
		int x, y;
		friend class Duongthang;
		friend class Chunhat;
		friend class Vuong;
		friend class Tron;
		friend class Tamgiac;
	public:
		void Nhap(){
			cout<<endl<<"Toa do x: ";
			cin>>x;
			cout<<"Toa do y: ";
			cin>>y;
		}
};
class Duongthang{
	private:
		Toado a,b;
	public:
		void NhapDT(){
			cout<<"Toa do diem thu nhat: ";
			a.Nhap();
			cout<<"Toa do diem thu hai: ";
			b.Nhap();
		}
		void DrawDT(){			
			line(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
		}
};
class Chunhat{
	private:
		Toado trentrai, duoiphai;
	public:
		void NhapCN(){
			cout<<"Toa do diem tren trai: ";
			trentrai.Nhap();
			cout<<"Toa do diem duoi phai: ";
			duoiphai.Nhap();
		}
		void DrawCN(){			
			rectangle(trentrai.x+Mx/2, -trentrai.y+My/2, duoiphai.x+Mx/2, -duoiphai.y+My/2);
		}
};
class Vuong{
	private:
		Toado trentrai, duoiphai;
	public:
		void NhapV(){
			do
			{
				cout<<"Toa do diem tren trai: ";
				trentrai.Nhap();
				cout<<"Toa do diem duoi phai: ";
				duoiphai.Nhap();
				if (abs(trentrai.x-duoiphai.x) != abs(trentrai.y-duoiphai.y))
					cout<<"Khong phai hinh vuong"<<endl;
			}
			while (abs(trentrai.x-duoiphai.x) != abs(trentrai.y-duoiphai.y));
		}
		void DrawV(){			
			rectangle(trentrai.x+Mx/2, -trentrai.y+My/2, duoiphai.x+Mx/2, -duoiphai.y+My/2);
		}
};
class Tron{
	private:
		Toado a;
		int r;
	public:
		void NhapT(){
				cout<<"Toa do tam: ";
				a.Nhap();
				cout<<"Nhap ban kinh: ";
				cin>>r;
		}
		void DrawT(){			
			circle(a.x+Mx/2,-a.y+My/2,r);
		}
};
class Tamgiac{
	private:
		Toado a, b, c;
	public:
		void NhapTG(){
				cout<<"Toa do diem thu nhat: ";
				a.Nhap();
				cout<<"Toa do diem thu hai: ";
				b.Nhap();
				cout<<"Toa do diem thu ba: ";
				c.Nhap();
		}
		void DrawTG(){			
			line(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
			line(a.x+Mx/2, -a.y+My/2, c.x+Mx/2, -c.y+My/2);
			line(b.x+Mx/2, -b.y+My/2, c.x+Mx/2, -c.y+My/2);
		}	
};
int main(){
	int key;
	Duongthang dt;
	Tamgiac tg;
	Chunhat cn;
	Vuong v;
	Tron t;
	initwindow(1280, 700);
    cleardevice();
    Mx = getmaxx(), My = getmaxy();
    Oxy();
    cout<<"Nhap key tuong ung de thuc hien ve hinh"<<endl;
    cout<<"1. Ve duong thang"<<endl;
    cout<<"2. Ve tam giac"<<endl;
    cout<<"3. Ve hinh chu nhat"<<endl;
    cout<<"4. Ve hinh vuong"<<endl;
    cout<<"5. Ve hinh tron"<<endl;
    cout<<"0. Ket thuc ve"<<endl;
    do
    {
	    cout<<endl<<"Nhap key: ";
	    cin>>key;
		switch(key)
		{
			case 1:
				setcolor(13);
				dt.NhapDT();
				dt.DrawDT();
				break;
			case 2:
				setcolor(10);
				tg.NhapTG();
				tg.DrawTG();
				break;
			case 3:
				setcolor(9);
				cn.NhapCN();
				cn.DrawCN();
				break;
			case 4:
				setcolor(14);
				v.NhapV();
				v.DrawV();
				break;
			case 5:
				setcolor(12);
				t.NhapT();
				t.DrawT();
				break;
			case 0:
				break;
		}
		delay(1000);
	}
    while (key != 0);	
    while(!kbhit()) delay(1);
    return 0;
}
