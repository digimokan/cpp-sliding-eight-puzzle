/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Move.hpp"
#include "MoveCostSqVal.hpp"
#include "MoveDir.hpp"
#include "MoveGenerator.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("generate_moves(Board)") {

  MoveGenerator gen{ std::make_shared<MoveCostSqVal>() };

  SUBCASE("empty square in top-left") {
    std::list<Move> moves{ gen.generate_moves(Board{"012345678"}) };
    CHECK_EQ(moves.size(), 2);
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"102345678"}, MoveDir::RIGHT, 1}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"312045678"}, MoveDir::DOWN, 3}), moves.end());
  }

  SUBCASE("empty square in top-right") {
    std::list<Move> moves{ gen.generate_moves(Board{"120345678"}) };
    CHECK_EQ(moves.size(), 2);
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"102345678"}, MoveDir::LEFT, 2}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"125340678"}, MoveDir::DOWN, 5}), moves.end());
  }

  SUBCASE("empty square in mid-center") {
    std::list<Move> moves{ gen.generate_moves(Board{"123405678"}) };
    CHECK_EQ(moves.size(), 4);
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"103425678"}, MoveDir::UP, 2}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123475608"}, MoveDir::DOWN, 7}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123045678"}, MoveDir::LEFT, 4}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123450678"}, MoveDir::RIGHT, 5}), moves.end());
  }

  SUBCASE("empty square in bot-left") {
    std::list<Move> moves{ gen.generate_moves(Board{"123456078"}) };
    CHECK_EQ(moves.size(), 2);
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123056478"}, MoveDir::UP, 4}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123456708"}, MoveDir::RIGHT, 7}), moves.end());
  }

  SUBCASE("empty square in bot-right") {
    std::list<Move> moves{ gen.generate_moves(Board{"123456780"}) };
    CHECK_EQ(moves.size(), 2);
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123450786"}, MoveDir::UP, 6}), moves.end());
    CHECK_NE(std::find(moves.begin(), moves.end(), Move{Board{"123456708"}, MoveDir::LEFT, 8}), moves.end());
  }

}

