#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct domino {
    int tren, duoi;
};

int n; // so luong con co
int tt[28]; // trang thai cac quan co
domino arr[28]; // du lieu cac con co
int ttluu[28]; // luu trang thai cac quan co
int chenhlech = 168;// bien chua do chenh lech

// ====prototype====
void readFile(string path, int &n);
void writeFile(string path);
void xuatMangDomino(domino arr[],int n);
void xuatMang2(int arr[], int n);
void kiemTra();
void thuBoTri(int i);
void kqua();
int soLanXoay();




int main() {
    string pathInput = "input.txt", pathOutput = "output.txt";
    readFile(pathInput, n);
    thuBoTri(0);
    kqua();
    writeFile(pathOutput);
    return 0;
}


// ====function====

void xuatMangDomino(domino arr[],int n) {
    for (int i = 0 ;i < n ; i++) {
        cout << arr[i].tren << endl;
        cout << arr[i].duoi << endl;
    }
    cout << "======" << endl;
}

void xuatMang2(int arr[], int n) {
    for (int i = 0 ;i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "======" << endl;
}

void readFile(string path, int &n) {
    ifstream infile;
    infile.open(path);
    int i = 0;
    n = 0;
    if (infile.fail()) {
        cout << "Your file didn't work." << endl;
    } else {
        infile >> n;
        // dung khi het file

        while(!infile.eof()) {
            infile >> arr[i].tren;
            infile >> arr[i].duoi;
            i++;
        }
    }

    infile.close();




/*
    ifstream infile;
    infile.open("input.txt");
    if (infile.fail()) {
        cout << "Your file didn't work." << endl;
    } else {
        string s;
        // infile>>s line by line

        while(getline(infile, s)) {
            cout << s << endl;
        }
        infile.close();
    }

    int x, y;
    inFile
*/
}

void writeFile(string path) {
    ofstream outfile;
    outfile.open(path);
    outfile << chenhlech << " " << soLanXoay();
    outfile.close();
}

void kiemTra() {
    int k;
    int sumt= 0, sumd = 0;
    int dochenh;
    for (k = 0; k < n ; k++) {
        if (tt[k] == 0) {
            sumt = sumt + arr[k].tren;
            sumd = sumd + arr[k].duoi;
        }
        else {
            sumt = sumt + arr[k].duoi;
            sumd = sumd + arr[k].tren;
        }
    }

    dochenh = abs(sumt - sumd);
    if (dochenh < chenhlech) {
        chenhlech = dochenh;
        for (k = 0; k < n; k++)
            ttluu[k] = tt[k];
    }
}

void thuBoTri(int i) {
    int k;
    for (k = 0; k <= 1; k++) {
        tt[i] = k;
        if (i < n) thuBoTri(i+1);
        else
            kiemTra();
        tt[i] = 0;
    }

}

int soLanXoay() {
    int dem = 0;
    for (int i = 0 ; i < n; i++) {
        if (ttluu[i])
            dem++;
    }
    return dem;
}

void kqua() {
    cout << "Do chech lech: " << chenhlech << endl;
    int dem = 0;
    for (int i = 0 ; i < n; i++) {
        if (ttluu[i])
            dem++;
    }
    cout << "so lan xoay: " << soLanXoay() << endl;
    xuatMang2(ttluu, n);
}
