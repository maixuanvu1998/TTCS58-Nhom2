#include <iostream>

using namespace std;



int taoNgauNhien(int arr[], int n) {
    n = n * n;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

}
void xuatMang(int arr[50][50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void xoaDong(int arr[50][50], int &n, int &m, int x) {
    for (int i = x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i+1][j];
        }
    }
    n--;
}

void xoaCot(int arr[50][50], int &n, int &m, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = x; j < m - 1; j++) {
            arr[i][j] = arr[i][j+1];
        }
    }
    m--;
}

bool doiXung(int arr[50][50], int n, int m) {
    for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i][j] != arr[j][i])
				return 0;
	return 1;
}

bool cheoChinhTren(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];
    p1--, p2--;
    while(p1 >= 0 && p2 >= 0) {
        //cout << "x: " << x << " " << "vt: " << arr[p1][p2] << endl;
        if (x < arr[p1][p2])
            return 0;
        p1--;
        p2--;
    }
    return 1;
}

bool cheoChinhDuoi(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];
    p1++, p2++;
    while(p1 < n && p2 < m) {
        //cout << "x: " << x << " " << "vt: " << arr[p1][p2] << endl;
        if (x < arr[p1][p2])
            return 0;
        p1++;
        p2++;
    }
    return 1;
}


bool cheoPhuTren(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];
    p1--, p2++;
    while(p1 >= 0 && p2 < m) {
        //cout << "x: " << x << " " << "vt: " << arr[p1][p2] << endl;
        if (x < arr[p1][p2])
            return 0;
        p1--;
        p2++;
    }
    return 1;
}

bool cheoPhuDuoi(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];
    p1++, p2--;
    while(p1 < m && p2 >= 0) {
        //cout << "x: " << x << " " << "vt: " << arr[p1][p2] << endl;
        if (x < arr[p1][p2])
            return 0;
        p1++;
        p2--;
    }
    return 1;
}

bool ngangDoc(int arr[50][50], int n, int m, int p1, int p2) {

    int x = arr[p1][p2];

    // ngang
    for (int i = p2 - 1; i >= 0 ; i--) {
        if (x < arr[p1][i])
            return 0;
    }
    for (int i = p2 + 1; i < m ; i++) {
        if (x < arr[p1][i])
            return 0;
    }

    // doc
    for (int i = p1 - 1; i >= 0; i--) {
        if (x < arr[i][p2])
            return 0;
    }
    for (int i = p1 + 1; i < n; i++) {
        if (x < arr[i][p2])
            return 0;
    }

    return 1;
}



void soHoangHau(int arr[50][50], int n, int m) {
    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            if (ngangDoc(arr, n, m, i, j) && cheoChinhTren(arr, n, m, i, j) && cheoChinhDuoi(arr, n, m, i, j) && cheoPhuTren(arr, n, m, i, j) && cheoPhuDuoi(arr, n, m, i, j)) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int arr[50][50] = {
        {2, 2, 7},
        {2, 1, 6},
        {5, 6, 2}
    };
    int n = 3, m = 3;
    //xoaCot(arr, n, m, 1);
    //cout << "doi xung: " << doiXung(arr, n, m) << endl;
    //cout << "check: " << ngangDoc(arr, n, m, 2, 2) << endl;
    soHoangHau(arr, n, m);

    xuatMang(arr, n, m);
}
