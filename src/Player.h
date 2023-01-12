#pragma once
#include "Board.h"
#include "Tile.h"

#include <iostream>
#include <random>

namespace OptiTake
{

    class Player
    {
    public:
        virtual ~Player() = default;
        
        virtual void SetChosenTile(Tile const &) = 0;
        virtual BoardPosition GetPosition() const = 0;
    };


    class CommandLinePlayer : public Player
    {
    public:
        void SetChosenTile(Tile const & chosenTile) override;

        BoardPosition GetPosition() const override;
    };


    class ComputerPlayer : public Player
    {
    public:
        void SetChosenTile(Tile const & chosenTile) override;

        BoardPosition GetPosition() const override;
    
    private:
        // to draw a random position for column
        std::random_device mutable rd_pos;
        std::default_random_engine mutable gen_pos{rd_pos()};
    };

}