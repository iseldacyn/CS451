=== Free Cell Problem ===
State: A specific configuration of piles of cards from 1 to n, with each card appearing once in a certain order.
	The value n serves as the current counter for the problem (i.e. the highest card number currently in the piles). The starting value of the counter may be called nMax.

Initial State: The starting configuration of the piles, with each card from 1 to n being present (and n = nMax).

Goal Test: The counter, n, reaches 0 (i.e. no more cards in any of the piles).

Successor Function: Look at the top card in each pile. If it is equal to the counter, create a successor where that card is discarded.
	If not, check if there is an empty pile, and create a successor where it is moved to said pile.
	If there is no empty pile, compare it to the top of the other piles. If the value at the top of the new pile is smaller than the value at the top of the current pile, create a successor where it is moved onto the new pile. Repeat for all such piles where this occurs.

Heuristic One: Return the counter value
Heuristic Two: Return the counter value + the amount of cards in front of each piles highest value card.

Program Output:

---Test Case 1---
[Heuristic 1]
Initial state:
10  [] [] [4,5,1,2,6,7,10,9,3,8]  Perform action [Move 8 from pile 2 to empty pile 0] to get state below with path cost 1 and heuristic 10
10  [8] [] [4,5,1,2,6,7,10,9,3]  Perform action [Move 3 from pile 2 to empty pile 1] to get state below with path cost 2 and heuristic 10
10  [8] [3] [4,5,1,2,6,7,10,9]  Perform action [Move 9 from pile 2 to pile 1] to get state below with path cost 3 and heuristic 10
10  [8] [3,9] [4,5,1,2,6,7,10]  Perform action [Discard 10 from pile 2] to get state below with path cost 4 and heuristic 9
9  [8] [3,9] [4,5,1,2,6,7]  Perform action [Discard 9 from pile 1] to get state below with path cost 5 and heuristic 8
8  [8] [3] [4,5,1,2,6,7]  Perform action [Discard 8 from pile 0] to get state below with path cost 6 and heuristic 7
7  [] [3] [4,5,1,2,6,7]  Perform action [Discard 7 from pile 2] to get state below with path cost 7 and heuristic 6
6  [] [3] [4,5,1,2,6]  Perform action [Discard 6 from pile 2] to get state below with path cost 8 and heuristic 5
5  [] [3] [4,5,1,2]  Perform action [Move 2 from pile 2 to empty pile 0] to get state below with path cost 9 and heuristic 5
5  [2] [3] [4,5,1]  Perform action [Move 3 from pile 1 to pile 0] to get state below with path cost 10 and heuristic 5
5  [2,3] [] [4,5,1]  Perform action [Move 1 from pile 2 to empty pile 1] to get state below with path cost 11 and heuristic 5
5  [2,3] [1] [4,5]  Perform action [Discard 5 from pile 2] to get state below with path cost 12 and heuristic 4
4  [2,3] [1] [4]  Perform action [Discard 4 from pile 2] to get state below with path cost 13 and heuristic 3
3  [2,3] [1] []  Perform action [Discard 3 from pile 0] to get state below with path cost 14 and heuristic 2
2  [2] [1] []  Perform action [Discard 2 from pile 0] to get state below with path cost 15 and heuristic 1
1  [] [1] []  Perform action [Discard 1 from pile 1] to get state below with path cost 16 and heuristic 0
0  [] [] []Expanded 6248 states

