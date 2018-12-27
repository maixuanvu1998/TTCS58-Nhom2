#include <iostream>
#include <stdlib.h>
using namespace std;

#include "nhiphan.h"

Node *root, *root2;

int main() {
    khoiTao(root);
    taoCay(root);
    duyetLNR(root);
    cout << endl;
    duyetLNR(root);

    cout << endl << "====================" << endl;
    inNutMuci(root, 2);

    cout << endl << "====================" << endl;
    saoChep(root, root2);
    duyetLNR(root2);

    xoaNut(root, 3);
    cout << endl << "=======da xoa========" << endl;
    duyetLNR(root);
}
