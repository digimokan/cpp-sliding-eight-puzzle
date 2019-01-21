/*******************************************************************************
module:   SolverIface
author:   digimokan
date:     20 JAN 2019
purpose:  finds solution-steps to an input eight-puzzle board
*******************************************************************************/

#ifndef SOLVER_IFACE_HPP
#define SOLVER_IFACE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <optional>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Solution;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverIface {

public:

  // destructor
  virtual ~SolverIface () = default;

  // operators
  SolverIface (const SolverIface& in) = delete;
  SolverIface& operator= (const SolverIface& rh) = delete;
  SolverIface (SolverIface&& in) = delete;
  SolverIface& operator= (SolverIface&& rh) = delete;

  // base / derived methods
  virtual std::optional<Solution> solve () = 0;

protected:

  // constructors
  SolverIface () = default;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_IFACE_HPP

