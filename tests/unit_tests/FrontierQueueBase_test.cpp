/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <queue>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBase.hpp"

/*******************************************************************************
* MOCKS
*******************************************************************************/

class FQBMock: public FrontierQueueBase {
private:
  void push_logic (std::shared_ptr<SearchNode> node) override { this->nqueue.push(node); }
  std::shared_ptr<SearchNode> pop_logic () override { auto node{ this->nqueue.front() }; this->nqueue.pop(); return node; }
  std::shared_ptr<SearchNode> peek_next_logic () const override { return this->nqueue.front(); }
  size_t get_size_logic () const override { return this->nqueue.size(); }
  std::queue<std::shared_ptr<SearchNode>> nqueue;
};

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("empty queue") {

  FQBMock fqbmock{};

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("not_empty()") {
    CHECK_FALSE(fqbmock.not_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 0);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 0);
  }

}

TEST_CASE("push single node") {

  Board BA{ Board{"134862705"} };
  /* Board BB{ Board{"134802765"} }; */
  /* Board BC{ Board{"134862075"} }; */
  /* Board BD{ Board{"134862750"} }; */
  /* Board BE{ Board{"104832765"} }; */
  /* Board BF{ Board{"134082765"} }; */
  auto SNA{ std::make_shared<SearchNode>(BA) };
  /* auto SNB{ std::make_shared<SearchNode>(BB) }; */
  /* auto SNC{ std::make_shared<SearchNode>(BC) }; */
  /* auto SND{ std::make_shared<SearchNode>(BD) }; */
  /* auto SNE{ std::make_shared<SearchNode>(BE) }; */
  /* auto SNF{ std::make_shared<SearchNode>(BF) }; */
  FQBMock fqbmock{};
  fqbmock.push(SNA);

  SUBCASE("contains()") {
    CHECK_UNARY(fqbmock.contains(SNA->get_board()));
  }

  SUBCASE("not_contains()") {
    CHECK_FALSE(fqbmock.not_contains(SNA->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), SNA);
  }

  SUBCASE("empty()") {
    CHECK_FALSE(fqbmock.is_empty());
  }

  SUBCASE("not_empty()") {
    CHECK_UNARY(fqbmock.not_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 1);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 1);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 0);
  }

}

TEST_CASE("push/pop single node") {

  Board BA{ Board{"134862705"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  auto popped{ fqbmock.pop() };

  SUBCASE("pop()") {
    CHECK_EQ(popped, SNA);
  }

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 1);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 1);
  }

}

TEST_CASE("push three nodes, pop three nodes") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.push(SNB);
  fqbmock.push(SNC);
  auto Apop{ fqbmock.pop() };
  auto Bpop{ fqbmock.pop() };
  auto Cpop{ fqbmock.pop() };

  SUBCASE("pop()") {
    CHECK_EQ(Apop, SNA);
    CHECK_EQ(Bpop, SNB);
    CHECK_EQ(Cpop, SNC);
  }

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 3);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 3);
  }

}

TEST_CASE("push/pop A, push/pop B, push/pop C") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  auto Apop{ fqbmock.pop() };
  fqbmock.push(SNB);
  auto Bpop{ fqbmock.pop() };
  fqbmock.push(SNC);
  auto Cpop{ fqbmock.pop() };

  SUBCASE("pop()") {
    CHECK_EQ(Apop, SNA);
    CHECK_EQ(Bpop, SNB);
    CHECK_EQ(Cpop, SNC);
  }

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 1);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 3);
  }

}

TEST_CASE("push ABCD, pop ABC, push EF, pop D") {
/*******************************************************************************
* FINAL QUEUE STATE: FE
*******************************************************************************/

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  Board BD{ Board{"134862750"} };
  Board BE{ Board{"104832765"} };
  Board BF{ Board{"134082765"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  auto SND{ std::make_shared<SearchNode>(BD) };
  auto SNE{ std::make_shared<SearchNode>(BE) };
  auto SNF{ std::make_shared<SearchNode>(BF) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.push(SNB);
  fqbmock.push(SNC);
  fqbmock.push(SND);
  auto Apop{ fqbmock.pop() };
  auto Bpop{ fqbmock.pop() };
  auto Cpop{ fqbmock.pop() };
  fqbmock.push(SNE);
  fqbmock.push(SNF);
  auto Dpop{ fqbmock.pop() };

  SUBCASE("pop()") {
    CHECK_EQ(Apop, SNA);
    CHECK_EQ(Bpop, SNB);
    CHECK_EQ(Cpop, SNC);
    CHECK_EQ(Dpop, SND);
  }

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
    CHECK_FALSE(fqbmock.contains(SND->get_board()));
    CHECK_UNARY(fqbmock.contains(SNE->get_board()));
    CHECK_UNARY(fqbmock.contains(SNF->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SND->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNE->get_board()), SNE);
    CHECK_EQ(fqbmock.get_node(SNF->get_board()), SNF);
  }

  SUBCASE("empty()") {
    CHECK_FALSE(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 2);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 4);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 4);
  }

}

