#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

int move2;
void fieldcreation(string m[10][10]){

    cout<<"-------------------";

    for (int i = 0;i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
                m[i][j] = " ";
                m[9][4] = "*";
                m[9][5] = "*";
                //cout.width(5);
                //cout<<"|";
                //v.push_back(10)
                cout<<m[i][j];
    }

        cout << "\n";

    }
    cout<<"-------------------";
}
void moveleft(string m[10][10]){

    for (int i = 0;i < 10; i++) {
        for (int j = 0; j < 10; ++j) {

                //cout.width(5);
                //cout<<"|";
                //v.push_back(10)
                cout<<m[i][j];
    }
       }
}
void mover(){
    int code = getch();
        if (code == 0 || code == 224)
            code = getch();
        switch (code)
        {
        case 75://âëåâî
            move2 = 1;
            break;
        case 77://âïðàâî
            move2 = 2;
            break;
        }
}
int main()
{
    string m[10][10];
    cout<<"1"<<endl;
    fieldcreation(m);
}
