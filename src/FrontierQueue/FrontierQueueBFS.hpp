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
  FrontierQueueBFS (const FrontierQueueBFS& in) = delete;
  FrontierQueueBFS& operator= (const FrontierQueueBFS& rh) = delete;
  FrontierQueueBFS (FrontierQueueBFS&& in) = delete;
  FrontierQueueBFS& operator= (FrontierQueueBFS&& rh) = delete;

private:

  // fields
  std::queue<std::shared_ptr<SearchNode>> fq;

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;
  std::shared_ptr<SearchNode> peek_next_logic () const override;
  size_t get_size_logic () const override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BFS_HPP

