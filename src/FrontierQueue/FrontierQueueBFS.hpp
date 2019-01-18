/*******************************************************************************
module:   FrontierQueueBFS
author:   digimokan
date:     17 JAN 2019
purpose:  simple BFS FIFO queue with no est-goal-cost strategy
*******************************************************************************/

#ifndef FRONTIER_QUEUE_BFS_HPP
#define FRONTIER_QUEUE_BFS_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>
#include <queue>

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

class FrontierQueueBFS : public FrontierQueueBase {

public:

  // constructors
  FrontierQueueBFS () = default;

  // destructor
  ~FrontierQueueBFS () override = default;

  // operators
  FrontierQueueBFS (const FrontierQueueBFS& in) = default;
  FrontierQueueBFS& operator= (const FrontierQueueBFS& rh) = default;
  FrontierQueueBFS (FrontierQueueBFS&& in) = default;
  FrontierQueueBFS& operator= (FrontierQueueBFS&& rh) = default;

  // base / derived methods
  bool is_empty () const override;
  size_t get_current_queue_size () const override;

private:

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;

  // fields
  std::queue<std::shared_ptr<SearchNode>> fq;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BFS_HPP

