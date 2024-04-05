## Error

### 1 Build error on Windows MinGW Static and Shared, VS2022 staic

Grid.cpp
D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8): error C2666: 'Grid::operator ==': overloaded functions have similar conversions [D:\a\GameOfLife\GameOfLife\build\game_of_life_lib\game_of_life_lib.vcxproj]
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  could be 'bool Grid::operator ==(const Grid &)'
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  or 'bool Grid::operator ==(const Grid &)' [synthesized expression 'y == x']
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8):
  while trying to match the argument list '(Grid, Grid)'

#### Problem:

The function was not const: bool operator==(const Grid& rhs)

#### Solution
Changing the signature as bool operator==(const Grid& rhs) const solve the issue. 


