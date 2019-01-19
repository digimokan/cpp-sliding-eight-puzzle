/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <functional>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Move.hpp"
#include "MoveCostConst.hpp"
#include "MoveDir.hpp"
#include "SearchGraph.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("graph with root only") {

  std::shared_ptr<SearchNode> root{ std::make_shared<SearchNode>(Board{"012345678"}) };
  SearchGraph graph{ root, std::make_shared<MoveCostConst>() };

  SUBCASE("max_depth of 0") {
    CHECK_EQ(graph.get_max_depth(), 0);
  }

}

TEST_CASE("graph of depth 1") {

  Board BA{ Board{"123456780"} };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  SearchGraph graph{ SNA, std::make_shared<MoveCostConst>() };

  SUBCASE("expand() creates correct children") {
    auto verify_parent = [BA] (std::shared_ptr<SearchNode> node) {
      CHECK_UNARY(node->get_parent().has_value());
      CHECK_UNARY(node->get_parent().value()->get_board() == BA);
    };
    graph.expand(SNA, verify_parent);
    CHECK_EQ(graph.get_max_depth(), 1);
  }

}

