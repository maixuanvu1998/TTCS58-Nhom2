#include <iostream>

using namespace std;



int taoNgauNhien(int arr[], int n) {
    n = 3 * 3;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

}

void xuatMang(int arr[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = i*m; j < i*m + m; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

void xuatMang2(int arr[], int n, int m) {
    for (int i = 0; i < n*m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void xoaDongi1(int arr[], int n, int x) {
    for (int i = x; i < n; i++) {
        for (int j = i*n; j < i*n +n; j++) {
            arr[j] = arr[j+n];
        }
    }
}

void xoaDongi2(int arr[], int &n, int &m, int x) {
    for (int i = x; i < n; i++) {
        for (int j = i*m; j < i*m +m; j++) {
            arr[j] = arr[j+m];
        }
    }
    n--;
}

void xoaCotj1(int arr[], int &n, int &m, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = i*n + x; j < i*n + n - 1; j++) {
            arr[j] = arr[j+1];
        }
    }
    m--;
}

void xoaCotj2(int arr[], int &n, int &m, int x) {

    //loop from x to n*m
    //this loop will delete 1 element => i+= m-1
    for (int i = x; i < n*m; i+=(m-1)) {
        // push all emement back to i
        for (int j = i; j < n*m-1; j++) {
            arr[j] = arr[j+1];
            //xuatMang2(arr, n, m);
        }
    }
    m--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    taoNgauNhien(arr, n);


    int n = 3;
    int m = 3;
    xoaDongi2(arr, n, m, 1);
//    xoaCotj2(arr, n, m, 0);
    cout << "==========" << endl;

    xuatMang(arr, n, m);
}
