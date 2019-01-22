/*******************************************************************************
module:   FrontierQueueBfsDfsBase
author:   digimokan
date:     21 JAN 2019
purpose:  base STL-list-based queue impl common methods
*******************************************************************************/

#ifndef FRONTIER_QUEUE_BFS_DFS_BASE_HPP
#define FRONTIER_QUEUE_BFS_DFS_BASE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueBfsDfsBase : public FrontierQueueBase {

public:

  // destructor
  ~FrontierQueueBfsDfsBase () override = default;

  // operators
  FrontierQueueBfsDfsBase (const FrontierQueueBfsDfsBase& in) = default;
  FrontierQueueBfsDfsBase& operator= (const FrontierQueueBfsDfsBase& rh) = default;
  FrontierQueueBfsDfsBase (FrontierQueueBfsDfsBase&& in) = default;
  FrontierQueueBfsDfsBase& operator= (FrontierQueueBfsDfsBase&& rh) = default;

  // base / derived methods
  bool is_empty () const override;
  bool contains (const Board& board) const override;
  std::optional<std::shared_ptr<SearchNode>> get_node (const Board& board) const override;
  void remove_node (std::shared_ptr<SearchNode> node) override;
  size_t get_current_queue_size () const override;

protected:

  // constructors
  FrontierQueueBfsDfsBase () = default;

  // base / derived methods
  void push_logic (std::shared_ptr<SearchNode> node) override = 0;
  std::shared_ptr<SearchNode> pop_logic () override = 0;

  // fields
  std::list<std::shared_ptr<SearchNode>> fq;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BFS_DFS_BASE_HPP

