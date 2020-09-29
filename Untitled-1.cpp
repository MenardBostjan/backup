 #include <iostream>
#include <fstream>
#include <stdlib.h>

string getBook(){
    string bookName;
    int chosen;
    system("cls");
    cout << "1. The Sixth Patriarchs Dharma Jewel Platform Sutra" << endl;
    cout << "2. Surangama Sutra" << endl;
    cin >> chosen;

    switch (chosen){ 
        case 1: 
            bookName = "The Sixth Patriarchs Dharma Jewel Platform Sutra";
            break;
        case 2: 
            bookName = "Surangama Sutra";
            break;
        default :
            bookName= "The Sixth Patriarchs Dharma Jewel Platform Sutra";
            break;
    }
    return bookName;
}
using namespace std;
int main (){
    char c;
ifstream myFile;
string bookName;
bookName = getBook();
myFile.open(bookName, ifstream::in);

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