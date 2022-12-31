#include <iostream>
#include <string>
#include <vector>

struct Plate
{
    int x;
    int y;
    int z;
};


std::ostream & operator<<(std::ostream & strm, Plate const & p)
{
    strm << p.x << ", " << p.y << ", " << p.z;
    return strm;
}


int main()
{
    Plate const p1{9, 7, 3};    
    std::cout << "Hello Daniel. Du hast " << p1 << " gezogen!\n";
}