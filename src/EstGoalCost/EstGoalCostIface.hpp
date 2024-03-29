/*******************************************************************************
module:   EstGoalCostIface
author:   digimokan
date:     17 JAN 2019
purpose:  given a SearchNode (and possibly, goal board), return est cost of goal
      --> uninformed strategy: returns g(n) (uniform) or const (simple queue)
      --> informed strategy: returns f(n) (which = h(n), maybe including g(n))
*******************************************************************************/

#ifndef EST_GOAL_COST_IFACE_HPP
#define EST_GOAL_COST_IFACE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostIface {

public:

  // destructor
  virtual ~EstGoalCostIface () = default;

  // operators
  EstGoalCostIface (const EstGoalCostIface& in) = default;
  EstGoalCostIface& operator= (const EstGoalCostIface& rh) = delete;
  EstGoalCostIface (EstGoalCostIface&& in) = default;
  EstGoalCostIface& operator= (EstGoalCostIface&& rh) = delete;

  // base / derived methods
  virtual bool operator() (const std::shared_ptr<SearchNode>& lh, const std::shared_ptr<SearchNode>& rh) = 0;
  virtual unsigned int get_est_goal_cost (std::shared_ptr<SearchNode>) const = 0;

protected:

  // constructors
  EstGoalCostIface () = default;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_IFACE_HPP

