#ifndef LIBBAI2_H_INCLUDED
#define LIBBAI2_H_INCLUDED



#endif // LIBBAI2_H_INCLUDED
using namespace std;

struct Xe {
    string soXe, loaiXe, hieuXe;
    Xe *tiep;
};

struct Con {
    string maNhanKhau, hoTen, gioiTinh;
    Con *tiep;
};

struct HoKhau {
    string soHoKhau, maNhanKhauChuHo, tenChuHo, diaChi;
    Xe *xe;
    Con *con;
    HoKhau *hktiep;
};



void khoiTao(HoKhau *&dauHoKhau) {
	dauHoKhau = NULL;
}

void nhapDSC (Con *&dauCon) {
    Con *p, *q;
    string maNhanKhautmp, hoTentmp, gioiTinhtmp;
    cout << "nhap ds con cai:" << endl;
    do {
        cout << "nhap maNhanKhau: (nhap exit de thoat)"<< endl;
        getline(cin, maNhanKhautmp);


        if (maNhanKhautmp != "exit") {
            cout << "nhap hoTen:";
            getline(cin, hoTentmp);
            cout << "nhap gioiTinh:";
            getline(cin, gioiTinhtmp);

            p = new Con;
            p->maNhanKhau = maNhanKhautmp;
            p->hoTen = hoTentmp;
            p->gioiTinh = gioiTinhtmp;


            p->tiep = NULL;

            if(dauCon == NULL)
				dauCon = p;
			else
				q->tiep = p;
			q = p;
        }
    } while (maNhanKhautmp != "exit");
}

void nhapDSX (Xe *&dauXe) {
    Xe *p, *q;
    string soXetmp, hieuXetmp, loaiXetmp;

    cout << "nhap Ds xe: " << endl;
    do {
        cout << "nhap soXe: (nhap exit de thoat)"<< endl;
        getline(cin, soXetmp);


        if (soXetmp != "exit") {
            cout << "nhap hieuXe:";
            getline(cin, hieuXetmp);
            cout << "nhap loaiXe:";
            getline(cin, loaiXetmp);

            p = new Xe;
            p->soXe = soXetmp;
            p->loaiXe = loaiXetmp;
            p->hieuXe = hieuXetmp;


            p->tiep = NULL;

            if(dauXe == NULL)
				dauXe = p;
			else
				q->tiep = p;
			q = p;
        }
    } while (soXetmp != "exit");
}


void nhapDSHK(HoKhau *&dauHoKhau) {
    HoKhau *p, *q;
    string soHoKhautmp, maNhanKhauChuHotmp, tenChuHotmp, diaChitmp;
    do {
        cout << "nhap soHoKhau: (nhap exit de thoat)" << endl;
        getline(cin, soHoKhautmp);

        if (soHoKhautmp != "exit") {

            cout << "nhap maNhanKhauChuHo:";
            getline(cin, maNhanKhauChuHotmp);
            cout << "nhap tenChuHo:";
            getline(cin, tenChuHotmp);
            cout << "nhap diaChi:";
            getline(cin, diaChitmp);

            p = new HoKhau;
            p->soHoKhau = soHoKhautmp;
            p->maNhanKhauChuHo = maNhanKhauChuHotmp;
            p->tenChuHo = tenChuHotmp;
            p->diaChi = diaChitmp;

            p->xe = NULL;
            p->con = NULL;
            p->hktiep = NULL;

            nhapDSX(p->xe);
            nhapDSC(p->con);

            if(dauHoKhau == NULL)
				dauHoKhau = p;
			else
				q->hktiep = p;
			q = p;
        }
    } while (soHoKhautmp != "exit");
 }


 void inXe(Xe *dauXe) {
    Xe *p;
    p = dauXe;
    cout << "=================================" << endl;
    cout << "xuat danh sach xe: " << endl;
    while (p != NULL) {
        cout << "So xe: " << p->soXe << endl;
        cout << "Loai xe: " << p->loaiXe << endl;;
        cout << "Hieu xe: " << p->hieuXe << endl;
        p = p->tiep;
    }
}

 void inCon(Con *dauCon) {
    Con *p;
    p = dauCon;
    cout << "================================="<< endl;
    cout << "xuat danh sach con: " << endl;
    while (p != NULL) {
        cout << "================="<< endl;
        cout << "Ma nhan khau " << p->maNhanKhau << endl;
        cout << "Ho ten: " << p->hoTen << endl;
        cout << "Gioi tinh: " << p->gioiTinh << endl;
        p = p->tiep;
    }
    cout << "================================="<< endl;
}

 void inHoKhau(HoKhau *dauHoKhau) {
    HoKhau *p;
    p = dauHoKhau;
    cout << "DANH SACH CAC HO KHAU && CHI TIET: " << endl;
    while (p != NULL) {
        cout << "So ho khau: " << p->soHoKhau << endl;
        cout << "Ten chu ho: " << p->tenChuHo << endl;;
        cout << "Ma nhan khau chu ho: " << p->maNhanKhauChuHo << endl;
        cout << "Dia chi: " << p->diaChi << endl;
        inXe(p->xe);
        inCon(p->con);
        p = p->hktiep;
    }
 }

void inDSThanhVien(HoKhau *&dauHoKhau, string soHoKhau) {
    HoKhau *p;
    p = dauHoKhau;

    while (p != NULL && p->soHoKhau != soHoKhau) {
        p = p->hktiep;
    }
    cout << "THONG TIN CUA HO CAN XUAT LA: "<< endl;
    cout << "So ho khau: " << p->soHoKhau << endl;
    cout << "Ten chu ho: " << p->tenChuHo << endl;;
    cout << "Ma nhan khau chu ho: " << p->maNhanKhauChuHo << endl;
    cout << "Dia chi: " << p->diaChi << endl;
    inCon(p->con);
}

bool kiemTraXe(HoKhau *&dauHoKhau, string hieuXe) {
    HoKhau *p;
    Xe *q;
    p = dauHoKhau;
    q = NULL;
    bool flag = 0;
    while (p != NULL) {
        q = p->xe;
        while(q != NULL) {
            if (q->hieuXe == hieuXe)
                flag = 1;
            q = q->tiep;
        }
        p = p->hktiep;
    }
    return flag;
}

void xoaDau(HoKhau *&dauHoKhau ,Xe *& dauXe) {
    Xe *p;
    if (dauXe != NULL) {
        p = dauXe;
        dauXe = dauXe->tiep;
        dauHoKhau->xe = dauXe;
        delete p;
    }
}



void xoaXe(HoKhau *&dauHoKhau, string maXe, string soHoKhau) {
    HoKhau *p;
    p = dauHoKhau;
    Xe *q, *t, *dauXe;
    q = NULL;
    dauXe = NULL;
    while (p != NULL) {
        if (p->soHoKhau == soHoKhau) {
            dauXe = p->xe;
            t = p->xe;
            while(t != NULL) {
                if (t->soXe == maXe) {
                    if (t == dauXe) {
                        cout << t->soXe << " this" << endl;
                        xoaDau(p, dauXe);
                        return;
                    } else {
                        q->tiep = t->tiep;
                        delete t;
                        return;
                    }
                }
                q = t;
                t = t->tiep;
            }
        }
        p = p->hktiep;
    }
}
