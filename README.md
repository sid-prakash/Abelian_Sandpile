# Abelian Sandpile
This is the Abelian Sandpile simulator. A grain of sand is added to the middle of a 23x23 Euclidean plane. If the height of the pile is greater than 8, then it is unstable and will topple. Toppling will remove 8 grains of sand from the pile and deposit them into one each on each of the cardinally and diagonally adjacent piles.

I used a recursive method to check if the current pile is over 8, if it is then I remove 8. Then I recursively check if all it's neighbors are also over 8.

To excuted the program run "make", then "./sandpile" which is the executable. You can also choose the fps and the initial sandpile. 

To initialize the sandpile run "./sandpile 11 11 3" where the first 2 "11 11" is the location and "3" is the number of sand.

How to set of fps: "./sandpile --fps 5"

Example of setting program to 5 fps and initilize grid to 3 at (11, 11) and 1 at (11, 12): "./sandpile --fps 5 11 11 3 11 12 1"