#include <iostream>
#include <vector>


using namespace std;
class Game
{
private:
    int move;
    const int X = 30;
    const int Y = 20;
    vector<vector<char>> field;
public:
    void right();
    void fieldcreation();
    void printfield();
    void start();
    void addMet();
    void down();
    void left();
};



void Game::fieldcreation()
{


    for (int i = 0; i < X; i++) {
        vector<char> a;
        for (int j = 0; j < Y; ++j) {


            a.push_back(' ');


        }
        field.push_back(a);

    }

}

void Game::printfield()
{
    for (int i = 0; i < X; i++) {
        vector<char> a;
        for (int j = 0; j < Y; ++j) {


            cout << field[i][j];


        }
        cout<<"\n";

    }
}

void Game::start()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            field[28][10] = '+';
            field[29][11] = '+';
            field[28][11] = '+';
            field[29][10] = '+';

        }
    }
}

void Game::addMet()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            int met = (rand() % 15 + 1);
            field[0][met] = '*';

        }

    }
}

void Game::down()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (field[i][j] == '*')
            {
                int r;
                r = field[i][j];
                field[i + 1][j] = r;
                field[i][j] = ' ';
            }
        }
    }
}

void Game::left()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (field[i][j]== '*')
            {
                char temp = field[i][j];
                field[i + 1][j] = temp;
                field[i][j] = ' ';
                move = 1;
            }

        }
    }
}
void Game::right()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (field[i][j--]== '*')
            {
                char temp = field[i][j];
                field[i - 1][j] = temp;
                field[i][j] = ' ';
                move = 1;
            }

        }
    }
}


void mover() {
    //int code = getch();
    //if (code == 0 || code == 224)
    //    code = getch();
    //switch (code)
    //{
    //case 75://âëåâî
    //    move2 = 1;
    //    break;
   // case 77://âïðàâî
    //   move2 = 2;
    //    break;
    //}
}
int main()
{

    Game go;

    go.fieldcreation();
    go.start();
    go.printfield();
    go.addMet();
    go.left();

}
