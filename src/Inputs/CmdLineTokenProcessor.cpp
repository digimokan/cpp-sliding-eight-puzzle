/*******************************************************************************
module:   CmdLineTokenProcessor
author:   digimokan
date:     12 JAN 2019
purpose:  process program-input command-line tokens
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "CmdLineTokenProcessor.hpp"
#include "EstGoalCostAstarOne.hpp"
#include "EstGoalCostAstarThree.hpp"
#include "EstGoalCostAstarTwo.hpp"
#include "EstGoalCostMisplSq.hpp"
#include "EstGoalCostUniform.hpp"
#include "MoveCostConst.hpp"
#include "MoveCostIface.hpp"
#include "MoveCostSqVal.hpp"
#include "SolverBFS.hpp"
#include "SolverDFS.hpp"
#include "SolverIDS.hpp"
#include "SolverIface.hpp"
#include "SolverInformed.hpp"
#include "SolverUninformed.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

CmdLineTokenProcessor::CmdLineTokenProcessor (int argc, char* argv[])
  : program_name{*argv},
    tokens{argv, argv + argc},
    short_opts{"hbdius123m:"},
    long_opts_map{
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
      {nullptr,               no_argument,       nullptr,  0}
    },
    move_cost{std::make_shared<MoveCostSqVal>()},
    solver_type{SolverType::BREADTH_FIRST}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::shared_ptr<SolverIface> CmdLineTokenProcessor::create_solver () {
  this->process_options();
  this->process_non_option_args();
  return this->make_solver_from_tokens();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void CmdLineTokenProcessor::process_options () {
  while (true) {
    const int opt = getopt_long(tokens.size(), tokens.data(), this->short_opts, this->long_opts_map.data(), nullptr);
    if (opt == -1)
      break;
    this->process_opt(opt);
  }
}

void CmdLineTokenProcessor::process_non_option_args () {
  if ((tokens.size() - optind) != 2) {
    this->print_err_msg("missing non-option argument");
  } else {
    std::cout << "<start_board>: " << tokens[optind] << std::endl;
    std::cout << "<goal_board>: " << tokens[optind + 1] << std::endl;
    this->start_board = Board{ tokens[optind] };
    this->goal_board = Board{ tokens[optind + 1] };
  }
}

void CmdLineTokenProcessor::process_opt (int opt) {
  switch (opt) {
  case 'h':
    this->handle_help(EXIT_SUCCESS);
    break;
  case 'b':
    this->handle_breadth_first();
    break;
  case 'd':
    this->handle_depth_first();
    break;
  case 'i':
    this->handle_iterative_deepening();
    break;
  case 'u':
    this->handle_uniform_cost();
    break;
  case 's':
    this->handle_best_first();
    break;
  case '1':
    this->handle_a_star_1();
    break;
  case '2':
    this->handle_a_star_2();
    break;
  case '3':
    this->handle_a_star_3();
    break;
  case 'm':
    this->handle_max_iterations();
    break;
  case '?':
    this->print_err_msg("missing option arg or bad option");
    break;
  default:
    this->print_err_msg("uknown error processing cmd line");
    break;
  }
}

void CmdLineTokenProcessor::print_err_msg (const std::string& err_msg) {
  std::cerr << "ERROR: " << err_msg << std::endl << std::endl;
  this->handle_help(EXIT_FAILURE);
}

std::shared_ptr<SolverIface> CmdLineTokenProcessor::make_solver_from_tokens () {
  std::shared_ptr<SolverIface> solver;
  switch (this->solver_type) {
    case SolverType::BREADTH_FIRST:
      solver = std::make_shared<SolverBFS>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::DEPTH_FIRST:
      solver = std::make_shared<SolverDFS>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::ITERATIVE_DEEPENING:
      solver = std::make_shared<SolverIDS>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::UNIFORM_COST:
      solver = std::make_shared<SolverUninformed<EstGoalCostUniform>>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::BEST_FIRST:
      solver = std::make_shared<SolverInformed<EstGoalCostMisplSq>>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::A_STAR_ONE:
      solver = std::make_shared<SolverInformed<EstGoalCostAstarOne>>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::A_STAR_TWO:
      solver = std::make_shared<SolverInformed<EstGoalCostAstarTwo>>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    case SolverType::A_STAR_THREE:
      solver = std::make_shared<SolverInformed<EstGoalCostAstarThree>>(
        this->start_board,
        this->goal_board,
        this->move_cost
      );
      break;
    default:
      assert(false);
      break;
  }
  return solver;
}

/*******************************************************************************
* STATIC OPTION HANDLERS
*******************************************************************************/

void CmdLineTokenProcessor::handle_help (int exit_code) {
  std::cout << "USAGE" << std::endl;
  std::cout << "  " << this->program_name << "  "
            << "-h" << std::endl;
  std::cout << "  " << this->program_name << "  "
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
            << "find solution using g(n) uniform-cost search" << std::endl;
  std::cout << "  " << "-s, --best-first" << std::endl << "      "
            << "find solution using h(n) num misplaced tiles" << std::endl;
  std::cout << "  " << "-1, --a-star-1" << std::endl << "      "
            << "find solution using A*1 search (g(n) + h(n) num misplaced tiles)" << std::endl;
  std::cout << "  " << "-2, --a-star-2" << std::endl << "      "
            << "find solution using A*2 search (g(n) + h(n) sum manhattan dists)" << std::endl;
  std::cout << "  " << "-3, --a-star-3" << std::endl << "      "
            << "find solution using A*3 search (g(n) + h(n) custom heuristic)" << std::endl;
  std::cout << "  " << "-m <num>, --max-iterations=<num>" << std::endl << "      "
            << "specify max num iterations to use while searching" << std::endl;
  exit(exit_code);
}

void CmdLineTokenProcessor::handle_breadth_first () {
  std::cout << "option b" << std::endl;
  this->solver_type = SolverType::BREADTH_FIRST;
}

void CmdLineTokenProcessor::handle_depth_first () {
  std::cout << "option d" << std::endl;
  this->solver_type = SolverType::DEPTH_FIRST;
}

void CmdLineTokenProcessor::handle_iterative_deepening () {
  std::cout << "option i" << std::endl;
  this->solver_type = SolverType::ITERATIVE_DEEPENING;
}

void CmdLineTokenProcessor::handle_uniform_cost () {
  std::cout << "option u" << std::endl;
  this->solver_type = SolverType::UNIFORM_COST;
}

void CmdLineTokenProcessor::handle_best_first () {
  std::cout << "option s" << std::endl;
  this->solver_type = SolverType::BEST_FIRST;
}

void CmdLineTokenProcessor::handle_a_star_1 () {
  std::cout << "option 1" << std::endl;
  this->solver_type = SolverType::A_STAR_ONE;
}

void CmdLineTokenProcessor::handle_a_star_2 () {
  std::cout << "option 2" << std::endl;
  this->solver_type = SolverType::A_STAR_TWO;
}

void CmdLineTokenProcessor::handle_a_star_3 () {
  std::cout << "option 3" << std::endl;
  this->solver_type = SolverType::A_STAR_THREE;
}

void CmdLineTokenProcessor::handle_max_iterations () {
  std::cout << "option m: " << optarg << std::endl;
}

