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

#include "FrontierQueueIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueBase : public FrontierQueueIface {

public:

  // destructor
  ~FrontierQueueBase () override = default;

  // operators
  FrontierQueueBase (const FrontierQueueBase& in) = default;
  FrontierQueueBase& operator= (const FrontierQueueBase& rh) = default;
  FrontierQueueBase (FrontierQueueBase&& in) = default;
  FrontierQueueBase& operator= (FrontierQueueBase&& rh) = default;

  // base / derived methods
  size_t get_largest_queue_size () const final;
  size_t get_num_nodes_popped () const final;
  void push (std::shared_ptr<SearchNode> node) final;
  std::shared_ptr<SearchNode> pop () final;
  bool not_empty () const final;
  bool is_empty () const override = 0;
  size_t get_current_queue_size () const override = 0;

protected:

  // constructors
  FrontierQueueBase ();

  // base / derived methods
  virtual void push_logic (std::shared_ptr<SearchNode>) = 0;
  virtual std::shared_ptr<SearchNode> pop_logic () = 0;

private:

  // fields
  size_t largest_queue_size;
  size_t num_nodes_popped;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_BASE_HPP

