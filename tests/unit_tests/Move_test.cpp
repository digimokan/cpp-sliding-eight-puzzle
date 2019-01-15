/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Move.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("equality") {

  Move move{Board{"012345678"}, MoveDir::DOWN, 1};
  Move move_dup{Board{"012345678"}, MoveDir::DOWN, 1};
  Move board_diff{Board{"876543210"}, MoveDir::DOWN, 1};
  Move dir_diff{Board{"012345678"}, MoveDir::RIGHT, 1};
  Move cost_diff{Board{"012345678"}, MoveDir::DOWN, 3};
  Move all_diff{Board{"876543210"}, MoveDir::RIGHT, 3};

  SUBCASE("equal moves") {
    CHECK_UNARY(move == move_dup);
    CHECK_UNARY_FALSE(move != move_dup);
  }

  SUBCASE("boards different") {
    CHECK_UNARY_FALSE(move == board_diff);
  }

  SUBCASE("move-directions different") {
    CHECK_UNARY_FALSE(move == dir_diff);
  }

  SUBCASE("costs different") {
    CHECK_UNARY_FALSE(move == cost_diff);
  }

  SUBCASE("all parts of move different") {
    CHECK_UNARY_FALSE(move == all_diff);
  }

}

