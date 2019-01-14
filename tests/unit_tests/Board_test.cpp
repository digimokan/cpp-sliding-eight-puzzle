/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("initialize board") {

  Board board{};

  SUBCASE("uninitialized board") {
    CHECK_UNARY(board.is_empty_board());
  }

  SUBCASE("init legal board") {
    Board::InitStatus status{ board.initialize("012345678") };
    CHECK_EQ(status, Board::InitStatus::SUCCESS);
  }

  SUBCASE("init illegal board: input string too short") {
    Board::InitStatus status{ board.initialize("01234567") };
    CHECK_EQ(status, Board::InitStatus::ERROR_INPUT_STR_TOO_SHORT);
  }

  SUBCASE("init illegal board: input string missing a square value") {
    Board::InitStatus status{ board.initialize("112345678") };
    CHECK_EQ(status, Board::InitStatus::ERROR_MISSING_EMPTY_SQUARE);
  }

}

TEST_CASE("assignment and equality") {

  Board a{};
  a.initialize("012345678");
  Board a_dup{};
  a_dup.initialize("012345678");
  Board b{};
  b.initialize("876543210");
  Board b_dup{};
  b_dup.initialize("876543210");

  SUBCASE("equality") {
    CHECK_UNARY(a == a_dup);
    CHECK_UNARY(a != b);
    CHECK_UNARY_FALSE(a == b);
  }

  SUBCASE("copy assignment") {
    a = b;
    CHECK_UNARY(a == b);
    CHECK_UNARY(a == b_dup);
    CHECK_UNARY(a != a_dup);
  }

  SUBCASE("copy construct") {
    Board acp{a};
    CHECK_UNARY(acp == a);
    CHECK_UNARY(acp == a_dup);
    CHECK_UNARY(a == a_dup);
  }

}

