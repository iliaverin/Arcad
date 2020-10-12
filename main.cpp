#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include "windows.h"
#include <conio.h>
#include <mutex>
#include <cstring>
#include <cstdlib>


using namespace std;
int mover2;
class Game
{
private:
    const int X = 40;
    const int Y = 40;
    bool state = true;
    mutable mutex mState;
    mutable mutex mField;
    vector<vector<char>> field;
public:

    void printfield();
    void start();
    void addMet();
    void down();
    void left();
    void right();
    bool getstate();
};



void Game::start()
{
    for (int i = 0; i < Y; i++)
    {
        vector<char> temp;
        for (int j = 0; j < X; j++)
        {
            temp.push_back(' ');
        }
        field.push_back(temp);
    }
    field[Y - 1][X / 2] = '*';
    field[Y - 1][(X / 2) + 1] = '*';
    field[Y - 2][X / 2] = '*';
    field[Y - 2][(X / 2) + 1] = '*';
    field[Y - 3][X / 2] = '*';
    field[Y - 3][(X / 2) + 1] = '*';
    srand(time(NULL));
}

void Game::printfield()
{
    system("cls");
    std::lock_guard<std::mutex> lock(mField);
    for (int i = 0; i < Y; i++)
    {
        cout << '|';
        for (int j = 0; j < X; j++)
        {
            cout << field[i][j];
        }
        cout << '|';
        cout << endl;
    }
}

void Game::addMet()
{
    std::lock_guard<std::mutex> lock(mField);
    field[0][0 + rand() % X] = '&';



}

void Game::down()
{
    std::lock_guard<std::mutex> lock(mField);

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y - 1; j++)
        {
            if (field[j][i] == '&')
            {
                if (field[j+1][i] == '*')
                {
                    state = false;
                    return;
                }
                field[j][i] = ' ';



                if (field[Y - 1][i] == '&')
                {
                    field[Y - 1][i] = ' ';
                }
                else
                {
                    field[j + 1][i] = '&';
                }
                j++;
            }

        }
    }


}
void Game::left()
{
    std::lock_guard<std::mutex> lock(mField);
    if (field[Y - 1][0] == '*')
        return;
    for (int j = Y - 3; j < Y; j++)
    {
        for (int i = 0; i < X; i++)
        {
            if (field[j][i] == '*')
            {
                field[j][i - 1] = '*';
                field[j][i + 1] = ' ';
            }
        }
    }
}

void Game::right()
{
    std::lock_guard<std::mutex> lock(mField);
    if (field[Y - 1][X - 1] == '*')
        return;
    for (int j = Y - 3; j < Y; j++)
    {
        for (int i = X - 1; i > 0; i--)
        {
            if (field[j][i] == '*')
            {
                field[j][i + 1] = '*';
                field[j][i - 1] = ' ';
            }
        }
    }
}

bool Game::getstate()
{
    std::lock_guard<std::mutex> lock(mState);
    return state;
}

void mover(Game&go) {

    while (true) {
        if (kbhit()) // ñëóøàòåëü íàæàòèÿ íà êëàâó
        {
            switch (getch()) // æä¸ò íàæàòèÿ íà êëàâó áåç Enter ïîñëå ýòîãî
            {

            case 75: //âëåâî
                go.left();
                break;
            case 77: //âïðàâî
                go.right();
                break;

            }
        }
    }
}
 void Print(Game& go)
{
     while (go.getstate())
     {
         go.printfield();
         this_thread::sleep_for(chrono::milliseconds(100));
     }



}
void CreetMet(Game&go)
{
    while (go.getstate())
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        go.addMet();

    }



}
void DownMetf(Game& go)
{
    while (go.getstate())
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        go.down();

    }

}
int main()
{

    Game go;
    go.start();
    go.addMet();
    go.printfield();
    go.down();

    go.printfield();


    thread Printer(Print, ref(go));
    thread SpamMet(CreetMet, ref(go));
    thread DownMet(DownMetf, ref(go));
    thread Checkclav(mover, ref(go));
    Checkclav.join();
    DownMet.join();
    SpamMet.join();
    Printer.join();


}


