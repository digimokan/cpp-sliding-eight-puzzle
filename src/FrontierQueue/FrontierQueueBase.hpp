/*******************************************************************************
module:   FrontierQueueBase
author:   digimokan
date:     17 JAN 2019
purpose:  base implementation for a "frontier queue" of a search graph
          --> tracks queue statistics
          --> queue type / usage implemented by FrontierQueueBase implementer
*******************************************************************************/

#ifndef FRONTIER_QUEUE_BASE_HPP
#define FRONTIER_QUEUE_BASE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "BoardMap.hpp"
#include "FrontierQueueIface.hpp"
#include "NodeSet.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueBase : public FrontierQueueIface {

public:

  // destructor
  ~FrontierQueueBase () override = default;

  // operators
  FrontierQueueBase (const FrontierQueueBase& in) = delete;
  FrontierQueueBase& operator= (const FrontierQueueBase& rh) = delete;
  FrontierQueueBase (FrontierQueueBase&& in) = delete;
  FrontierQueueBase& operator= (FrontierQueueBase&& rh) = delete;

  // base / derived methods
  void push (std::shared_ptr<SearchNode> node) final;
  std::shared_ptr<SearchNode> pop () final;
  bool contains (const Board& board) const final;
  bool not_contains (const Board& board) const final;
  std::optional<std::shared_ptr<SearchNode>> get_node (const Board& board) const final;
  void remove_node (std::shared_ptr<SearchNode> node) final;
  bool is_empty () const final;
  bool not_empty () const final;
  size_t get_current_queue_size () const final;
  size_t get_largest_queue_size () const final;
  size_t get_num_nodes_popped () const final;

protected:

  // constructors
  FrontierQueueBase ();

  // base / derived methods
  virtual void push_logic (std::shared_ptr<SearchNode>) = 0;
  virtual std::shared_ptr<SearchNode> pop_logic () = 0;
  virtual std::shared_ptr<SearchNode> peek_next_logic () const = 0;
  virtual size_t get_size_logic () const = 0;

private:

  // fields
  size_t current_queue_size;
  size_t largest_queue_size;
  size_t num_nodes_popped;
  NodeSet nodes_on_queue;
  BoardMap board_node_lookup;

  // helper methods
  void sync_node_addition (const std::shared_ptr<SearchNode>& node);
  void sync_node_removal (const std::shared_ptr<SearchNode>& node);
  void prune_removed_nodes ();

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BASE_HPP

