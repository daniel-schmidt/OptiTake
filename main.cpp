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


Tile drawRandomTile(std::vector<Tile> & possibleTiles, std::minstd_rand0 & gen) {
    assert (!possibleTiles.empty());
    if (possibleTiles.size() == 1){
        return possibleTiles[0];
    }
    int numberTiles = possibleTiles.size() -1;
    std::uniform_int_distribution<> distrib(0, numberTiles);

    int chosenIndex = distrib(gen);
    Tile chosenTile = possibleTiles[chosenIndex];
    std::erase(possibleTiles, chosenTile);
    return chosenTile;

}


int main()
{
    std::vector<Tile> availableTiles{};
    std::ranges::copy(allPossibleTiles, std::back_inserter(availableTiles));

    std::random_device rd;
    std::default_random_engine gen(rd());

    for (int i = 0; i < 19; ++i){
        Tile chosenTile = drawRandomTile(availableTiles, gen);
        std::cout << "Hello. You have chosen tile " << chosenTile << "\n";
    }
    std::cout << "Game over!" << std::endl;


}