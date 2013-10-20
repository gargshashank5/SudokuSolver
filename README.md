SudokuSolver
============

Solving Sudoku using Naked single, Hidden single and Backtracking.

Naked single and Hidden single are powerful and fast techniques to solve Sudoku but they don't guarantee solution to every sudoku. Backtracking is time consuming but surely solves every sudoku. 
Combination of both the techniques give advantage of time as well as surity of solving sudoku

General Usage notes
--------------------

- Enter the cell values of given sudoku in that order in the sudoku.txt file.
- Fill a 0 for every vacant space.
- Do no add spaces between values.



Example
-------------------
```
You@Yourcomputer:~$ cd sudokudirectory //files are in sudoku_directory
You@Yourcomputer:~/sudokudirectory$ make
You@Yourcomputer:~/sudokudirectory$ ./sudoku
```
Note
----------

If you are not using g++ compiler. Edit the makefile accordingly. 
