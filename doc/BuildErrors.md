## Error
# # Build: Windows MinGW Static Shared, vs2022 staic

Grid.cpp
D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8): error C2666: 'Grid::operator ==': overloaded functions have similar conversions [D:\a\GameOfLife\GameOfLife\build\game_of_life_lib\game_of_life_lib.vcxproj]
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  could be 'bool Grid::operator ==(const Grid &)'
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  or 'bool Grid::operator ==(const Grid &)' [synthesized expression 'y == x']
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8):
  while trying to match the argument list '(Grid, Grid)'


 Grid.cpp
D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8): error C2666: 'Grid::operator ==': overloaded functions have similar conversions [D:\a\GameOfLife\GameOfLife\build\game_of_life_lib\game_of_life_lib.vcxproj]
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  could be 'bool Grid::operator ==(const Grid &)'
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\include\model\Grid.hpp(35,17):
  or 'bool Grid::operator ==(const Grid &)' [synthesized expression 'y == x']
  D:\a\GameOfLife\GameOfLife\game_of_life_lib\source\controller\RuleSet.cpp(90,8):
  while trying to match the argument list '(Grid, Grid)'

