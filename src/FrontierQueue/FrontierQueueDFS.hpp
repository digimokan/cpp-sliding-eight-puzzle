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

#include <memory>
#include <stack>

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
  FrontierQueueDFS (const FrontierQueueDFS& in) = delete;
  FrontierQueueDFS& operator= (const FrontierQueueDFS& rh) = delete;
  FrontierQueueDFS (FrontierQueueDFS&& in) = delete;
  FrontierQueueDFS& operator= (FrontierQueueDFS&& rh) = delete;

private:

  // fields
  std::stack<std::shared_ptr<SearchNode>> fq;

  // template methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;
  std::shared_ptr<SearchNode> peek_next_logic () const override;
  size_t get_size_logic () const override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_DFS_HPP

