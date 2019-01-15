/*******************************************************************************
module:   MoveCostUniform
author:   digimokan
date:     13 JAN 2019
purpose:  uniform move cost (all moves cost 1, regardless of square values)
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

class MoveCostUniform : public MoveCostIface {

public:

  // constructors
  MoveCostUniform () = default;

  // destructor
  ~MoveCostUniform () override = default;

  // operators
  MoveCostUniform (const MoveCostUniform& in) = default;
  MoveCostUniform& operator= (const MoveCostUniform& rh) = default;
  MoveCostUniform (MoveCostUniform&& in) = default;
  MoveCostUniform& operator= (MoveCostUniform&& rh) = default;

  // base / derived methods
  unsigned int calc_cost (const Board& board, MoveDir move_dir) override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_COST_UNIFORM_HPP

