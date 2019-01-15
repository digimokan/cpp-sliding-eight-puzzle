/*******************************************************************************
module:   MoveCostIface
author:   digimokan
date:     13 JAN 2019
purpose:  interface for calculating move cost, given board and move-dir
*******************************************************************************/

#ifndef MOVE_COST_IFACE_HPP
#define MOVE_COST_IFACE_HPP 1

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
enum class MoveDir;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MoveCostIface {

public:

  // destructor
  virtual ~MoveCostIface () = default;

  // operators
  MoveCostIface (const MoveCostIface& in) = default;
  MoveCostIface& operator= (const MoveCostIface& rh) = default;
  MoveCostIface (MoveCostIface&& in) = default;
  MoveCostIface& operator= (MoveCostIface&& rh) = default;

  // base / derived methods
  virtual unsigned int calc_cost (const Board&, MoveDir) = 0;

protected:

  // constructors
  MoveCostIface () = default;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MOVE_COST_IFACE_HPP

