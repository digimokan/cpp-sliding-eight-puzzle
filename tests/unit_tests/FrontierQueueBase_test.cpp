/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "CompilerUtils.hpp"
#include "FrontierQueueBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* MOCKS
*******************************************************************************/

class TestQueue: public FrontierQueueBase {
public:
  TestQueue () : queue_size{0} { }
  bool is_empty () const override { return true; }
  size_t get_current_queue_size () const override { return queue_size; }
private:
  void push_logic (std::shared_ptr<SearchNode> node) override { MARK_AS_USED(node); this->queue_size++; }
  std::shared_ptr<SearchNode> pop_logic () override { this->queue_size--; return std::make_shared<SearchNode>(Board{ "123405678" }); }
  size_t queue_size;
};

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("is_empty and not_empty") {

  TestQueue tq{};

  SUBCASE("is_empty()") {
    CHECK_UNARY(tq.is_empty());
  }

  SUBCASE("not_empty()") {
    CHECK_FALSE(tq.not_empty());
  }

}

TEST_CASE("push and pop") {

  TestQueue tq{};

  SUBCASE("push()") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
  }

  SUBCASE("pop()") {
    auto sn{ tq.pop() };
    CHECK_UNARY(sn->get_board() == Board{ "123405678" });
  }

}

TEST_CASE("get_current_queue_size()") {

  TestQueue tq{};

  SUBCASE("empty queue") {
    CHECK_EQ(tq.get_current_queue_size(), 0);
  }

  SUBCASE("after pushing 4") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    CHECK_EQ(tq.get_current_queue_size(), 4);
  }

  SUBCASE("after pushing 4, removing 3") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.pop();
    tq.pop();
    tq.pop();
    CHECK_EQ(tq.get_current_queue_size(), 1);
  }

  SUBCASE("after pushing 4, removing 3, adding 1") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.pop();
    tq.pop();
    tq.pop();
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    CHECK_EQ(tq.get_current_queue_size(), 2);
  }

}

TEST_CASE("get_largest_queue_size()") {

  TestQueue tq{};

  SUBCASE("after pushing 4, removing 3, adding 1") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.pop();
    tq.pop();
    tq.pop();
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    CHECK_EQ(tq.get_largest_queue_size(), 4);
  }

}

TEST_CASE("get_num_nodes_popped()") {

  TestQueue tq{};

  SUBCASE("after pushing 4, removing 2, adding 1, removing 1") {
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.pop();
    tq.pop();
    tq.push(std::make_shared<SearchNode>(Board{ "123405678" }));
    tq.pop();
    CHECK_EQ(tq.get_num_nodes_popped(), 3);
  }

}
