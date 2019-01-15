/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "MoveDir.hpp"

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

TEST_CASE("construct board") {

  Board inited_board{};
  inited_board.initialize("012345678");

  SUBCASE("construct lval board") {
    Board cboard{ "012345678" };
    CHECK_UNARY(cboard == inited_board);
  }

  SUBCASE("construct rval board") {
    CHECK_UNARY(inited_board == Board{"012345678"});
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

TEST_CASE("get_empty_square_pos()") {

  SUBCASE("valid empty squares") {
    Board top_left{ "012345678" };
    CHECK_EQ(top_left.get_empty_square_pos(), 0);
    Board top_center{ "102345678" };
    CHECK_EQ(top_center.get_empty_square_pos(), 1);
    Board top_right{ "120345678" };
    CHECK_EQ(top_right.get_empty_square_pos(), 2);
    Board mid_left{ "123045678" };
    CHECK_EQ(mid_left.get_empty_square_pos(), 3);
    Board mid_center{ "123405678" };
    CHECK_EQ(mid_center.get_empty_square_pos(), 4);
    Board mid_right{ "123450678" };
    CHECK_EQ(mid_right.get_empty_square_pos(), 5);
    Board bot_left{ "123456078" };
    CHECK_EQ(bot_left.get_empty_square_pos(), 6);
    Board bot_center{ "123456708" };
    CHECK_EQ(bot_center.get_empty_square_pos(), 7);
    Board bot_right{ "123456780" };
    CHECK_EQ(bot_right.get_empty_square_pos(), 8);
  }

}

TEST_CASE("get_square_val()") {

  Board board{"876543210"};

  SUBCASE("get top-left square") {
    CHECK_EQ(board.get_square_val(0), 8);
  }

  SUBCASE("get top-right square") {
    CHECK_EQ(board.get_square_val(2), 6);
  }

  SUBCASE("get mid-center square") {
    CHECK_EQ(board.get_square_val(4), 4);
  }

  SUBCASE("get bot-left square") {
    CHECK_EQ(board.get_square_val(6), 2);
  }

  SUBCASE("get bot-right square") {
    CHECK_EQ(board.get_square_val(8), 0);
  }

}

TEST_CASE("get_swap_pos()") {

  Board top_left{ "012345678" };
  Board mid_center{ "123405678" };
  Board bot_right{ "123456780" };

  SUBCASE("top-left empty, move down") {
    size_t pos{ top_left.get_swap_pos(MoveDir::DOWN) };
    CHECK_EQ(pos, 3);
  }

  SUBCASE("top-left empty, move right") {
    size_t pos{ top_left.get_swap_pos(MoveDir::RIGHT) };
    CHECK_EQ(pos, 1);
  }

  SUBCASE("mid-center empty, move up") {
    size_t pos{ mid_center.get_swap_pos(MoveDir::UP) };
    CHECK_EQ(pos, 1);
  }

  SUBCASE("mid-center empty, move down") {
    size_t pos{ mid_center.get_swap_pos(MoveDir::DOWN) };
    CHECK_EQ(pos, 7);
  }

  SUBCASE("mid-center empty, move left") {
    size_t pos{ mid_center.get_swap_pos(MoveDir::LEFT) };
    CHECK_EQ(pos, 3);
  }

  SUBCASE("mid-center empty, move right") {
    size_t pos{ mid_center.get_swap_pos(MoveDir::RIGHT) };
    CHECK_EQ(pos, 5);
  }

  SUBCASE("bot-right empty, move up") {
    size_t pos{ bot_right.get_swap_pos(MoveDir::UP) };
    CHECK_EQ(pos, 5);
  }

  SUBCASE("bot-right empty, move left") {
    size_t pos{ bot_right.get_swap_pos(MoveDir::LEFT) };
    CHECK_EQ(pos, 7);
  }

}

TEST_CASE("swap_squares()") {

  Board board{"876543210"};

  SUBCASE("swap top-left and bot-right") {
    board.swap_squares(0, 8);
    CHECK_UNARY(board == Board{"076543218"});
  }

  SUBCASE("swap top-left and top-center") {
    board.swap_squares(0, 1);
    CHECK_UNARY(board == Board{"786543210"});
  }

  SUBCASE("swap mid-left and mid-center") {
    board.swap_squares(3, 4);
    CHECK_UNARY(board == Board{"876453210"});
  }

  SUBCASE("swap mid-center and mid-right") {
    board.swap_squares(4, 5);
    CHECK_UNARY(board == Board{"876534210"});
  }

  SUBCASE("swap bot-center and bot-right") {
    board.swap_squares(7, 8);
    CHECK_UNARY(board == Board{"876543201"});
  }

  SUBCASE("swap top-left and mid-left") {
    board.swap_squares(0, 3);
    CHECK_UNARY(board == Board{"576843210"});
  }

  SUBCASE("swap top-center and mid-center") {
    board.swap_squares(1, 4);
    CHECK_UNARY(board == Board{"846573210"});
  }

  SUBCASE("swap mid-right and bot-right") {
    board.swap_squares(5, 8);
    CHECK_UNARY(board == Board{"876540213"});
  }

}

