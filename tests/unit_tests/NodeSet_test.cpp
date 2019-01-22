/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "NodeSet.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("add, remove, contains") {

  NodeSet node_set{};
  Board BA{ "123405678" };
  Board BB{ "876543210" };
  Board BC{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(BB) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(BC) };

  SUBCASE("empty set, contains fails") {
    CHECK_FALSE(node_set.contains(SNA));
    CHECK_UNARY(node_set.not_contains(SNA));
  }

  SUBCASE("add single node") {
    node_set.add(SNA);
    CHECK_UNARY(node_set.contains(SNA));
    CHECK_FALSE(node_set.not_contains(SNA));
  }

  SUBCASE("add/remove single node") {
    node_set.add(SNA);
    node_set.remove(SNA);
    CHECK_FALSE(node_set.contains(SNA));
    CHECK_UNARY(node_set.not_contains(SNA));
  }

  SUBCASE("add three nodes") {
    node_set.add(SNA);
    node_set.add(SNB);
    node_set.add(SNC);
    CHECK_UNARY(node_set.contains(SNA));
    CHECK_UNARY(node_set.contains(SNB));
    CHECK_UNARY(node_set.contains(SNC));
  }

  SUBCASE("add three nodes, remove three nodes") {
    node_set.add(SNA);
    node_set.add(SNB);
    node_set.add(SNC);
    node_set.remove(SNA);
    node_set.remove(SNB);
    node_set.remove(SNC);
    CHECK_FALSE(node_set.contains(SNA));
    CHECK_FALSE(node_set.contains(SNB));
    CHECK_FALSE(node_set.contains(SNC));
  }

  SUBCASE("repeated add/remove of same node") {
    node_set.add(SNA);
    CHECK_UNARY(node_set.contains(SNA));
    node_set.remove(SNA);
    CHECK_FALSE(node_set.contains(SNA));
    node_set.add(SNA);
    CHECK_UNARY(node_set.contains(SNA));
    node_set.remove(SNA);
    CHECK_FALSE(node_set.contains(SNA));
    node_set.add(SNA);
    CHECK_UNARY(node_set.contains(SNA));
    node_set.remove(SNA);
    CHECK_FALSE(node_set.contains(SNA));
  }

}

