#pragma once
#include <string>

namespace OptiTake
{
    class Board;
    struct BoardPosition;
    struct Tile;

    class Player
    {
    public:
        virtual ~Player() = default;
        
        virtual BoardPosition SelectPosition(Tile const &, Board const &) = 0;
        virtual std::string getName() const = 0;
    };
}