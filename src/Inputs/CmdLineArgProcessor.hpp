/*******************************************************************************
module:   CmdLineArgProcessor
author:   digimokan
date:     12 JAN 2019
purpose:  process command-line inputs
*******************************************************************************/

#ifndef CMD_LINE_ARG_PROCESSOR_HPP
#define CMD_LINE_ARG_PROCESSOR_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <getopt.h>
#include <string>
#include <vector>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class CmdLineArgProcessor {

public:

  // constructors
  CmdLineArgProcessor () = delete;
  CmdLineArgProcessor (int argc, char* argv[]);

  // destructor
  ~CmdLineArgProcessor () = default;

  // operators
  CmdLineArgProcessor (const CmdLineArgProcessor& in) = delete;
  CmdLineArgProcessor& operator= (const CmdLineArgProcessor& rh) = delete;
  CmdLineArgProcessor (CmdLineArgProcessor&& in) = delete;
  CmdLineArgProcessor& operator= (CmdLineArgProcessor&& rh) = delete;

  // specialized methods
  void process_args ();

private:

  // fields
  const char* program_name;
  std::vector<char*> tokens;
  const char* short_opts;
  const std::vector<option> long_opts_map;

  // helper methods
  void process_options ();
  void process_non_option_args ();
  void process_opt (int opt);
  void print_err_msg (const std::string& err_msg);

  // option handlers
  void handle_help (int exit_code);
  void handle_breadth_first ();
  void handle_depth_first ();
  void handle_iterative_deepening ();
  void handle_uniform_cost ();
  void handle_best_first ();
  void handle_a_star_1 ();
  void handle_a_star_2 ();
  void handle_a_star_3 ();
  void handle_max_iterations ();

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // CMD_LINE_ARG_PROCESSOR_HPP

