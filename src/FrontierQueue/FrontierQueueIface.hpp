/*******************************************************************************
module:   FrontierQueueIface
author:   digimokan
date:     17 JAN 2019
purpose:  interface for a "frontier queue" of a search graph
          --> this queue orders the "nodes to be explored" in the search graph
*******************************************************************************/

#ifndef FRONTIER_QUEUE_IFACE_HPP
#define FRONTIER_QUEUE_IFACE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class FrontierQueueIface {

public:

  // destructor
  virtual ~FrontierQueueIface () = default;

  // operators
  FrontierQueueIface (const FrontierQueueIface& in) = default;
  FrontierQueueIface& operator= (const FrontierQueueIface& rh) = default;
  FrontierQueueIface (FrontierQueueIface&& in) = default;
  FrontierQueueIface& operator= (FrontierQueueIface&& rh) = default;

  // base / derived methods
  virtual void push (std::shared_ptr<SearchNode>) = 0;
  virtual std::shared_ptr<SearchNode> pop () = 0;
  virtual bool is_empty () const = 0;
  virtual bool not_empty () const = 0;
  virtual size_t get_current_queue_size () const = 0;
  virtual size_t get_largest_queue_size () const = 0;
  virtual size_t get_num_nodes_popped () const = 0;

protected:

  // constructors
  FrontierQueueIface () = default;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_IFACE_HPP

