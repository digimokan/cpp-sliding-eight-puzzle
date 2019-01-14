/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Square.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("getting and setting legal value") {

  Square square{};

  SUBCASE("uninitialized square") {
    CHECK_EQ(square.get_val(), 0);
    CHECK_UNARY(square.is_empty());
  }

  SUBCASE("set/get legal value") {
    square.set_val(8);
    CHECK_EQ(square.get_val(), 8);
  }

}

TEST_CASE("assignment and equality") {

  Square sqa{0};
  Square sqa_dup{0};
  Square sqb{1};

  SUBCASE("equality") {
    CHECK_UNARY(sqa == sqa_dup);
    CHECK_UNARY(sqa != sqb);
    CHECK_UNARY_FALSE(sqa == sqb);
  }

  SUBCASE("copy assignment") {
    sqa = sqb;
    CHECK_EQ(sqa.get_val(), 1);
    CHECK_EQ(sqb.get_val(), 1);
  }

  SUBCASE("copy construct") {
    Square scp{sqb};
    CHECK_EQ(scp.get_val(), 1);
    CHECK_EQ(sqb.get_val(), 1);
  }

}

