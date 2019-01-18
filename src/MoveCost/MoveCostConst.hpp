/*******************************************************************************
module:   MoveCostConst
author:   digimokan
date:     13 JAN 2019
purpose:  constant move cost (all moves cost 1, regardless of square values)
*******************************************************************************/

#ifndef MOVE_COST_UNIFORM_HPP
#define MOVE_COST_UNIFORM_HPP 1

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

class MoveCostConst : public MoveCostIface {

public:

  // constructors
  MoveCostConst () = default;

  // destructor
  ~MoveCostConst () override = default;

  // operators
  MoveCostConst (const MoveCostConst& in) = default;
  MoveCostConst& operator= (const MoveCostConst& rh) = default;
  MoveCostConst (MoveCostConst&& in) = default;
  MoveCostConst& operator= (MoveCostConst&& rh) = default;

  // base / derived methods
  unsigned int calc_cost (const Board& board, MoveDir move_dir) override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_COST_UNIFORM_HPP

