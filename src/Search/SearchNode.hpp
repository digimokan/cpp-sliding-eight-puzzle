/*******************************************************************************
module:   SearchNode
author:   digimokan
date:     15 JAN 2019
purpose:  a node in a search tree, comprising these elements:
            a) the board state
            b) the move that produced this board state (including its cost)
*******************************************************************************/

#ifndef SEARCH_NODE_HPP
#define SEARCH_NODE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <list>
#include <memory>
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Move;
enum class MoveDir;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SearchNode {

public:

  // constructors
  SearchNode () = delete;
  SearchNode (const Move& move, const std::shared_ptr<SearchNode>& in_parent);
  explicit SearchNode (const Board& board);

  // destructor
  ~SearchNode () = default;

  // operators
  SearchNode (const SearchNode& in) = default;
  SearchNode& operator= (const SearchNode& rh) = default;
  SearchNode (SearchNode&& in) = default;
  SearchNode& operator= (SearchNode&& rh) = default;

  // get/set methods
  std::optional<std::shared_ptr<SearchNode>> get_parent () const;
  void set_parent (std::optional<std::shared_ptr<SearchNode>>);
  size_t get_depth () const;
  size_t get_height () const;
  void update_height ();
  Board get_board () const;
  std::optional<MoveDir> get_move_dir () const;
  unsigned int get_move_cost () const;
  unsigned int get_path_cost () const;

  // specialized methods
  void add_child (const std::shared_ptr<SearchNode>& child);
  void remove_child (const std::weak_ptr<SearchNode>& child);
  bool is_root () const;
  bool has_children () const;
  bool is_leaf () const;

private:

  // fields
  std::optional<std::shared_ptr<SearchNode>> parent;
  std::list<std::weak_ptr<SearchNode>> children;
  size_t depth;
  size_t height;
  Board board;
  std::optional<MoveDir> move_dir;
  unsigned int move_cost;
  unsigned int path_cost;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SEARCH_NODE_HPP

