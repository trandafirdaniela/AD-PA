from collections import deque

def solve2(mat,n):
    valoare =10101010
    cost = []
    for i in range (0,n):
        cost.append([])
    for i in range (0,n):
         for j in range (0,n):
             cost[i].append(j)
             cost[i][j] = 10101010
    cost[0][0] = 0
    de = deque()
    de.append(0)
    de.append(0)
    while   de:
        i = de.popleft()
        j = de.popleft()

        if i+1 < n:
            if cost[i+1][j] == 10101010:
                de.append(i+1)
                de.append(j)
            cost[i+1][j] = min( cost[i+1][j], cost[i][j] + abs( mat[i][j] - mat[i+1][j]) )


        if j+1 < n:
            if cost[i][j+1] == 10101010:
                de.append(i)
                de.append(j+1)
            cost[i][j+1] = min( cost[i][j+1], cost[i][j] + abs( mat[i][j] - mat[i][j+1]) )
    return cost[n-1][n-1]
