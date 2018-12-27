#include <iostream>
#include <fstream>
using namespace std;

void xuatMang(int arr[],int n) {
    for (int i = 0 ;i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << "======" << endl;
}

void readFile(int arr[], string path) {
    ifstream infile;
    infile.open(path);
    int i = 0;
    int n = 0;
    if (infile.fail()) {
        cout << "Your file didn't work." << endl;
    } else {
        infile >> n;
        // dung khi het file
        while(!infile.eof()) {
            infile >> arr[i];
            i++;
        }
    }
    xuatMang(arr, n);

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

void writeFile(int a, int b, string path) {
    ofstream outfile;
    outfile.open(path);
    outfile << a << " " << b;
    outfile.close();
}

int main() {
    string path = "input.txt";
    int arr[50];

/*
    ofstream outfile;
    outfile.open("output.txt");
    outfile << "First number " << 5;
    outfile << "Second line ";
    outfile.close();

*/

    return 0;
}
