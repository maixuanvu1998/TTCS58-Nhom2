#ifndef LIBHEAPSORT_H_INCLUDED
#define LIBHEAPSORT_H_INCLUDED



#endif // LIBHEAPSORT_H_INCLUDED
using namespace std;


// ============= function =============
int taoNgauNhien(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

}

void xuatMang(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
}

void chinhHeap(int arr[], int n, int root) {
    int pLeft = root * 2 + 1;
    int pRight = root * 2 + 2;
    int pTmp = root;

    if (pLeft < n && arr[pLeft] > arr[pTmp])
        pTmp = pLeft;
    if (pRight < n && arr[pRight] > arr[pTmp])
        pTmp = pRight;
    if (pTmp != root) {
        swap(arr[pTmp], arr[root]);

        chinhHeap(arr, n, pTmp);
    }
}

void xayDungHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        chinhHeap(arr, n, i);
    }
}
void heapSort(int arr[], int n) {
    xayDungHeap(arr, n);
    for (int i = n -1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        chinhHeap(arr, i, 0);
    }
}
