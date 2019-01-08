#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node {
	int data;
	struct node *pleft;
	struct node *pright;
};
typedef struct node* tree;

//ham khoi tao cay
void taocay(tree &root)
{
	root = NULL; // cay rong
}

// ham them node vao cay
void themnode(tree &root, int value)
{
	// neu cay rong
	if(root==NULL)
	{
		node *p = new node;
		p->data = value; //them gia tri cho data
		p->pleft = NULL;
		p->pright = NULL;
		root = p; //node p chinh la node goc 
	}
	// neu cay co ton tai phan tu
	else if(root->data > value) // neu phan tu them vao ma nho hon node goc ==> duyet no vao ben trai
		{
			themnode(root->pleft, value); // duyet qua trai de them gia tri
		}
		else if(root->data < value) // neu phan tu them vao ma lon hon node goc ==> duyet no vao ben phai
		{
			themnode(root->pright, value); // duyet qua phai de them gia tri
		}
}

//ham duyet cay
void duyet_nlr(tree root)
{
	if(root!=NULL)
	{
		cout << root->data << " "; // xuat du lieu trong cay
		duyet_nlr(root->pleft); //duyet qua trai
		duyet_nlr(root->pright); //duyet qua phai
		
	}
}

void duyet_lnr(tree root)
{
	if(root!=NULL)
	{
		duyet_nlr(root->pleft); //duyet qua trai
		cout << root->data << " "; // xuat du lieu trong cay
		duyet_nlr(root->pright); //duyet qua phai
		
	}
}
// ham nhap du lieu
void nhapdl(tree &root){
/*	while(true)
	{
	int value;
	int chon;
	system("cls");
	cout << "\nNhap du lieu: ";
	cin >> value;
	cout << "\nNeu muon dung thi bam phim 0:";
	cin >> chon;
	themnode(root, value);
	
	if(chon==0)
	{
		break;
	}
	else
	{
		cout << "Nhap tiep";
	}
}
*/
	while(true)
	{
		system("cls"); 
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu cay";
		cout << "\n0.Ket thuc";
		
		int chon;
		cout << "\nNhap lua chon";
		cin >> chon;
		if(chon < 0 || chon > 2)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if(chon==1)
		{
			int value;
			cout << "\nNhap so nguyen x:";
			cin >> value;
			themnode(root, value);
		}
		else if(chon==2)
		{
		
			cout << "\nDuyet cay theo nrl la:";
			duyet_nlr(root);
			cout << "\nDuyet cay lnr la:";
			duyet_lnr(root);
			system("pause");
		}
		else
		{
			break;
		}
	}
	
}
int main(int argc, char** argv) {
	tree root;
	taocay(root);
	nhapdl(root);
	system("pause");
	return 0;
}