[Heuristic 2]
10  [] [] [4,5,1,2,6,7,10,9,3,8]  Perform action [Move 8 from pile 2 to empty pile 1] to get state below with path cost 1 and heuristic 12
10  [] [8] [4,5,1,2,6,7,10,9,3]  Perform action [Move 3 from pile 2 to empty pile 0] to get state below with path cost 2 and heuristic 11
10  [3] [8] [4,5,1,2,6,7,10,9]  Perform action [Move 9 from pile 2 to pile 0] to get state below with path cost 3 and heuristic 10
10  [3,9] [8] [4,5,1,2,6,7,10]  Perform action [Discard 10 from pile 2] to get state below with path cost 4 and heuristic 9
9  [3,9] [8] [4,5,1,2,6,7]  Perform action [Discard 9 from pile 0] to get state below with path cost 5 and heuristic 8
8  [3] [8] [4,5,1,2,6,7]  Perform action [Discard 8 from pile 1] to get state below with path cost 6 and heuristic 7
7  [3] [] [4,5,1,2,6,7]  Perform action [Discard 7 from pile 2] to get state below with path cost 7 and heuristic 6
6  [3] [] [4,5,1,2,6]  Perform action [Discard 6 from pile 2] to get state below with path cost 8 and heuristic 7
5  [3] [] [4,5,1,2]  Perform action [Move 2 from pile 2 to empty pile 1] to get state below with path cost 9 and heuristic 6
5  [3] [2] [4,5,1]  Perform action [Move 3 from pile 0 to pile 1] to get state below with path cost 10 and heuristic 6
5  [] [2,3] [4,5,1]  Perform action [Move 1 from pile 2 to empty pile 0] to get state below with path cost 11 and heuristic 5
5  [1] [2,3] [4,5]  Perform action [Discard 5 from pile 2] to get state below with path cost 12 and heuristic 4
4  [1] [2,3] [4]  Perform action [Discard 4 from pile 2] to get state below with path cost 13 and heuristic 3
3  [1] [2,3] []  Perform action [Discard 3 from pile 1] to get state below with path cost 14 and heuristic 2
2  [1] [2] []  Perform action [Discard 2 from pile 1] to get state below with path cost 15 and heuristic 1
1  [1] [] []  Perform action [Discard 1 from pile 0] to get state below with path cost 16 and heuristic 0
0  [] [] []Expanded 3035 states

---Test Case 2---
[Heuristic 1]
12  [2,11,4] [3,12,6,1] [7,8,9] [10,5]  Perform action [Move 5 from pile 3 to pile 0] to get state below with path cost 1 and heuristic 12
12  [2,11,4,5] [3,12,6,1] [7,8,9] [10]  Perform action [Move 10 from pile 3 to pile 2] to get state below with path cost 2 and heuristic 12
12  [2,11,4,5] [3,12,6,1] [7,8,9,10] []  Perform action [Move 1 from pile 1 to empty pile 3] to get state below with path cost 3 and heuristic 12
12  [2,11,4,5] [3,12,6] [7,8,9,10] [1]  Perform action [Move 5 from pile 0 to pile 3] to get state below with path cost 4 and heuristic 12
12  [2,11,4] [3,12,6] [7,8,9,10] [1,5]  Perform action [Move 6 from pile 1 to pile 3] to get state below with path cost 5 and heuristic 12
12  [2,11,4] [3,12] [7,8,9,10] [1,5,6]  Perform action [Discard 12 from pile 1] to get state below with path cost 6 and heuristic 11
11  [2,11,4] [3] [7,8,9,10] [1,5,6]  Perform action [Move 4 from pile 0 to pile 1] to get state below with path cost 7 and heuristic 11
11  [2,11] [3,4] [7,8,9,10] [1,5,6]  Perform action [Discard 11 from pile 0] to get state below with path cost 8 and heuristic 10
10  [2] [3,4] [7,8,9,10] [1,5,6]  Perform action [Discard 10 from pile 2] to get state below with path cost 9 and heuristic 9
9  [2] [3,4] [7,8,9] [1,5,6]  Perform action [Discard 9 from pile 2] to get state below with path cost 10 and heuristic 8
8  [2] [3,4] [7,8] [1,5,6]  Perform action [Discard 8 from pile 2] to get state below with path cost 11 and heuristic 7
7  [2] [3,4] [7] [1,5,6]  Perform action [Discard 7 from pile 2] to get state below with path cost 12 and heuristic 6
6  [2] [3,4] [] [1,5,6]  Perform action [Discard 6 from pile 3] to get state below with path cost 13 and heuristic 5
5  [2] [3,4] [] [1,5]  Perform action [Discard 5 from pile 3] to get state below with path cost 14 and heuristic 4
4  [2] [3,4] [] [1]  Perform action [Discard 4 from pile 1] to get state below with path cost 15 and heuristic 3
3  [2] [3] [] [1]  Perform action [Discard 3 from pile 1] to get state below with path cost 16 and heuristic 2
2  [2] [] [] [1]  Perform action [Discard 2 from pile 0] to get state below with path cost 17 and heuristic 1
1  [] [] [] [1]  Perform action [Discard 1 from pile 3] to get state below with path cost 18 and heuristic 0
0  [] [] [] []Expanded 23223 states

