/*******************************************************************************
module:   MoveGenerator
author:   digimokan
date:     13 JAN 2019
purpose:  given board and move-cost-function, generate list of possible moves
*******************************************************************************/

#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <list>
#include <memory>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class MoveCostIface;
class Move;
enum class MoveDir;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MoveGenerator {

public:

  // constructors
  MoveGenerator () = delete;
  explicit MoveGenerator (std::shared_ptr<MoveCostIface>);

  // destructor
  ~MoveGenerator () = default;

  // operators
  MoveGenerator (const MoveGenerator& in) = delete;
  MoveGenerator& operator= (const MoveGenerator& rh) = delete;
  MoveGenerator (MoveGenerator&& in) = delete;
  MoveGenerator& operator= (MoveGenerator&& rh) = delete;

  // specialized methods
  std::list<Move> generate_moves (const Board&) const;

private:

  // fields
  std::shared_ptr<MoveCostIface> move_cost;

  // helper methods
  std::list<MoveDir> generate_move_dirs (const Board&) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_GENERATOR_HPP

