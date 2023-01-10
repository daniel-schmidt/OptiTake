#include "Board.h"
#include "RemainingTiles.h"
#include "Tile.h"

#include <iostream>
#include <memory>

using namespace OptiTake;

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
    void SetChosenTile(Tile const & chosenTile) override
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";
    }

    BoardPosition GetPosition() const override
    {
        std::cout << "Please insert a position (format: column row): ";
        int colIndex = 0;
        int posInCol = 0;
        std::cin >> colIndex >> posInCol;
        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }
};


class ComputerPlayer : public Player
{

};



int main()
{
    std::cout << "This is the game Take it Easy!\n";
    RemainingTiles remainingTiles{};
    Board board{};
    
    std::unique_ptr<Player> player = std::make_unique<CommandLinePlayer>();

    // The board has 19 positions for tiles.
    for (int i = 0; i < 19; ++i){
        // The game as a total of 27 tiles.
        // In each round, one random tile is drawn from the remaining set of tiles.
        // The tile is presented and the position is chosen by the user. 
        std::cout << "The current board is:\n" << board << "\n";
        Tile chosenTile = remainingTiles.drawRandomTile();
        player->SetChosenTile(chosenTile);
        
        bool success = false;
        while (!success) {
            success = board.SetTileToPosition(chosenTile, player->GetPosition());
            if(!success) {
                std::cout << "This is not a valid, free position. Try again!\n";
            }
        }

        std::cout << "Current score: " << board.GetScore() << "\n";
    }
    std::cout << "The final board is:\n" << board << "\n";
    std::cout << "Game over! You finished with a final score of " << board.GetScore() << ".\n";
}