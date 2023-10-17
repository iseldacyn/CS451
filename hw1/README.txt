=== Geography Problem ===
State: Set of words in a specific order (i.e. last letter is first letter of next word)
	Additionally, there is a list of words to be added to that set

Initial State: One word to start with a list of words to be added in a row

Goal Test: Check if each word in the list has been added

Action/Successor Function: Add a new word to the set from the list of words, obeying the constraint

Program Output:
Test Case 1- No Solution on either method
Test Case 2- ABC CFG GKG GJC CDE EHI

*Was this supposed to print the output ONLY on success? I had it to only print on success, to prevent clutter on my terminal window
**Especially in PCP with infinite loops

Test 2 Solution Output:
Solution Found!
Initial State: ABC
Action: Continue with word CFG
State: ABC CFG
Action: Continue with word GKG
State: ABC CFG GKG
Action: Continue with word GJC
State: ABC CFG GKG GJC
Action: Continue with word CDE
State: ABC CFG GKG GJC CDE
Action: Continue with word EHI
State: ABC CFG GKG GJC CDE EHI

=== PCP Problem ===
State: Configuration of concatenated string from the top and bottom of domino

Initial State: Starting strings from the first domino

Goal Test: Check if top string matches bottom string

Action/Successor Function: Add a top/bottom string from another domino to current top/bottom string

Program Output:
Test Case 1- MOMOMOM (BFS), Infinite loop (DFS)
Test Case 2- Infinite loop on either method

Test 1 Solution Output (BFS):
Solution Found!
Initial State: [ Top String: MOM === Bottom String: M ]
Action: Concatenate domino 2
State: [ Top String: MOMO === Bottom String: MOMOMO ]
Action: Concatenate domino 1
State: [ Top String MOMOMOM === Bottom String: MOMOMOM ]
