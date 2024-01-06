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
        
        virtual void SetChosenTile(Tile const &) = 0;
        virtual BoardPosition SelectPosition() = 0;
        virtual std::string getName() const = 0;
    };
}