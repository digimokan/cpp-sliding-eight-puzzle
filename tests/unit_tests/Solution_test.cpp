/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <functional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("single-step solution") {

  Board BA{ Board{"134862705"} };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  Solution sol{1, 2, SNA};

  SUBCASE("contains 1 step") {
    size_t num_steps{0};
    auto act = [&num_steps] (auto node) { num_steps++; };
    sol.for_each_step(act);
    CHECK_EQ(num_steps, 1);
    CHECK_EQ(sol.get_num_steps(), 1);
  }

  SUBCASE("get_total_cost()") {
    CHECK_EQ(sol.get_total_cost(), 0);
  }

  SUBCASE("get_time_complexity()") {
    CHECK_EQ(sol.get_time_complexity(), 1);
  }

  SUBCASE("get_space_complexity()") {
    CHECK_EQ(sol.get_space_complexity(), 2);
  }

}

TEST_CASE("four-step solution") {

/*******************************************************************************
  Solution: BA --> BB --> BE --> BK
*******************************************************************************/

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BE{ Board{"104832765"} };
  Board BK{ Board{"140832765"} };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{BB, MoveDir::UP, 6}, SNA) };
  std::shared_ptr<SearchNode> SNE{ std::make_shared<SearchNode>(Move{BE, MoveDir::UP, 3}, SNB) };
  std::shared_ptr<SearchNode> SNK{ std::make_shared<SearchNode>(Move{BK, MoveDir::RIGHT, 4}, SNE) };
  SNA->add_child(SNB);
  SNB->add_child(SNE);
  SNE->add_child(SNK);
  Solution sol{100, 200, SNK};

  SUBCASE("contains 4 steps") {
    size_t num_steps{0};
    auto act = [&num_steps] (auto node) { num_steps++; };
    sol.for_each_step(act);
    CHECK_EQ(num_steps, 4);
    CHECK_EQ(sol.get_num_steps(), 4);
  }

  SUBCASE("iterated steps match correct search nodes") {
    std::array<size_t, 4> move_costs{ 0, 6, 3, 4 };
    size_t i{0};
    auto act = [&move_costs, &i] (auto node) { CHECK_EQ(node->get_move_cost(), move_costs.at(i)); i++; };
    sol.for_each_step(act);
  }

  SUBCASE("get_total_cost()") {
    CHECK_EQ(sol.get_total_cost(), 13);
  }

  SUBCASE("get_time_complexity()") {
    CHECK_EQ(sol.get_time_complexity(), 100);
  }

  SUBCASE("get_space_complexity()") {
    CHECK_EQ(sol.get_space_complexity(), 200);
  }

}

