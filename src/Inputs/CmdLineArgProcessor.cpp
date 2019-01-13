/*******************************************************************************
module:   CmdLineArgProcessor
author:   digimokan
date:     12 JAN 2019
purpose:  process command-line inputs
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "CmdLineArgProcessor.hpp"

/*******************************************************************************
* STATIC FIELDS
*******************************************************************************/

const char* CmdLineArgProcessor::short_opts = "hbdius123m:";

const option CmdLineArgProcessor::long_opts_map[] = {
  {"help",                no_argument,       nullptr, 'h'},
  {"breadth-first",       no_argument,       nullptr, 'b'},
  {"depth-first",         no_argument,       nullptr, 'd'},
  {"iterative-deepening", no_argument,       nullptr, 'i'},
  {"uniform-cost",        no_argument,       nullptr, 'u'},
  {"best-first",          no_argument,       nullptr, 's'},
  {"a-star-1",            no_argument,       nullptr, '1'},
  {"a-star-2",            no_argument,       nullptr, '2'},
  {"a-star-3",            no_argument,       nullptr, '3'},
  {"max-iterations",      required_argument, nullptr, 'm'},
  {nullptr, no_argument, nullptr, 0}
};

const char* CmdLineArgProcessor::program_name;

/*******************************************************************************
* PUBLIC STATIC METHODS
*******************************************************************************/

void CmdLineArgProcessor::process_args (int argc, char* const* argv) {
  CmdLineArgProcessor::program_name = argv[0];
  CmdLineArgProcessor::process_options(argc, argv);
  CmdLineArgProcessor::process_non_option_args(argc, argv);
}

/*******************************************************************************
* STATIC HELPER METHODS
*******************************************************************************/

void CmdLineArgProcessor::process_options (int argc, char* const* argv) {
  while (true) {
    const int opt = getopt_long(argc, argv, CmdLineArgProcessor::short_opts,
      CmdLineArgProcessor::long_opts_map, nullptr);
    if (opt == -1)
      break;
    CmdLineArgProcessor::process_opt(opt);
  }
}

void CmdLineArgProcessor::process_non_option_args (int argc, char* const* argv) {
  if ((argc - optind) != 2) {
    CmdLineArgProcessor::print_err_msg("missing non-option argument");
  } else {
    std::cout << "<start_board>: " << argv[optind] << std::endl;
    std::cout << "<goal_board>: " << argv[optind + 1] << std::endl;
  }
}

void CmdLineArgProcessor::process_opt (int opt) {
  switch (opt) {
  case 'h':
    CmdLineArgProcessor::handle_help(EXIT_SUCCESS);
    break;
  case 'b':
    CmdLineArgProcessor::handle_breadth_first();
    break;
  case 'd':
    CmdLineArgProcessor::handle_depth_first();
    break;
  case 'i':
    CmdLineArgProcessor::handle_iterative_deepening();
    break;
  case 'u':
    CmdLineArgProcessor::handle_uniform_cost();
    break;
  case 's':
    CmdLineArgProcessor::handle_best_first();
    break;
  case '1':
    CmdLineArgProcessor::handle_a_star_1();
    break;
  case '2':
    CmdLineArgProcessor::handle_a_star_2();
    break;
  case '3':
    CmdLineArgProcessor::handle_a_star_3();
    break;
  case 'm':
    CmdLineArgProcessor::handle_max_iterations();
    break;
  case '?':
    CmdLineArgProcessor::print_err_msg("missing option arg or bad option");
    break;
  default:
    CmdLineArgProcessor::print_err_msg("uknown error processing cmd line");
    break;
  }
}

void CmdLineArgProcessor::print_err_msg (const std::string& err_msg) {
  std::cerr << "ERROR: " << err_msg << std::endl << std::endl;
  CmdLineArgProcessor::handle_help(EXIT_FAILURE);
}

/*******************************************************************************
* STATIC OPTION HANDLERS
*******************************************************************************/

void CmdLineArgProcessor::handle_help (int exit_code) {
  std::cout << "USAGE" << std::endl;
  std::cout << "  " << CmdLineArgProcessor::program_name << "  "
            << "-h" << std::endl;
  std::cout << "  " << CmdLineArgProcessor::program_name << "  "
            << "[-b|-d|-i|-u|-s|-1|-2|-3]  [-m <num>]" << std::endl << "          "
            << "<start_board>  <goal_board>" << std::endl;
  std::cout << "ARGUMENTS" << std::endl;
  std::cout << "  " << "<start_board>" << std::endl << "      "
            << "starting board: a 3x3 with 0-8 (0 is empty), e.g. \"134862705\"" << std::endl;
  std::cout << "  " << "<goal_board>" << std::endl << "      "
            << "winning/goal board: a 3x3 with 0-8 (0 is empty), e.g. \"123804765\"" << std::endl;
  std::cout << "OPTIONS" << std::endl;
  std::cout << "  " << "-h, --help" << std::endl << "      "
            << "print this help message" << std::endl;
  std::cout << "  " << "-b, --breadth-first" << std::endl << "      "
            << "find solution using breadth-first search (default)" << std::endl;
  std::cout << "  " << "-d, --depth-first" << std::endl << "      "
            << "find solution using depth-first search" << std::endl;
  std::cout << "  " << "-i, --iterative-deepening" << std::endl << "      "
            << "find solution using depth-first search with iterative deepening" << std::endl;
  std::cout << "  " << "-u, --uniform-cost" << std::endl << "      "
            << "find solution using uniform-cost search" << std::endl;
  std::cout << "  " << "-s, --best-first" << std::endl << "      "
            << "find solution using best-first search (num squares in correct pos)" << std::endl;
  std::cout << "  " << "-1, --a-star-1" << std::endl << "      "
            << "find solution using A*1 search (num squares in correct pos)" << std::endl;
  std::cout << "  " << "-2, --a-star-2" << std::endl << "      "
            << "find solution using A*2 search (sum of manhattan dists)" << std::endl;
  std::cout << "  " << "-3, --a-star-3" << std::endl << "      "
            << "find solution using A*3 search (custom heuristic)" << std::endl;
  std::cout << "  " << "-m <num>, --max-iterations=<num>" << std::endl << "      "
            << "specify max num iterations to use while searching" << std::endl;
  exit(exit_code);
}

void CmdLineArgProcessor::handle_breadth_first () {
  std::cout << "option b" << std::endl;
}

void CmdLineArgProcessor::handle_depth_first () {
  std::cout << "option d" << std::endl;
}

void CmdLineArgProcessor::handle_iterative_deepening () {
  std::cout << "option i" << std::endl;
}

void CmdLineArgProcessor::handle_uniform_cost () {
  std::cout << "option u" << std::endl;
}

void CmdLineArgProcessor::handle_best_first () {
  std::cout << "option s" << std::endl;
}

void CmdLineArgProcessor::handle_a_star_1 () {
  std::cout << "option 1" << std::endl;
}

void CmdLineArgProcessor::handle_a_star_2 () {
  std::cout << "option 2" << std::endl;
}

void CmdLineArgProcessor::handle_a_star_3 () {
  std::cout << "option 3" << std::endl;
}

void CmdLineArgProcessor::handle_max_iterations () {
  std::cout << "option m: " << optarg << std::endl;
}

