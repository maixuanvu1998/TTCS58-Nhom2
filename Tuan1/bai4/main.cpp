#include <iostream>
#include <stdlib.h>
#include "heapsort.h"


using namespace std;




int main() {
    int n = 70;
    int arr[n];

    taoNgauNhien(arr, n);
    xuatMang(arr, n);
    cout << "=======" << endl;
    heapSort(arr, n);
    xuatMang(arr, n);
}




/*


34 37 28 16 44 36 37 43 50 22
                34
           37         28
        16    44      36    37
      43 50 22  13

                50
           44         37
        43    34     36    28
      37 16 22  13

//===========chinh 1 head tu tren xuong=======

    vtTrai = goc * 2 + 1;
    vtPhai = goc * 2 + 2;
    vtLonNhat = goc
    if ( vtTrai < slPhanTu && vtTrai[] > vtlonNhat[] )
        vtLonNhat = vtTrai
    if ( vtPhai < slPhanTu && vtPhai[] > vtlonNhat[])
        vtLonNhat = vtPhai

    if (vtlonNhat != i) {
        swap(goc[], vtLonNhat[])

        lap(arr, n, vtLonNhat
    }

//===========xay duong heap::chinh head tu node be nhat len====

    for (i = n/2 - 1; i >= 0; i--) {
        head(arr, n, i);
    }


*/
