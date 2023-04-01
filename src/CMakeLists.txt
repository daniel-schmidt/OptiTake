add_library(LibOptiTake 
    Board.cpp
    OptimalSolutionPlayer.cpp
    Player.cpp
    RemainingTiles.cpp
    Tile.cpp
)

target_compile_features(LibOptiTake PUBLIC cxx_std_20)
target_compile_options(LibOptiTake PUBLIC -Wall -pedantic)


target_include_directories(LibOptiTake PRIVATE .)