/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "MoveCostSqVal.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("calc move cost") {

  std::shared_ptr<MoveCostIface> sqval{ std::make_shared<MoveCostSqVal>() };
  Board board{ "876503214" };

  SUBCASE("calc cost of move up") {
    unsigned int cost{ sqval->calc_cost(board, MoveDir::UP) };
    CHECK_EQ(cost, 7);
  }

  SUBCASE("calc cost of move down") {
    unsigned int cost{ sqval->calc_cost(board, MoveDir::DOWN) };
    CHECK_EQ(cost, 1);
  }

  SUBCASE("calc cost of move left") {
    unsigned int cost{ sqval->calc_cost(board, MoveDir::LEFT) };
    CHECK_EQ(cost, 5);
  }

  SUBCASE("calc cost of move right") {
    unsigned int cost{ sqval->calc_cost(board, MoveDir::RIGHT) };
    CHECK_EQ(cost, 3);
  }

}

