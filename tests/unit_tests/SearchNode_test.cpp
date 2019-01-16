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

#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("single node creation") {

  std::shared_ptr<SearchNode> root{ std::make_shared<SearchNode>(Board{"012345678"}) };

  SUBCASE("single root-node fields valid") {
    CHECK_UNARY_FALSE(root->get_parent());
    CHECK_EQ(root->get_depth(), 0);
    CHECK_EQ(root->get_height(), 0);
    CHECK_UNARY(root->get_board() == Board{"012345678"});
    CHECK_UNARY_FALSE(root->get_move_dir());
    CHECK_EQ(root->get_move_cost(), 0);
    CHECK_EQ(root->get_path_cost(), 0);
    CHECK_UNARY(root->is_root());
    CHECK_UNARY_FALSE(root->has_children());
    CHECK_UNARY(root->is_leaf());
  }

}

TEST_CASE("create tree with three nodes: root/child/grandchild") {

  std::shared_ptr<SearchNode> root{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> child{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, root) };
  root->add_child(child);
  std::shared_ptr<SearchNode> grandchild{ std::make_shared<SearchNode>(Move{Board{"120345678"}, MoveDir::RIGHT, 2}, child) };
  child->add_child(grandchild);

  SUBCASE("root-node fields valid") {
    CHECK_UNARY_FALSE(root->get_parent());
    CHECK_EQ(root->get_depth(), 0);
    CHECK_EQ(root->get_height(), 2);
    CHECK_UNARY(root->get_board() == Board{"012345678"});
    CHECK_UNARY_FALSE(root->get_move_dir());
    CHECK_EQ(root->get_move_cost(), 0);
    CHECK_EQ(root->get_path_cost(), 0);
    CHECK_UNARY(root->is_root());
    CHECK_UNARY(root->has_children());
    CHECK_UNARY_FALSE(root->is_leaf());
  }

  SUBCASE("child fields valid") {
    CHECK_EQ(child->get_parent(), root);
    CHECK_EQ(child->get_depth(), 1);
    CHECK_EQ(child->get_height(), 1);
    CHECK_UNARY(child->get_board() == Board{"102345678"});
    CHECK_EQ(child->get_move_dir(), MoveDir::RIGHT);
    CHECK_EQ(child->get_move_cost(), 1);
    CHECK_EQ(child->get_path_cost(), 1);
    CHECK_UNARY_FALSE(child->is_root());
    CHECK_UNARY(child->has_children());
    CHECK_UNARY_FALSE(child->is_leaf());
  }

  SUBCASE("grandchild fields valid") {
    CHECK_EQ(grandchild->get_parent(), child);
    CHECK_EQ(grandchild->get_depth(), 2);
    CHECK_EQ(grandchild->get_height(), 0);
    CHECK_UNARY(grandchild->get_board() == Board{"120345678"});
    CHECK_EQ(grandchild->get_move_dir(), MoveDir::RIGHT);
    CHECK_EQ(grandchild->get_move_cost(), 2);
    CHECK_EQ(grandchild->get_path_cost(), 3);
    CHECK_UNARY_FALSE(grandchild->is_root());
    CHECK_UNARY_FALSE(grandchild->has_children());
    CHECK_UNARY(grandchild->is_leaf());
  }

}

