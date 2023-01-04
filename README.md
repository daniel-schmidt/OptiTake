# OptiTake
An open-source implementation of the board game Take it Easy.

https://en.wikipedia.org/wiki/Take_It_Easy_(game)

## Rules

The game consists of a board and 27 tiles with the shape of a hexagon. The board has 19 cells arranged as a 3x3 hexagon. Each tile has three numbers on it each representing one direction by connecting opposite sides of the hexagon with a line. Each direction has three different values.
* vertical: 1, 5, 9
* diagonal (going up): 2, 6, 7
* diagonal (going down): 3, 4, 8

~~~text
             ___
         ___/   \___
     ___/   \___/   \___
    /   \___/   \___/   \
    \___/   \___/   \___/
    /   \___/   \___/   \
    \___/   \___/   \___/
    /   \___/   \___/   \
    \___/   \___/   \___/
        \___/   \___/
            \___/
~~~

The tiles are drawn one at a time and placed on the board. After being placed, they cannot be moved. The game ends as soon as the board is filled. When the numbers along continous lines all match, the numbers are summed up to give a score. The goal is to get a high score.
