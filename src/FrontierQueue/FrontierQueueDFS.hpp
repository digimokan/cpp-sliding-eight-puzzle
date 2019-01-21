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

#include "FrontierQueueBfsDfsBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueDFS : public FrontierQueueBfsDfsBase {

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

private:

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_DFS_HPP

