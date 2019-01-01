#include <iostream>

using namespace std;



int taoNgauNhien(int arr[], int n) {
    n = 3 * 3;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

}

void xuatMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i*n; j < i*n + n; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

void xoaDongi(int arr[], int n, int x) {

}

void xoaDongj(int arr[], int n, int x) {

}

int main() {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    taoNgauNhien(arr, 3);
    xuatMang(arr, 3);
}
