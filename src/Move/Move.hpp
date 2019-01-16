/*******************************************************************************
module:   Move
author:   digimokan
date:     13 JAN 2019
purpose:  a new board, the empty-sq move that created it, and the move's cost
*******************************************************************************/

#ifndef MOVE_HPP
#define MOVE_HPP 1

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

enum class MoveDir;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class Move {

public:

  // constructors
  Move () = delete;
  Move (Board board, MoveDir move_dir, unsigned int cost);

  // destructor
  ~Move () = default;

  // operators
  Move (const Move& in) = delete;
  Move& operator= (const Move& rh) = delete;
  Move (Move&& in) = delete;
  Move& operator= (Move&& rh) = delete;
  bool operator== (const Move& rh);
  bool operator!= (const Move& rh);

  // get/set methods
  Board get_board () const;
  MoveDir get_move_dir () const;
  unsigned int get_cost () const;

private:

  // fields
  Board new_board;
  MoveDir move_dir;
  unsigned int cost;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_HPP

