/*******************************************************************************
module:   FrontierQueueDFS
author:   digimokan
date:     21 JAN 2019
purpose:  simple DFS LIFO queue with no est-goal-cost strategy
*******************************************************************************/

#ifndef FRONTIER_QUEUE_DFS_HPP
#define FRONTIER_QUEUE_DFS_HPP 1

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

class FrontierQueueDFS : public FrontierQueueBase {

public:

  // constructors
  FrontierQueueDFS () = default;

  // destructor
  ~FrontierQueueDFS () override = default;

  // operators
  FrontierQueueDFS (const FrontierQueueDFS& in) = default;
  FrontierQueueDFS& operator= (const FrontierQueueDFS& rh) = default;
  FrontierQueueDFS (FrontierQueueDFS&& in) = default;
  FrontierQueueDFS& operator= (FrontierQueueDFS&& rh) = default;

  // base / derived methods
  bool is_empty () const override;
  bool contains (const Board& board) const override;
  size_t get_current_queue_size () const override;

private:

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;

  // fields
  std::list<std::shared_ptr<SearchNode>> fq;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_DFS_HPP

