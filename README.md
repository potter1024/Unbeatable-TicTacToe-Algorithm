# Tic-tac-toe

An implementation of minimax algorithm to construct an unbeatable AI in Tic-Tac-Toe.
Time complexity is O(number of states) which is less than 10^6 in tic-tac-toe

Total states = 549946

If computer starts then:
  number of win states = 131184
  number of lose states= = 77904
  number of tie states = 46080

If player starts:
  number of win states = 77904
  number of lose states= = 131184
  number of tie states = 46080


Also improved it to win in the smallest number of steps by taking the cost of depth into account.

Naive:
  computer: max of all children
  player: min of all cheldren
Improved:
  win: max of all children - depth
  lose: min of all children + depth
  


Psuedocode for building game tree:

  def minimax:
    if win:
      return 10
    if lose:
      return -10
    if draw:
      return 0
    if computer's turn:
      choose maximum of all children - depth
    if player's turn:
      choose minimum of all children + depth
     

Psuedocode for gameplay:

  continue until terminal state occurs:
     take user input and define it as b
     find the maximum score node connected to b
     set b as this node and recurse




## Can be used to code the perfect algorithm for any two player based game
