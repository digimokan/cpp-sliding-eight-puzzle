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

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class CmdLineArgProcessor {

public:

  // constructors
  CmdLineArgProcessor () = delete;

  // destructor
  ~CmdLineArgProcessor () = delete;

  // operators
  CmdLineArgProcessor (const CmdLineArgProcessor& in) = delete;
  CmdLineArgProcessor& operator= (const CmdLineArgProcessor& rh) = delete;
  CmdLineArgProcessor (CmdLineArgProcessor&& in) = delete;
  CmdLineArgProcessor& operator= (CmdLineArgProcessor&& rh) = delete;

  // static methods
  static void process_args (int argc, char* const* argv);

private:

  // static fields
  static const char* short_opts;
  static const option long_opts_map[];
  static const char* program_name;

  // static helper methods
  static void process_options (int argc, char* const* argv);
  static void process_non_option_args (int argc, char* const* argv);
  static void process_opt (int opt);
  static void print_err_msg (const std::string& err_msg);

  // static option handlers
  static void handle_help (int exit_code);
  static void handle_breadth_first ();
  static void handle_depth_first ();
  static void handle_iterative_deepening ();
  static void handle_uniform_cost ();
  static void handle_best_first ();
  static void handle_a_star_1 ();
  static void handle_a_star_2 ();
  static void handle_a_star_3 ();
  static void handle_max_iterations ();

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // CMD_LINE_ARG_PROCESSOR_HPP

