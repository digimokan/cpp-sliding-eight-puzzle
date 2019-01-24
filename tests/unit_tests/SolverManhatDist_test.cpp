/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <functional>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostManhatDist.hpp"
#include "MoveCostSqVal.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"
#include "SolverInformed.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("goal_board == start_board (1-step solution)") {

  constexpr size_t num_steps{ 1 };
  constexpr size_t path_cost{ 0 };
  constexpr size_t num_fq_nodes_popped{ 1 };
  constexpr size_t max_fq_size{ 1 };
  std::array<Board, num_steps> boards{
    Board{"123804765"}
  };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{
    std::nullopt
  };
  std::array<unsigned int, num_steps> move_costs{
    0
  };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(num_steps - 1), move_cost};
  size_t i{0};
  auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
    CHECK_UNARY(node->get_board() == boards.at(i));
    CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
    CHECK_EQ(node->get_move_cost(), move_costs.at(i));
    i++;
  };
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  solution.for_each_step(act);
  CHECK_EQ(solution.get_total_cost(), path_cost);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

TEST_CASE("2-step solution") {

  constexpr size_t num_steps{ 2 };
  constexpr size_t path_cost{ 4 };
  constexpr size_t num_fq_nodes_popped{ 2 };
  constexpr size_t max_fq_size{ 4 };
  std::array<Board, num_steps> boards{
    Board{"123804765"}, Board{"123840765"}
  };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{
    std::nullopt, MoveDir::RIGHT
  };
  std::array<unsigned int, num_steps> move_costs{
    0, 4
  };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(num_steps - 1), move_cost};
  size_t i{0};
  auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
    CHECK_UNARY(node->get_board() == boards.at(i));
    CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
    CHECK_EQ(node->get_move_cost(), move_costs.at(i));
    i++;
  };
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  solution.for_each_step(act);
  CHECK_EQ(solution.get_total_cost(), path_cost);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

TEST_CASE("3-step solution") {

  constexpr size_t num_steps{ 3 };
  constexpr size_t path_cost{ 9 };
  constexpr size_t num_fq_nodes_popped{ 3 };
  constexpr size_t max_fq_size{ 5 };
  std::array<Board, num_steps> boards{
    Board{"123804765"}, Board{"123840765"}, Board{"123845760"}
  };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{
    std::nullopt, MoveDir::RIGHT, MoveDir::DOWN
  };
  std::array<unsigned int, num_steps> move_costs{
    0, 4, 5
  };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(num_steps - 1), move_cost};
  size_t i{0};
  auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
    CHECK_UNARY(node->get_board() == boards.at(i));
    CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
    CHECK_EQ(node->get_move_cost(), move_costs.at(i));
    i++;
  };
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  solution.for_each_step(act);
  CHECK_EQ(solution.get_total_cost(), path_cost);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

TEST_CASE("6-step \"easy\" solution") {

  constexpr size_t num_steps{ 6 };
  constexpr size_t path_cost{ 17 };
  constexpr size_t num_fq_nodes_popped{ 6 };
  constexpr size_t max_fq_size{ 7 };
  std::array<Board, num_steps> boards{
    Board{"134862705"}, Board{"134802765"}, Board{"134820765"},
    Board{"130824765"}, Board{"103824765"}, Board{"123804765"}
  };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{
    std::nullopt, MoveDir::UP, MoveDir::RIGHT,
    MoveDir::UP, MoveDir::LEFT, MoveDir::DOWN
  };
  std::array<unsigned int, num_steps> move_costs{
    0, 6, 2,
    4, 3, 2
  };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(num_steps - 1), move_cost};
  size_t i{0};
  auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
    CHECK_UNARY(node->get_board() == boards.at(i));
    CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
    CHECK_EQ(node->get_move_cost(), move_costs.at(i));
    i++;
  };
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  solution.for_each_step(act);
  CHECK_EQ(solution.get_total_cost(), path_cost);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

TEST_CASE("\"medium\" solution") {

  constexpr size_t num_steps{ 18 };
  constexpr size_t num_fq_nodes_popped{ 44 };
  constexpr size_t max_fq_size{ 40 };
  std::array<Board, 2> boards{ Board{"281043765"}, Board{"123804765"} };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(1), move_cost};
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

TEST_CASE("\"hard\" solution") {

  constexpr size_t num_steps{ 57 };
  constexpr size_t num_fq_nodes_popped{ 125 };
  constexpr size_t max_fq_size{ 109 };
  std::array<Board, 2> boards{ Board{"567408321"}, Board{"123804765"} };
  auto move_cost{ std::make_shared<MoveCostSqVal>() };
  SolverInformed<EstGoalCostManhatDist> solver{ boards.at(0), boards.at(1), move_cost};
  auto solution{ solver.solve() };

  CHECK_UNARY(solution.is_solved());
  CHECK_EQ(solution.get_num_steps(), num_steps);
  CHECK_EQ(solution.get_time_complexity(), num_fq_nodes_popped);
  CHECK_EQ(solution.get_space_complexity(), max_fq_size);

}

