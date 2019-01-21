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

#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBfsDfsBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueBFS : public FrontierQueueBfsDfsBase {

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

private:

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BFS_HPP

