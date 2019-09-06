# Tic-tac-toe

An implementation of minimax algorithm to construct an unbeatable AI in Tic-Tac-Toe.

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
  

## Can be used to code the perfect algorithm for any two player based game
