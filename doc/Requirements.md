# Requirements

## Descrtiption
This documents contains the main elements needed to create the game of life

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