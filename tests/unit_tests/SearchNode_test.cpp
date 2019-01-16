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

TEST_CASE("create multi-branch, multi-level tree") {
/*******************************************************************************
        A
      / |
     B  C
       / \
      D  E
      |
      F
*******************************************************************************/

  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, A) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Move{Board{"312045678"}, MoveDir::DOWN, 3}, A) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Move{Board{"312405678"}, MoveDir::RIGHT, 4}, C) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Move{Board{"312645078"}, MoveDir::DOWN, 6}, C) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Move{Board{"302415678"}, MoveDir::UP, 1}, D) };
  A->add_child(B);
  A->add_child(C);
  C->add_child(D);
  C->add_child(E);
  D->add_child(F);

  SUBCASE("A-node fields valid") {
    CHECK_UNARY_FALSE(A->get_parent());
    CHECK_EQ(A->get_depth(), 0);
    CHECK_EQ(A->get_height(), 3);
    CHECK_UNARY(A->get_board() == Board{"012345678"});
    CHECK_UNARY_FALSE(A->get_move_dir());
    CHECK_EQ(A->get_move_cost(), 0);
    CHECK_EQ(A->get_path_cost(), 0);
    CHECK_UNARY(A->is_root());
    CHECK_UNARY(A->has_children());
    CHECK_UNARY_FALSE(A->is_leaf());
  }

  SUBCASE("B-node fields valid") {
    CHECK_EQ(B->get_parent(), A);
    CHECK_EQ(B->get_depth(), 1);
    CHECK_EQ(B->get_height(), 0);
    CHECK_UNARY(B->get_board() == Board{"102345678"});
    CHECK_EQ(B->get_move_dir(), MoveDir::RIGHT);
    CHECK_EQ(B->get_move_cost(), 1);
    CHECK_EQ(B->get_path_cost(), 1);
    CHECK_UNARY_FALSE(B->is_root());
    CHECK_UNARY_FALSE(B->has_children());
    CHECK_UNARY(B->is_leaf());
  }

  SUBCASE("C-node fields valid") {
    CHECK_EQ(C->get_parent(), A);
    CHECK_EQ(C->get_depth(), 1);
    CHECK_EQ(C->get_height(), 2);
    CHECK_UNARY(C->get_board() == Board{"312045678"});
    CHECK_EQ(C->get_move_dir(), MoveDir::DOWN);
    CHECK_EQ(C->get_move_cost(), 3);
    CHECK_EQ(C->get_path_cost(), 3);
    CHECK_UNARY_FALSE(C->is_root());
    CHECK_UNARY(C->has_children());
    CHECK_UNARY_FALSE(C->is_leaf());
  }

  SUBCASE("D-node fields valid") {
    CHECK_EQ(D->get_parent(), C);
    CHECK_EQ(D->get_depth(), 2);
    CHECK_EQ(D->get_height(), 1);
    CHECK_UNARY(D->get_board() == Board{"312405678"});
    CHECK_EQ(D->get_move_dir(), MoveDir::RIGHT);
    CHECK_EQ(D->get_move_cost(), 4);
    CHECK_EQ(D->get_path_cost(), 7);
    CHECK_UNARY_FALSE(D->is_root());
    CHECK_UNARY(D->has_children());
    CHECK_UNARY_FALSE(D->is_leaf());
  }

  SUBCASE("E-node fields valid") {
    CHECK_EQ(E->get_parent(), C);
    CHECK_EQ(E->get_depth(), 2);
    CHECK_EQ(E->get_height(), 0);
    CHECK_UNARY(E->get_board() == Board{"312645078"});
    CHECK_EQ(E->get_move_dir(), MoveDir::DOWN);
    CHECK_EQ(E->get_move_cost(), 6);
    CHECK_EQ(E->get_path_cost(), 9);
    CHECK_UNARY_FALSE(E->is_root());
    CHECK_UNARY_FALSE(E->has_children());
    CHECK_UNARY(E->is_leaf());
  }

  SUBCASE("F-node fields valid") {
    CHECK_EQ(F->get_parent(), D);
    CHECK_EQ(F->get_depth(), 3);
    CHECK_EQ(F->get_height(), 0);
    CHECK_UNARY(F->get_board() == Board{"302415678"});
    CHECK_EQ(F->get_move_dir(), MoveDir::UP);
    CHECK_EQ(F->get_move_cost(), 1);
    CHECK_EQ(F->get_path_cost(), 8);
    CHECK_UNARY_FALSE(F->is_root());
    CHECK_UNARY_FALSE(F->has_children());
    CHECK_UNARY(F->is_leaf());
  }

}

TEST_CASE("remove nodes in multi-branch, multi-level tree") {
/*******************************************************************************
        A
      / |
     B  C
       / \
      D  E
      |
      F
*******************************************************************************/

  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, A) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Move{Board{"312045678"}, MoveDir::DOWN, 3}, A) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Move{Board{"312405678"}, MoveDir::RIGHT, 4}, C) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Move{Board{"312645078"}, MoveDir::DOWN, 6}, C) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Move{Board{"302415678"}, MoveDir::UP, 1}, D) };
  A->add_child(B);
  A->add_child(C);
  C->add_child(D);
  C->add_child(E);
  D->add_child(F);

  SUBCASE("remove node F") {
    D->remove_child(F);
    CHECK_EQ(D->get_depth(), 2);
    CHECK_EQ(A->get_height(), 2);
    CHECK_EQ(D->get_path_cost(), 7);
    CHECK_UNARY(C->has_children());
    CHECK_UNARY_FALSE(D->has_children());
    CHECK_UNARY(D->is_leaf());
  }

  SUBCASE("remove node D") {
    C->remove_child(D);
    CHECK_EQ(C->get_depth(), 1);
    CHECK_EQ(A->get_height(), 2);
    CHECK_EQ(E->get_path_cost(), 9);
    CHECK_UNARY(C->has_children());
    CHECK_UNARY_FALSE(E->has_children());
    CHECK_UNARY(E->is_leaf());
  }

  SUBCASE("remove node C") {
    A->remove_child(C);
    CHECK_EQ(B->get_depth(), 1);
    CHECK_EQ(A->get_height(), 1);
    CHECK_EQ(B->get_path_cost(), 1);
    CHECK_UNARY(A->has_children());
    CHECK_UNARY_FALSE(B->has_children());
    CHECK_UNARY(B->is_leaf());
  }

  SUBCASE("remove node B") {
    A->remove_child(B);
    CHECK_EQ(F->get_depth(), 3);
    CHECK_EQ(A->get_height(), 3);
    CHECK_EQ(F->get_path_cost(), 8);
    CHECK_UNARY(A->has_children());
  }

}

