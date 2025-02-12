# 📌 Greedy Algorithm

## 🔹 Overview
A **Greedy Algorithm** is a problem-solving technique where the best choice is made at each step, with the hope of finding the global optimum. It selects the locally optimal solution at each stage with the intention of finding the global optimum, but does not always guarantee the best overall solution.

---

## 🔹 Core Principle of Greedy Algorithms
Greedy algorithms follow a few basic steps:  
1. **Greedy Choice**: At each step, choose the "best" or "optimal" option without considering the choices made before.
2. **Restore or Update State**: Update the problem after each step to reflect the decision made.
3. **Termination Check**: Check whether the algorithm has arrived at a solution (i.e., the optimal or final result).

---

## 🔹 Characteristics of Greedy Algorithms
- **Natural**: Greedy algorithms are often naturally suited for problems with specific structures (like optimization or selection problems).
- **Not globally optimal in all cases**: Greedy algorithms do not always guarantee the globally optimal solution, but in some problems, they provide an optimal or good solution quickly.
- **Easy to implement**: The greedy approach is simple as it involves making decisions step by step based on the current state.

---

## 🔹 Pros and Cons
### ✔ Pros:
- **High efficiency**: Greedy algorithms usually have a low time complexity because they only consider each step individually.
- **Simple and easy to implement**: The greedy approach is straightforward and does not require complex data storage.
- **Effective for certain problems**: For problems like scheduling, resource allocation, or sorting, greedy algorithms can yield optimal results.

### ✖ Cons:
- **Does not guarantee global optimal solution**: In some problems, greedy algorithms may not provide the best overall solution.
- **Limited to specific problems**: Greedy algorithms only work for problems that satisfy certain conditions (such as the greedy-choice property and optimal substructure).

---

## 🔹 Problems Solved Using Greedy Algorithms
Some common problems that can be solved using greedy algorithms include:
1. **Knapsack Problem**: In cases where the items' values and weights are proportional.
2. **Coin Change Problem**: Finding the minimum number of coins to make a specific amount of change.
3. **Shortest Path Problem**: Some shortest path algorithms (like Dijkstra’s algorithm) are greedy in nature.

---

## 🔹 Conditions for Applying Greedy Algorithms
Greedy algorithms can only be applied when the problem satisfies **two key conditions**:
1. **Greedy Choice Property**: The problem must allow making an optimal choice at each step without considering future steps.
2. **Optimal Substructure**: The global optimal solution can be constructed from local optimal solutions.

---
