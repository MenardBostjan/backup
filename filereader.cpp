#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
int main (){
    char c;
    ifstream myFile;

    myFile.open("test.txt", ifstream::in);

    if (myFile.is_open()){
        do{
            c = myFile.get();
            if (myFile.good())
            cout << c;
            Sleep(100);
        } while (!myFile.eof());
    }
    if (myFile.is_open())
    myFile.close();

}