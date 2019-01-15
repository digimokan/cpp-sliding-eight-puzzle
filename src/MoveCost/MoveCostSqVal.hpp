/*******************************************************************************
module:   MoveCostSqVal
author:   digimokan
date:     13 JAN 2019
purpose:  calc move cost based on val of square to swap with empty square
*******************************************************************************/

#ifndef MOVE_COST_SQ_VAL_HPP
#define MOVE_COST_SQ_VAL_HPP 1

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MoveCostIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
enum class MoveDir;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MoveCostSqVal : public MoveCostIface {

public:

  // constructors
  MoveCostSqVal () = default;

  // destructor
  ~MoveCostSqVal () override = default;

  // operators
  MoveCostSqVal (const MoveCostSqVal& in) = default;
  MoveCostSqVal& operator= (const MoveCostSqVal& rh) = default;
  MoveCostSqVal (MoveCostSqVal&& in) = default;
  MoveCostSqVal& operator= (MoveCostSqVal&& rh) = default;

  // base / derived methods
  unsigned int calc_cost (const Board& board, MoveDir move_dir) override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_COST_SQ_VAL_HPP

