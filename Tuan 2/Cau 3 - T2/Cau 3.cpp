#include <Windows.h>
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <vector>
# include <fstream>
# include <stdlib.h>
# include <math.h>
using namespace std;
ifstream f("input3.txt");
class Nhanvien{
	private:
		string Maso, Hoten, chucvu;
		int hesoluong, hesochucvu, thang, nam;
		int luongcb;
		friend class DSNV;
	public:
		void Nhap()
		{
			string s;
			getline(f, s); Maso = s;
			getline(f, s); Hoten = s;
			getline(f, s); hesoluong = atoi(s.c_str());
			getline(f, s); chucvu = s;
			getline(f, s); hesochucvu = atoi(s.c_str());
			getline(f, s); thang = atoi(s.c_str());
			getline(f, s); nam = atoi(s.c_str());
			luongcb = 10000;
		}
		int Luong()
		{
			return luongcb * (hesoluong + hesochucvu);
		}
		void Xuat()
		{
			cout<<Maso<<" "<<Hoten<<" "<<hesoluong<<" "<<chucvu<<" "<<hesochucvu<<" "<<thang<<" "<<nam<<endl;
			cout<<"Luong: "<<Luong()<<endl;
		}
		
};
class DSNV{
	private:
		int n;
		vector <Nhanvien> dsnv;
	public:
		void NhapDS()
		{
			if (f.fail())
				cout << "Failed to open this file!" << endl;
			else
			{
				string s;
				getline(f, s); n = atoi(s.c_str());
				dsnv.resize(n);
				for (int i = 0; i < dsnv.size(); i++)
					dsnv[i].Nhap();
			}
		}
		void XuatDS()
		{
			for (int i = 0; i < dsnv.size(); i++)
			{
					dsnv[i].Xuat();
					cout<<endl;
			}
		}
		void Sapxepluong()
		{
			for (int i = 0; i < dsnv.size() - 1; i++)
				for (int j = i + 1; j < dsnv.size(); j++)
					if (dsnv[i].Luong() > dsnv[j].Luong())
						swap (dsnv[i],dsnv[j]);
		}
		void Timkiem ()
		{
			string ms;
			cout<<"Nhap ma so nhan vien can tim: ";
    		getline(cin, ms);
			for (int i = 0; i < dsnv.size(); i++)
				if (dsnv[i].Maso == ms)
				{
					dsnv[i].Xuat();
					break;
				}
		}
		void Xoa()
		{
			string ms;
			cout<<"Nhap ma so nhan vien can xoa: ";
    		getline(cin, ms);
    		for (int i = 0; i < dsnv.size(); i++)
				if (dsnv[i].Maso == ms)
				{
					dsnv.erase(dsnv.begin() + i);
					break;
				}
		}
};

int main() {
	DSNV ds;
	ds.NhapDS();
	ds.Sapxepluong();
	ds.XuatDS();
	ds.Timkiem();
	cout<<endl;
	ds.Xoa();
	cout<<endl<<"Danh sach nhan vien sau khi xoa: "<<endl;
	ds.XuatDS();
}