[Heuristic 2]
12  [2,11,4] [3,12,6,1] [7,8,9] [10,5]  Perform action [Move 5 from pile 3 to pile 0] to get state below with path cost 1 and heuristic 16
12  [2,11,4,5] [3,12,6,1] [7,8,9] [10]  Perform action [Move 10 from pile 3 to pile 2] to get state below with path cost 2 and heuristic 16
12  [2,11,4,5] [3,12,6,1] [7,8,9,10] []  Perform action [Move 1 from pile 1 to empty pile 3] to get state below with path cost 3 and heuristic 15
12  [2,11,4,5] [3,12,6] [7,8,9,10] [1]  Perform action [Move 5 from pile 0 to pile 3] to get state below with path cost 4 and heuristic 14
12  [2,11,4] [3,12,6] [7,8,9,10] [1,5]  Perform action [Move 6 from pile 1 to pile 3] to get state below with path cost 5 and heuristic 13
12  [2,11,4] [3,12] [7,8,9,10] [1,5,6]  Perform action [Discard 12 from pile 1] to get state below with path cost 6 and heuristic 12
11  [2,11,4] [3] [7,8,9,10] [1,5,6]  Perform action [Move 4 from pile 0 to pile 1] to get state below with path cost 7 and heuristic 11
11  [2,11] [3,4] [7,8,9,10] [1,5,6]  Perform action [Discard 11 from pile 0] to get state below with path cost 8 and heuristic 10
10  [2] [3,4] [7,8,9,10] [1,5,6]  Perform action [Discard 10 from pile 2] to get state below with path cost 9 and heuristic 9
9  [2] [3,4] [7,8,9] [1,5,6]  Perform action [Discard 9 from pile 2] to get state below with path cost 10 and heuristic 8
8  [2] [3,4] [7,8] [1,5,6]  Perform action [Discard 8 from pile 2] to get state below with path cost 11 and heuristic 7
7  [2] [3,4] [7] [1,5,6]  Perform action [Discard 7 from pile 2] to get state below with path cost 12 and heuristic 6
6  [2] [3,4] [] [1,5,6]  Perform action [Discard 6 from pile 3] to get state below with path cost 13 and heuristic 5
5  [2] [3,4] [] [1,5]  Perform action [Discard 5 from pile 3] to get state below with path cost 14 and heuristic 4
4  [2] [3,4] [] [1]  Perform action [Discard 4 from pile 1] to get state below with path cost 15 and heuristic 3
3  [2] [3] [] [1]  Perform action [Discard 3 from pile 1] to get state below with path cost 16 and heuristic 2
2  [2] [] [] [1]  Perform action [Discard 2 from pile 0] to get state below with path cost 17 and heuristic 1
1  [] [] [] [1]  Perform action [Discard 1 from pile 3] to get state below with path cost 18 and heuristic 0
0  [] [] [] []Expanded 50 states


=== Parking Problem ===
State: A configuration of an nxn grid with cars oriented horizontally or vertically in two or more contingous positions in the grid. One car is your car, which is to be taken to a goal position.

Initial State: The starting configuration of your car, and all the others cars in the grid.

Goal Test: Check if your car is at the desired location.

Successor Function: For each car, pick one coordinate and try to move it forward/backward. If it can be moved without going off the grid or intersecting with another car, create a successor where it is moved. Repeat for the other coordinate(s) on the car.

Heuristic One: Return the distance between your car and the goal state
Heuristic Two: Return the above distance + the amount of cars in between your car and the goal state/number of cars intersecting the goal state

Program Output:

