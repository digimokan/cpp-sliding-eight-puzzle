# cpp-sliding-eight-puzzle

Linux/UNIX command-line Sliding Eight-Puzzle solver with selectable strategies,
written in C++.

[![Release](https://img.shields.io/github/release/digimokan/cpp-sliding-eight-puzzle.svg?label=release)](https://github.com/digimokan/cpp-sliding-eight-puzzle/releases/latest "Latest Release Notes")
[![License](https://img.shields.io/badge/license-MIT-blue.svg?label=license)](LICENSE.txt "Project License")
[![Build Status](https://img.shields.io/travis/com/digimokan/cpp-sliding-eight-puzzle/master.svg?label=linux+build)](https://travis-ci.com/digimokan/cpp-sliding-eight-puzzle "Build And Test Results From Master Branch")

## Table Of Contents

* [Motivation](#motivation)
* [Features](#features)
* [Design](#design)
* [Requirements](#requirements)
* [Quick Start](#quick-start)
* [Sample Project Layout](#source-code-layout)
* [Full Usage / Options](#full-usage--options)
* [Examples](#examples)
* [Contributing](#contributing)

## Motivation

Make an efficient, easy-to-use command-line program to solve an
[Eight-Puzzle](https://en.wikipedia.org/wiki/15_puzzle). Implement selectable
solving strategies to allow comparison of time complexity, space complexity,
and optimality.

## Features

* Use different strategies as simple options.
* Switch between different move costs with an option.
* Perform low-level, common operations in constant time to maximize the solving
  speed of any strategy.

## Design

A paragraph or two about architecture.

<img src="readme_assets/design_diagram.svg" width="100%" height="400" alt="Design Diagram">

## Requirements

* A Linux/UNIX system
* C++17 (gcc 7, clang 4)
* CMake

## Quick Start

1. Clone the project into a local project directory:

   ```shell
   $ git clone git@github.com:digimokan/cpp-sliding-eight-puzzle.git
   ```

2. Change to the local project directory:

   ```shell
   $ cd cpp-sliding-eight-puzzle
   ```

3. Compile the program.

   ```shell
   $ ./third_party/smart-build/src/smart-build.sh -r
   ```

3. Solve a puzzle.

   ```shell
   $ ./eight-puzzle --depth-first "567408321" "123804765"
   ```

## Source Code Layout

```
├─┬ cpp-sliding-eight-puzzle/
│ │
│ ├─┬ src/
│ │ ├── Board/            # a puzzle board, containing squares with values
│ │ ├── EstGoalCost/      # estimated cost to goal board (g(n), h(n), f(n), etc)
│ │ ├── FrontierQueue/    # search nodes for evaluation, ordered in some way
│ │ ├── Inputs/           # process program user input
│ │ ├── Move/             # a board move, or possible legal board moves
│ │ ├── MoveCost/         # cost of a board move (traditionally, 1 unit)
│ │ ├── Search/           # the search graph and its nodes
│ │ ├── Solver/           # produces solution steps using various strategies
│ │ ├── Utils/            # utility functions
│ │ └── main.cpp          # main program entry point
│ │
│ ├─┬ tests/
│ │ ├── unit_tests/             # unit test for each class and its methods
│ │ ├── doctest_testharness.cpp # configures the unit tester (doctest)
│ │ └── test_driver.sh          # one-line driver to smart-build the program
│ │
│ ├─┬ third_party/
│ │ ├── doctest/                # the unit-tester
│ │ └── smart-build             # the building/testing utility
│ │
│ ├── .project_config           # smart-build compilation/build config
│ └── CMakeLists.txt            # CMake build config
```

## Full Usage / Options

USAGE

`eight-puzzle -h`

`eight-puzzle [-v|-c] [-b|-d|-i|-u|-s|-1|-2|-3] <start_board> <goal_board>`  

ARGUMENTS

`<start_board>`  
&nbsp; &nbsp; &nbsp; &nbsp; starting board: a 3x3 with 0-8 (0 is empty), e.g. "134862705"

`<goal_board>`  
&nbsp; &nbsp; &nbsp; &nbsp; winning/goal board: a 3x3 with 0-8 (0 is empty), e.g. "123804765"

OPTIONS

`-h, --help`  
&nbsp; &nbsp; &nbsp; &nbsp; print this help message

`-v, --move-cost-sq-val`  
&nbsp; &nbsp; &nbsp; &nbsp; set move costs to the value of the square moved (default)

`-c, --move-cost-const`  
&nbsp; &nbsp; &nbsp; &nbsp; set move costs to 1 (the traditional cost)

`-b, --breadth-first`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using breadth-first search (default)

`-d, --depth-first`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using depth-first search

`-i, --iterative-deepening`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using depth-first search with iterative deepening

`-u, --uniform-cost`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using g(n) uniform-cost search

`-s, --best-first`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using h(n) num misplaced tiles

`-1, --a-star-1`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using A*1 search (g(n) + h(n) num misplaced tiles)

`-2, --a-star-2`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using A*2 search (g(n) + h(n) sum manhattan dists)

`-3, --a-star-3`  
&nbsp; &nbsp; &nbsp; &nbsp; find solution using A*3 search (g(n) + h(n) custom heuristic)

## Examples

* Solve an easy puzzle, using the traditional move cost of 1:

   ```shell
   $ ./eight-puzzle -cb "134862705" "123804765"
   ```

* Solve a hard puzzle (requiring many steps) using a fast, but non-optimal solver:

   ```shell
   $ ./eight-puzzle --best-first "567408321" "123804765"
   ```

* Solve a hard puzzle (requiring many steps) using a balanced, optimal solver:

   ```shell
   $ ./eight-puzzle --a-star-3 "567408321" "123804765"
   ```

## Contributing

* Feel free to report a bug or propose a feature by opening a new
  [Issue](https://github.com/digimokan/cpp-sliding-eight-puzzle/issues).
* Follow the project's [Contributing](CONTRIBUTING.md) guidelines.
* Respect the project's [Code Of Conduct](CODE_OF_CONDUCT.md).

