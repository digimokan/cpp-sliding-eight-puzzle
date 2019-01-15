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
#include "MoveCostUniform.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("calc move cost") {

  std::shared_ptr<MoveCostIface> uniform{ std::make_shared<MoveCostUniform>() };
  Board board{ "012345678" };

  SUBCASE("calc cost of move down") {
    unsigned int cost{ uniform->calc_cost(board, MoveDir::DOWN) };
    CHECK_EQ(cost, 1);
  }

  SUBCASE("calc cost of move right") {
    unsigned int cost{ uniform->calc_cost(board, MoveDir::RIGHT) };
    CHECK_EQ(cost, 1);
  }

}

