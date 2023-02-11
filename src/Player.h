#pragma once
#include "Board.h"

#include <iostream>
#include <random>
#include <string>

namespace OptiTake
{
    struct Tile;

    class Player
    {
    public:
        virtual ~Player() = default;
        
        virtual void SetChosenTile(Tile const &) = 0;
        virtual BoardPosition SelectPosition() = 0;
        virtual std::string getName() const = 0;
    };


    class CommandLinePlayer : public Player
    {
    public:
      CommandLinePlayer(std::string playerName);

      void SetChosenTile(Tile const &chosenTile) override;

      BoardPosition SelectPosition() override;

      std::string getName() const override;

    private:
      std::string name;
    };


    class ComputerPlayer : public Player
    {
    public:
        void SetChosenTile(Tile const & chosenTile) override;

        BoardPosition SelectPosition() override;

        std::string getName() const override;

      private:
        // to draw a random position for column
        std::random_device rdPos;
        std::default_random_engine genPos{rdPos()};

        // all 19 boardPositions existing in the game
        static constexpr std::array<BoardPosition, 19> allPossiblePositions{ 
        BoardPosition{1, 1}, 
        {1, 2}, 
        {1, 3}, 
        {2, 1}, 
        {2, 2}, 
        {2, 3}, 
        {2, 4}, 
        {3, 1}, 
        {3, 2}, 
        {3, 3}, 
        {3, 4}, 
        {3, 5}, 
        {4, 1}, 
        {4, 2}, 
        {4, 3}, 
        {4, 4}, 
        {5, 1},
        {5, 2}, 
        {5, 3}};
    };

}