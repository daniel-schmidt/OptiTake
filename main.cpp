#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <string>
#include <vector>


namespace
{
    struct Tile
    {
        int x;
        int y;
        int z;

        auto operator<=>(Tile const &) const = default;
    };


    std::ostream & operator<<(std::ostream & strm, Tile const & t)
    {
        strm << t.x << ", " << t.y << ", " << t.z;
        return strm;
    }


    std::array<Tile, 27> allPossibleTiles{ 
        Tile{1, 2, 3}, 
        {1, 2, 4},
        {1, 2, 8},
        {1, 6, 3}, 
        {1, 6, 4},
        {1, 6, 8},
        {1, 7, 3}, 
        {1, 7, 4},
        {1, 7, 8},
        {5, 2, 3}, 
        {5, 2, 4},
        {5, 2, 8},
        {5, 6, 3}, 
        {5, 6, 4},
        {5, 6, 8},
        {5, 7, 3}, 
        {5, 7, 4},
        {5, 7, 8},
        {9, 2, 3}, 
        {9, 2, 4},
        {9, 2, 8},
        {9, 6, 3}, 
        {9, 6, 4},
        {9, 6, 8},
        {9, 7, 3}, 
        {9, 7, 4},
        {9, 7, 8}};
}


class RemainingTiles 
{
public:
    RemainingTiles()
    {
        std::ranges::copy(allPossibleTiles, std::back_inserter(availableTiles));
    }

    Tile drawRandomTile() 
    {
        assert (!availableTiles.empty());
        if (availableTiles.size() == 1){
            return availableTiles[0];
        }
        int numberTiles = availableTiles.size() -1;
        std::uniform_int_distribution<> distrib(0, numberTiles);

        int chosenIndex = distrib(gen);
        Tile chosenTile = availableTiles[chosenIndex];
        std::erase(availableTiles, chosenTile);
        return chosenTile;
    }

private:
    std::vector<Tile> availableTiles{};
    std::random_device rd;
    std::default_random_engine gen{rd()};
};


int main()
{
    std::cout << "This is the game Take it Easy!" << std::endl;
    RemainingTiles remainingTiles{};
    for (int i = 0; i < 19; ++i){
        Tile chosenTile = remainingTiles.drawRandomTile();
        std::cout << "The chosen tile is " << chosenTile << ".\n";
    }
    std::cout << "Game over!" << std::endl;
}