/*******************************************************************************
module:   MoveDir
author:   digimokan
date:     13 JAN 2019
purpose:  a possible direction to move the empty (0) square of a board
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MoveDir.hpp"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <iostream>

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::ostream& operator<< (std::ostream& os, const MoveDir& move_dir) {
  switch (move_dir) {
    case MoveDir::UP:
      os << "UP";
      break;
    case MoveDir::DOWN:
      os << "DOWN";
      break;
    case MoveDir::LEFT:
      os << "LEFT";
      break;
    case MoveDir::RIGHT:
      os << "RIGHT";
      break;
  }
   return os;
}

