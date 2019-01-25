/*******************************************************************************
module:   main
author:   digimokan
date:     24 JAN 2018 (created)
purpose:  collect user input, make a Solver, run it and output results
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "CmdLineArgProcessor.hpp"
#include "Solution.hpp"
#include "SolverIface.hpp"

/*******************************************************************************
* MAIN
*******************************************************************************/

int main (int argc, char* argv[]) {
  CmdLineArgProcessor token_proc{ argc, argv };
  std::shared_ptr<SolverIface> solver{ token_proc.process_args() };
  Solution solution{ solver->solve() };
  return (0);
}

