/*******************************************************************************
module:   FrontierQueueEstCost
author:   digimokan
date:     22 JAN 2019
purpose:  priority queues based on est cost to goal (uniform, f(n), g(n), etc.)
template param:
          a type that implements EstGoalCostIface
*******************************************************************************/

#ifndef FRONTIER_QUEUE_EST_COST_HPP
#define FRONTIER_QUEUE_EST_COST_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>
#include <queue>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

template <typename T>
class FrontierQueueEstCost : public FrontierQueueBase {

public:

  // constructors
  FrontierQueueEstCost () = default;

  // destructor
  ~FrontierQueueEstCost () override = default;

  // operators
  FrontierQueueEstCost (const FrontierQueueEstCost& in) = delete;
  FrontierQueueEstCost& operator= (const FrontierQueueEstCost& rh) = delete;
  FrontierQueueEstCost (FrontierQueueEstCost&& in) = delete;
  FrontierQueueEstCost& operator= (FrontierQueueEstCost&& rh) = delete;

private:

  // fields
  std::priority_queue<std::shared_ptr<SearchNode>, std::vector<std::shared_ptr<SearchNode>>, T> fq;

  // base / derived methods
  void push_logic (std::shared_ptr<SearchNode> node) override;
  std::shared_ptr<SearchNode> pop_logic () override;
  std::shared_ptr<SearchNode> peek_next_logic () const override;
  size_t get_size_logic () const override;

};

/*******************************************************************************
* IMPLEMENTATION
*******************************************************************************/

#include "FrontierQueueEstCost.hxx"

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_EST_COST_HPP

