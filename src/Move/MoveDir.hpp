/*******************************************************************************
module:   MoveDir
author:   digimokan
date:     13 JAN 2019
purpose:  a possible direction to move the empty (0) square of a board
*******************************************************************************/

#ifndef MOVE_DIR_HPP
#define MOVE_DIR_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <iostream>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

// types
enum class MoveDir {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

// specialized methods
std::ostream& operator<< (std::ostream&, const MoveDir&);

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_DIR_HPP
