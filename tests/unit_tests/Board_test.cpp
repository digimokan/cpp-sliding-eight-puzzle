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

