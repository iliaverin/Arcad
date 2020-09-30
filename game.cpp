#include "game.h"

Game::Game(int move)
{
    for (size_t i = 0; i < SIZE; i++)
            {
                    std::vector<int>v1;
                    for (size_t j = 0; j < SIZE; j++)
                    {
                            v1.push_back(FIELD_EMPTY);

                    }
                    field.push_back(v1);
}
