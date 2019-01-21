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

class FQBaseMock: public FrontierQueueBase {
public:
  FQBaseMock () : queue_size{0} { }
  bool is_empty () const override { return true; }
  bool contains (const Board& board) const override { MARK_AS_USED(board); return true; }
  std::optional<std::shared_ptr<SearchNode>> get_node (const Board& board) const override { MARK_AS_USED(board); return std::nullopt; }
  size_t get_current_queue_size () const override { return queue_size; }
private:
  void push_logic (std::shared_ptr<SearchNode> node) override { MARK_AS_USED(node); this->queue_size++; }
  std::shared_ptr<SearchNode> pop_logic () override { this->queue_size--; return std::make_shared<SearchNode>(Board{ "123405678" }); }
  size_t queue_size;
};

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("not_empty()") {

  FQBaseMock tq{};

  SUBCASE("not_empty() returns opposite of is_empty()") {
    CHECK_NE(tq.is_empty(), tq.not_empty());
  }

}

TEST_CASE("not_contains()") {

  FQBaseMock tq{};

  SUBCASE("not_contains() returns opposite of contains()") {
    CHECK_NE(tq.contains(Board{"01234567"}), tq.not_contains(Board{"01234567"}));
  }

}

TEST_CASE("get_largest_queue_size()") {

  FQBaseMock tq{};

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

  FQBaseMock tq{};

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

