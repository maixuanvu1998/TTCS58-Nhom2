#include "bignum1.h" 
#include <fstream> 

using namespace std; 
int main() { 
    bignum a, b, c, d;
	cout<<"Nhap a: "; 
    cin >> a; 
    cout<<"Nhap b: "; 
    cin >> b;       
    cout <<endl<<"Tong: "<< a + b; 
    cout <<endl<<"Hieu: "<< a - b; 
    cout <<endl<<"Tich: "<< a * b; 
    cout <<endl<<"Chia phan nguyen: "<< a / b; 
    cout <<endl<<"Chia lay du: "<< a % b; 
	getchar(); 
}  
