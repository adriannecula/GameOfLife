# Overview

## History
According to [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life):

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine. 

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur: 

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These rules, which compare the behaviour of the automaton to real life, can be condensed into the following:

1. Any live cell with two or three live neighbours survives.
2. Any dead cell with three live neighbours becomes a live cell.
3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

## Descrtiption
The main elements used to create game of life are

### Grid
A grid is used to represent the cells in the game. Each cell can be in one of two states: alive or dead. The grid provides a visual representation of the current state of the game.

### Cell
A cell is a single unit within the grid. It can be alive or dead, and its state can change based on certain rules defined by the game.

### User Interface
The UI allows users to interact with the game. It typically includes buttons or controls for starting, stopping, and resetting the game, as well as options for customizing the initial state of the grid.

### Rules Engine
The rules engine defines the rules that govern how the game progresses from one generation to the next. In Conway’s Game of Life, for example, cells can die or come to life based on the number of neighboring cells that are alive.

### Event Handling: 
Event handling allows the application to respond to user input, such as mouse clicks or keyboard presses. It enables users to interact with the game and trigger actions based on their input.
