/*******************************************************************************
module:   SearchNode
author:   digimokan
date:     15 JAN 2019
purpose:  a node in a search tree, comprising these elements:
            a) the board state
            b) the move that produced this board state (including its cost)
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cstddef>
#include <list>
#include <memory>
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/

SearchNode::SearchNode (const Move& move, const std::shared_ptr<SearchNode>& in_parent)
  : parent{in_parent},
    depth{in_parent->get_depth() + 1},
    height{0},
    board{move.get_board()},
    move_dir{move.get_move_dir()},
    move_cost{move.get_cost()},
    path_cost{in_parent->get_path_cost() + move.get_cost()}
  { }

SearchNode::SearchNode (const Board& board)
  : parent{std::nullopt},
    depth{0},
    height{0},
    board{board},
    move_dir{std::nullopt},
    move_cost{0},
    path_cost{0}
  { }

/*******************************************************************************
* GET/SET METHODS
*******************************************************************************/

std::optional<std::shared_ptr<SearchNode>> SearchNode::get_parent () const {
  return this->parent;
}

size_t SearchNode::get_depth () const {
  return this->depth;
}

size_t SearchNode::get_height () const {
  return this->height;
}

void SearchNode::update_height (size_t new_child_height) {
  this->height = std::max(new_child_height + 1, this->height);
  if (this->parent.has_value())
    this->parent.value()->update_height(this->height);
}

Board SearchNode::get_board () const {
  return this->board;
}

std::optional<MoveDir> SearchNode::get_move_dir () const {
  return this->move_dir;
}

unsigned int SearchNode::get_move_cost () const {
  return this->move_cost;
}

unsigned int SearchNode::get_path_cost () const {
  return this->path_cost;
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void SearchNode::add_child (const std::shared_ptr<SearchNode>& child) {
  this->children.push_back(child);
  this->update_height(child->get_height());
}

bool SearchNode::is_root () const {
  return (! this->parent.has_value());
}

bool SearchNode::has_children () const {
  return (! this->children.empty());
}

bool SearchNode::is_leaf () const {
  return this->children.empty();
}

