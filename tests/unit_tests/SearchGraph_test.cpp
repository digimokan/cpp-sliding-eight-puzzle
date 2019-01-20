/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <functional>
#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardHistory.hpp"
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

TEST_CASE("graph of depth 3") {
/*******************************************************************************
Level 0:
  BA has children BB, BC, BD
Level 1:
  BB has children BE, BF, BG
  BC has children BH
  BD has children BI
Level 2:
  BE has children BJ, BK
  BF has children BL, BM
  BG has children BN, BO
  BH has children BP, BQ
  BI has children BR, BS
*******************************************************************************/
  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  Board BD{ Board{"134862750"} };
  Board BE{ Board{"104832765"} };
  Board BF{ Board{"134082765"} };
  Board BG{ Board{"134820765"} };
  Board BH{ Board{"134062875"} };
  Board BI{ Board{"134860752"} };
  Board BJ{ Board{"014832765"} };
  Board BK{ Board{"140832765"} };
  Board BL{ Board{"034182765"} };
  Board BM{ Board{"134782065"} };
  Board BN{ Board{"130824765"} };
  Board BO{ Board{"134825760"} };
  Board BP{ Board{"034162875"} };
  Board BQ{ Board{"134602875"} };
  Board BR{ Board{"130864752"} };
  Board BS{ Board{"134806752"} };

  BoardHistory history{};
  std::shared_ptr<SearchNode> root{ std::make_shared<SearchNode>(BA) };
  SearchGraph graph{ root, std::make_shared<MoveCostConst>() };
  history.add(root);

  SUBCASE("expand() to depth 1") {
    auto exp_level_0 = [&history] (auto node) {
      history.add(node);
    };
    graph.expand(root, exp_level_0);
    CHECK_EQ(graph.get_max_depth(), 1);
    CHECK_EQ(history.get_size(), 4);
    CHECK_UNARY(history.contains(BA));
    CHECK_UNARY(history.contains(BB));
    CHECK_UNARY(history.contains(BC));
    CHECK_UNARY(history.contains(BD));
  }

  SUBCASE("expand() to depth 2") {

    std::list<std::shared_ptr<SearchNode>> level_1_nodes;
    auto exp_level_0 = [&history, &level_1_nodes] (auto node) {
      history.add(node);
      level_1_nodes.push_back(node);
    };
    auto exp_level_1 = [&history] (auto node) {
      if (history.not_contains(node->get_board()))
        history.add(node);
    };
    graph.expand(root, exp_level_0);
    for (const auto& node: level_1_nodes)
      graph.expand(node, exp_level_1);
    CHECK_EQ(graph.get_max_depth(), 2);
    CHECK_EQ(history.get_size(), 9);
    CHECK_UNARY(history.contains(BA));
    CHECK_UNARY(history.contains(BB));
    CHECK_UNARY(history.contains(BC));
    CHECK_UNARY(history.contains(BD));
    CHECK_UNARY(history.contains(BE));
    CHECK_UNARY(history.contains(BF));
    CHECK_UNARY(history.contains(BG));
    CHECK_UNARY(history.contains(BH));
    CHECK_UNARY(history.contains(BI));
  }

  SUBCASE("expand() to depth 3") {

    std::list<std::shared_ptr<SearchNode>> level_1_nodes;
    auto exp_level_0 = [&history, &level_1_nodes] (auto node) {
      history.add(node);
      level_1_nodes.push_back(node);
    };
    std::list<std::shared_ptr<SearchNode>> level_2_nodes;
    auto exp_level_1 = [&history, &level_2_nodes] (auto node) {
      if (history.not_contains(node->get_board())) {
        history.add(node);
        level_2_nodes.push_back(node);
      }
    };
    std::list<std::shared_ptr<SearchNode>> level_3_nodes;
    auto exp_level_2 = [&history, &level_3_nodes] (auto node) {
      if (history.not_contains(node->get_board())) {
        history.add(node);
        level_3_nodes.push_back(node);
      }
    };
    graph.expand(root, exp_level_0);
    for (const auto& node: level_1_nodes)
      graph.expand(node, exp_level_1);
    for (const auto& node: level_2_nodes) {
      graph.expand(node, exp_level_2);
    }
    CHECK_EQ(graph.get_max_depth(), 3);
    CHECK_EQ(history.get_size(), 19);
    CHECK_EQ(level_1_nodes.size(), 3);
    CHECK_EQ(level_2_nodes.size(), 5);
    CHECK_EQ(level_3_nodes.size(), 10);
    CHECK_UNARY(history.contains(BA));
    CHECK_UNARY(history.contains(BB));
    CHECK_UNARY(history.contains(BC));
    CHECK_UNARY(history.contains(BD));
    CHECK_UNARY(history.contains(BE));
    CHECK_UNARY(history.contains(BF));
    CHECK_UNARY(history.contains(BG));
    CHECK_UNARY(history.contains(BH));
    CHECK_UNARY(history.contains(BI));
    CHECK_UNARY(history.contains(BJ));
    CHECK_UNARY(history.contains(BK));
    CHECK_UNARY(history.contains(BL));
    CHECK_UNARY(history.contains(BM));
    CHECK_UNARY(history.contains(BN));
    CHECK_UNARY(history.contains(BO));
    CHECK_UNARY(history.contains(BP));
    CHECK_UNARY(history.contains(BQ));
    CHECK_UNARY(history.contains(BR));
    CHECK_UNARY(history.contains(BS));
  }

}

