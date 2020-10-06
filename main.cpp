#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include "windows.h"
#include <conio.h>


using namespace std;
int mover2;
class Game
{
private:
    const int X = 40;
    const int Y = 40;
    vector<vector<char>> field;
public:

    void printfield();
    void start();
    void addMet();
    void down();
    void left();
    void right();
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
    field[Y-1][X / 2] = '*';
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
    for (int i = 0; i < Y; i++)
    {
        cout << '|';
        for (int  j = 0;  j< X; j++)
        {
            cout << field[i][j];
        }
        cout << '|';
        cout << endl;
    }
}

void Game::addMet()
{

      field[0][0 + rand() % X] = '&';



}

void Game::down()
{
        for (int i = 0; i < Y; i++)
        {
            for (int  j = 0;  j< X; j++)
            {
                if ( j+1 < X ) {
                    if (field[j][i] == '&')
                    {
                        field[j+1][i] = '&';
                        field[j][i] = ' ';
                        break;
                    }
                }

            }

        }


}
void Game::left()
{
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
    if (field[Y - 1][X-1] == '*')
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
void mover() {
    while(true){
    if(kbhit()) // слушатель нажатия на клаву
        {
            switch(getch()) // ждёт нажатия на клаву без Enter после этого
                {
                    case 72: //вверх
                        mover2 = 1;
                        break;
                    case 80: //вниз
                        mover2 = 2;
                        break;
                    case 75: //влево
                         mover2 = 3;
                         break;
                    case 77: //вправо
                         mover2 = 4;
                         break;
                            }
                    }
    }
}
/*void SpamMet(int *a)
{
    a = down();
}*/
int main()
{

    Game go;
    go.start();

    go.addMet();
    go.printfield();

    /*Game *a = &go;

    go.down();
    a->down();*/

    /*thread SpamMet(&Game::addMet, ref(go));
    thread DownMet(&Game::down, ref(go));
    DownMet.join();
    SpamMet.join();
    thread Checkclav(mover);
    go.printfield();*/

    /*for (int i = 0; i < 5; i++)
     {
        Sleep(500);
        go.down();
        go.printfield();
     }
    for (int i = 0; i < 40; i++){

        Sleep(500); // ждать 5 секунд, время эта функция считает в тысячных долях секунды

        go.left();
        go.printfield();
     }
    for (int i = 0; i < 40; i++)
        {
            go.down();
            Sleep(500);
            go.printfield();

        }*/




}