TEST_CASE("push/remove single node") {

  Board BA{ Board{"134862705"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.remove_node(SNA);

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 1);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 0);
  }

}

TEST_CASE("push three nodes, remove three nodes") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.push(SNB);
  fqbmock.push(SNC);
  fqbmock.remove_node(SNA);
  fqbmock.remove_node(SNB);
  fqbmock.remove_node(SNC);

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 3);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 0);
  }

}

TEST_CASE("push/remove A, push/remove B, push/remove C") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.remove_node(SNA);
  fqbmock.push(SNB);
  fqbmock.remove_node(SNB);
  fqbmock.push(SNC);
  fqbmock.remove_node(SNC);

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 1);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 0);
  }

}

TEST_CASE("push ABCDEFGHIJKL, pop A, rem B, rem C, pop D, rem EF, pop G, rem JK, pop H, pop I, pop L") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  Board BD{ Board{"134862750"} };
  Board BE{ Board{"104832765"} };
  Board BF{ Board{"134082765"} };
  Board BG{ Board{"314082765"} };
  Board BH{ Board{"413082765"} };
  Board BI{ Board{"813402765"} };
  Board BJ{ Board{"713408265"} };
  Board BK{ Board{"613408275"} };
  Board BL{ Board{"513408276"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  auto SND{ std::make_shared<SearchNode>(BD) };
  auto SNE{ std::make_shared<SearchNode>(BE) };
  auto SNF{ std::make_shared<SearchNode>(BF) };
  auto SNG{ std::make_shared<SearchNode>(BG) };
  auto SNH{ std::make_shared<SearchNode>(BH) };
  auto SNI{ std::make_shared<SearchNode>(BI) };
  auto SNJ{ std::make_shared<SearchNode>(BJ) };
  auto SNK{ std::make_shared<SearchNode>(BK) };
  auto SNL{ std::make_shared<SearchNode>(BL) };
  FQBMock fqbmock{};
  fqbmock.push(SNA);
  fqbmock.push(SNB);
  fqbmock.push(SNC);
  fqbmock.push(SND);
  fqbmock.push(SNE);
  fqbmock.push(SNF);
  fqbmock.push(SNG);
  fqbmock.push(SNH);
  fqbmock.push(SNI);
  fqbmock.push(SNJ);
  fqbmock.push(SNK);
  fqbmock.push(SNL);
  auto Apop{ fqbmock.pop() };
  fqbmock.remove_node(SNB);
  fqbmock.remove_node(SNC);
  auto Dpop{ fqbmock.pop() };
  fqbmock.remove_node(SNF);
  fqbmock.remove_node(SNE);
  auto Gpop{ fqbmock.pop() };
  fqbmock.remove_node(SNJ);
  fqbmock.remove_node(SNK);
  auto Hpop{ fqbmock.pop() };
  auto Ipop{ fqbmock.pop() };
  auto Lpop{ fqbmock.pop() };

  SUBCASE("pop()") {
    CHECK_EQ(Apop, SNA);
    CHECK_EQ(Dpop, SND);
    CHECK_EQ(Gpop, SNG);
    CHECK_EQ(Hpop, SNH);
    CHECK_EQ(Ipop, SNI);
    CHECK_EQ(Lpop, SNL);
  }

  SUBCASE("contains()") {
    CHECK_FALSE(fqbmock.contains(SNA->get_board()));
    CHECK_FALSE(fqbmock.contains(SNB->get_board()));
    CHECK_FALSE(fqbmock.contains(SNC->get_board()));
    CHECK_FALSE(fqbmock.contains(SND->get_board()));
    CHECK_FALSE(fqbmock.contains(SNE->get_board()));
    CHECK_FALSE(fqbmock.contains(SNF->get_board()));
    CHECK_FALSE(fqbmock.contains(SNG->get_board()));
    CHECK_FALSE(fqbmock.contains(SNH->get_board()));
    CHECK_FALSE(fqbmock.contains(SNI->get_board()));
    CHECK_FALSE(fqbmock.contains(SNJ->get_board()));
    CHECK_FALSE(fqbmock.contains(SNK->get_board()));
    CHECK_FALSE(fqbmock.contains(SNL->get_board()));
  }

  SUBCASE("get_node()") {
    CHECK_EQ(fqbmock.get_node(SNA->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNB->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNC->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SND->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNE->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNF->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNG->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNH->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNI->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNJ->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNK->get_board()), std::nullopt);
    CHECK_EQ(fqbmock.get_node(SNL->get_board()), std::nullopt);
  }

  SUBCASE("empty()") {
    CHECK_UNARY(fqbmock.is_empty());
  }

  SUBCASE("get_current_queue_size()") {
    CHECK_EQ(fqbmock.get_current_queue_size(), 0);
  }

  SUBCASE("get_largest_queue_size()") {
    CHECK_EQ(fqbmock.get_largest_queue_size(), 12);
  }

  SUBCASE("get_num_nodes_popped()") {
    CHECK_EQ(fqbmock.get_num_nodes_popped(), 6);
  }

}

