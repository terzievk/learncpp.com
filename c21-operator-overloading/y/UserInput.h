#ifndef USER_INPUT_H_
#define USER_INPUT_H_

class Direction;

namespace UserInput {
  char getCommand();

  Direction commandToDirection(char command);
}  // namespace UserInput

#endif  //  USER_INPUT_H_
