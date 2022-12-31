add_library(LibOptiTake 
    Board.cpp
    RemainingTiles.cpp
    Tile.cpp
)

target_compile_features(LibOptiTake PRIVATE cxx_std_20)
target_compile_options(LibOptiTake PRIVATE -Wall -pedantic)


target_include_directories(LibOptiTake PRIVATE .)