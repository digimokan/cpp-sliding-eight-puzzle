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
#include "EstGoalCostUniform.hpp"
#include "MoveCostSqVal.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"
#include "SolverFn.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("goal_board == start_board (1-step solution)") {

  SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ Board{"123804765"}, Board{"123804765"}};
  auto solution{ solver.solve() };
  constexpr size_t num_steps{ 1 };

  SUBCASE("returns valid optional<Solution>") {
    CHECK_UNARY(solution.is_solved());
  }

  SUBCASE("contains correct num steps") {
    CHECK_EQ(solution.get_num_steps(), num_steps);
  }

  SUBCASE("contains correct steps") {
    std::array<Board, num_steps> boards{ Board{"123804765"} };
    std::array<std::optional<MoveDir>, num_steps> move_dirs{ std::nullopt };
    std::array<unsigned int, num_steps> move_costs{ 0 };
    size_t i{0};
    auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
      CHECK_UNARY(node->get_board() == boards.at(i));
      CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
      CHECK_EQ(node->get_move_cost(), move_costs.at(i));
      i++;
    };
    solution.for_each_step(act);
  }

  SUBCASE("get_total_cost()") {
    CHECK_EQ(solution.get_total_cost(), 0);
  }

  SUBCASE("get_time_complexity()") {
    CHECK_EQ(solution.get_time_complexity(), 1);
  }

  SUBCASE("get_space_complexity()") {
    CHECK_EQ(solution.get_space_complexity(), 1);
  }

}

TEST_CASE("2-step solution") {

  Board BA{ "123804765" };
  Board BB{ "123840765" };
  constexpr size_t num_steps{ 2 };
  std::array<Board, num_steps> boards{ BA, BB };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{ std::nullopt, MoveDir::RIGHT };
  std::array<unsigned int, num_steps> move_costs{ 0, 4 };

  SUBCASE("returns valid optional<Solution>") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    CHECK_UNARY(solution.is_solved());
  }

  SUBCASE("contains correct num steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_num_steps(), num_steps);
  }

  SUBCASE("contains correct steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    size_t i{0};
    auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
      CHECK_UNARY(node->get_board() == boards.at(i));
      CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
      CHECK_EQ(node->get_move_cost(), move_costs.at(i));
      i++;
    };
    solution.for_each_step(act);
  }

  SUBCASE("get_total_cost()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_total_cost(), 4);
  }

  SUBCASE("get_time_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_time_complexity(), 4);
  }

  SUBCASE("get_space_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BB };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_space_complexity(), 5);
  }

}

TEST_CASE("3-step solution") {

  Board BA{ "123804765" };
  Board BB{ "123840765" };
  Board BC{ "123845760" };
  constexpr size_t num_steps{ 3 };
  std::array<Board, num_steps> boards{ BA, BB, BC };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{ std::nullopt, MoveDir::RIGHT, MoveDir::DOWN };
  std::array<unsigned int, num_steps> move_costs{ 0, 4, 5 };

  SUBCASE("returns valid optional<Solution>") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    CHECK_UNARY(solution.is_solved());
  }

  SUBCASE("contains correct num steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_num_steps(), num_steps);
  }

  SUBCASE("contains correct steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    size_t i{0};
    auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
      CHECK_UNARY(node->get_board() == boards.at(i));
      CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
      CHECK_EQ(node->get_move_cost(), move_costs.at(i));
      i++;
    };
    solution.for_each_step(act);
  }

  SUBCASE("get_total_cost()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_total_cost(), 9);
  }

  SUBCASE("get_time_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_time_complexity(), 11);
  }

  SUBCASE("get_space_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BC };
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_space_complexity(), 9);
  }

}

TEST_CASE("6-step \"easy\" solution") {

  Board BA{ "134862705" };
  Board BB{ "134802765" };
  Board BC{ "134820765" };
  Board BD{ "130824765" };
  Board BE{ "103824765" };
  Board BF{ "123804765" };
  constexpr size_t num_steps{ 6 };
  std::array<Board, num_steps> boards{ BA, BB, BC, BD, BE, BF };
  std::array<std::optional<MoveDir>, num_steps> move_dirs{
    std::nullopt, MoveDir::UP, MoveDir::RIGHT,
    MoveDir::UP, MoveDir::LEFT, MoveDir::DOWN

  };
  std::array<unsigned int, num_steps> move_costs{ 0, 6, 2, 4, 3, 2 };

  SUBCASE("returns valid optional<Solution>") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    CHECK_UNARY(solution.is_solved());
  }

  SUBCASE("contains correct num steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_num_steps(), num_steps);
  }

  SUBCASE("contains correct steps") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    size_t i{0};
    auto act = [&boards, &move_dirs, &move_costs, &i] (auto node) {
      CHECK_UNARY(node->get_board() == boards.at(i));
      CHECK_UNARY(node->get_move_dir() == move_dirs.at(i));
      CHECK_EQ(node->get_move_cost(), move_costs.at(i));
      i++;
    };
    solution.for_each_step(act);
  }

  SUBCASE("get_total_cost()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_total_cost(), 17);
  }

  SUBCASE("get_time_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_time_complexity(), 24);
  }

  SUBCASE("get_space_complexity()") {
    SolverFn<MoveCostSqVal, EstGoalCostUniform> solver{ BA, BF};
    auto solution{ solver.solve() };
    CHECK_EQ(solution.get_space_complexity(), 16);
  }

}

