#pragma once
#include <string>

namespace OptiTake
{
    struct BoardPosition;
    struct Tile;

    class Player
    {
    public:
        virtual ~Player() = default;
        
        virtual BoardPosition SelectPosition(Tile const &) = 0;
        virtual std::string getName() const = 0;
    };
}