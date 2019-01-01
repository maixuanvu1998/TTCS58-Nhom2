#ifndef LIBNHIPHAN_H_INCLUDED
#define LIBNHIPHAN_H_INCLUDED



#endif // LIBNHIPHAN_H_INCLUDED
using namespace std;

struct nut {
	int info;
	nut *left, *right;
};
typedef nut Node;


void khoiTao(Node *&root) {
	root = NULL;
}

void mocNut(Node *&root, int x) {
	if(root == NULL) {
		root = new Node;
		root->info = x;
		root->left = NULL;
		root->right = NULL;
	} else {
		if(root->info >= x)
			mocNut(root->left,x);
		else
			mocNut(root->right,x);
	}
}

void taoCay(Node *&root) {
	int tmp;
	do {
		cout<<"Nhap so nguyen, 0 de dung: ";
		cin>>tmp;
		if(tmp != 0)
			mocNut(root,tmp);
	} while(tmp != 0);
}

void duyetLNR(Node *root) {
	if(root != NULL) {
		duyetLNR(root->left);
		cout<<root->info<<" ";
		duyetLNR(root->right);
	}
}

int Max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int chieuCao(Node *root) {
    if (root == NULL)
        return 0;
    else return 1 + Max(chieuCao(root->left), chieuCao(root->right));
}

void inNutMuci(Node *root, int i, int muc = 1) {
    if (root != NULL) {
        if (muc == i)
            cout << root->info << " ";
        else {
            inNutMuci(root->left, i, muc+1);
            inNutMuci(root->right, i, muc+1);
        }
    }
}




void saoChep(Node *root, Node *&root1) {
	if(root == NULL)
		root1 = NULL;
	else {
		root1 = new Node;
		root1->info = root->info;
		saoChep(root->left, root1->left);
		saoChep(root->right, root1->right);
	}
}


void mocMoi(Node *&root1, Node *&root2) {

    if (root2->left != NULL) {
        mocMoi(root1, root2->left);
    } else {
        root1->info = root2->info;
        root1 = root2;
        root2 = root2->right;
    }
}

void xoaNut(Node *&root, int x) {
    if (root == NULL) return;
    else {
        if (root->info > x) {
            xoaNut(root->left, x);
        }
        else if (root->info < x) {
            cout << "right";
            xoaNut(root->right, x);
        }
        else {
            cout << "found";
            Node *q = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            else mocMoi(q, root->right); // tim phai moc

            delete q;
        }
    }
}

void inputRandom(Node *&root) {
    int tam;
    do {
        rand() % 25;
        mocNut(root, tam);
    } while(tam != 0)

}