---Test Case 1---
[Heuristic 1]
[(1,2) (2,2)]* [(4,5) (5,5)] [(4,1) (4,2) (4,3)] [(2,4) (2,5)]  Perform action [Move car 1 backward ] to get state below with path cost 1 and heuristic 3
[(1,2) (2,2)]* [(3,5) (4,5)] [(4,1) (4,2) (4,3)] [(2,4) (2,5)]  Perform action [Move car 3 backward ] to get state below with path cost 2 and heuristic 3
[(1,2) (2,2)]* [(3,5) (4,5)] [(4,1) (4,2) (4,3)] [(2,3) (2,4)]  Perform action [Move car 0 forward ] to get state below with path cost 3 and heuristic 2
[(2,2) (3,2)]* [(3,5) (4,5)] [(4,1) (4,2) (4,3)] [(2,3) (2,4)]  Perform action [Move car 1 backward ] to get state below with path cost 4 and heuristic 2
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,1) (4,2) (4,3)] [(2,3) (2,4)]  Perform action [Move car 2 forward ] to get state below with path cost 5 and heuristic 2
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,2) (4,3) (4,4)] [(2,3) (2,4)]  Perform action [Move car 2 forward ] to get state below with path cost 6 and heuristic 2
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]  Perform action [Move car 0 forward ] to get state below with path cost 7 and heuristic 1
[(3,2) (4,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]  Perform action [Move car 0 forward ] to get state below with path cost 8 and heuristic 0
[(4,2) (5,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]Expanded 487 states

[Heuristic 2]
[(1,2) (2,2)]* [(4,5) (5,5)] [(4,1) (4,2) (4,3)] [(2,4) (2,5)]  Perform action [Move car 0 forward ] to get state below with path cost 1 and heuristic 3
[(2,2) (3,2)]* [(4,5) (5,5)] [(4,1) (4,2) (4,3)] [(2,4) (2,5)]  Perform action [Move car 1 backward ] to get state below with path cost 2 and heuristic 3
[(2,2) (3,2)]* [(3,5) (4,5)] [(4,1) (4,2) (4,3)] [(2,4) (2,5)]  Perform action [Move car 3 backward ] to get state below with path cost 3 and heuristic 3
[(2,2) (3,2)]* [(3,5) (4,5)] [(4,1) (4,2) (4,3)] [(2,3) (2,4)]  Perform action [Move car 1 backward ] to get state below with path cost 4 and heuristic 3
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,1) (4,2) (4,3)] [(2,3) (2,4)]  Perform action [Move car 2 forward ] to get state below with path cost 5 and heuristic 3
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,2) (4,3) (4,4)] [(2,3) (2,4)]  Perform action [Move car 2 forward ] to get state below with path cost 6 and heuristic 2
[(2,2) (3,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]  Perform action [Move car 0 forward ] to get state below with path cost 7 and heuristic 1
[(3,2) (4,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]  Perform action [Move car 0 forward ] to get state below with path cost 8 and heuristic 0
[(4,2) (5,2)]* [(2,5) (3,5)] [(4,3) (4,4) (4,5)] [(2,3) (2,4)]Expanded 216 states

---Test Case 2---
[Heuristic 1]
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(2,1) (3,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 3 forward ] to get state below with path cost 1 and heuristic 2
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(3,1) (4,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 3 forward ] to get state below with path cost 2 and heuristic 2
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 backward ] to get state below with path cost 3 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 4 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(2,3) (3,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 5 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(3,3) (4,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 6 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 2 backward ] to get state below with path cost 7 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 8 and heuristic 2
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 9 and heuristic 1
[(3,3) (3,4)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 5 backward ] to get state below with path cost 10 and heuristic 1
[(3,3) (3,4)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(1,5) (2,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 11 and heuristic 0
[(3,4) (3,5)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(1,5) (2,5)] [(4,5) (5,5)]Expanded 109 states

[Heuristic 2]
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(2,1) (3,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 3 forward ] to get state below with path cost 1 and heuristic 2
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(3,1) (4,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 3 forward ] to get state below with path cost 2 and heuristic 2
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 backward ] to get state below with path cost 3 and heuristic 3
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(1,3) (2,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 4 and heuristic 4
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(2,3) (3,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 5 and heuristic 5
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(3,3) (4,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 4 forward ] to get state below with path cost 6 and heuristic 4
[(3,1) (3,2)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 7 and heuristic 3
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,4) (1,5)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 2 backward ] to get state below with path cost 8 and heuristic 3
[(3,2) (3,3)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 9 and heuristic 1
[(3,3) (3,4)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(2,5) (3,5)] [(4,5) (5,5)]  Perform action [Move car 5 backward ] to get state below with path cost 10 and heuristic 1
[(3,3) (3,4)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(1,5) (2,5)] [(4,5) (5,5)]  Perform action [Move car 0 forward ] to get state below with path cost 11 and heuristic 0
[(3,4) (3,5)]* [(1,1) (1,2)] [(1,3) (1,4)] [(4,1) (5,1)] [(4,3) (5,3)] [(1,5) (2,5)] [(4,5) (5,5)]Expanded 75 states
