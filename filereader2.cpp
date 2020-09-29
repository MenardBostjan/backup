#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

string getBook(){
    string bookName;
    int chosen;
    system("cls");
    cout << "1. The Sixth Patriarchs Dharma Jewel Platform Sutra" << endl;
    cout << "2. Surangama Sutra" << endl;
    cin >> chosen;

    switch (chosen){ 
        case 1: 
            bookName = "The Sixth Patriarchs Dharma Jewel Platform Sutra.txt";
            break;
        case 2: 
            bookName = "Surangama Sutra.txt";
            break;
        default :
            bookName= "The Sixth Patriarchs Dharma Jewel Platform Sutra.txt";
            break;
    }
    return bookName;
}

int main (){
    char c;
ifstream myFile;
string bookName;
bookName = getBook();
cout << bookName;
myFile.open(bookName.c_str(), ifstream::in);

    if (myFile.is_open()){
        do {
            c = myFile.get();
            if (myFile.good())
            cout << c;
            Sleep(100);
        } while (!myFile.eof());
    }
    
    if (myFile.is_open())
    myFile.close();

}