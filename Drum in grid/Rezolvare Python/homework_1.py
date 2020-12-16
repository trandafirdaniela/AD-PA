def solve1(aux,n):
    mat=[[]]
    mat = [[0 for x in range(n+1)] for y in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            mat[i][j]=aux[i-1][j-1]
    
    for i in range(0,n+1):
        mat[i][0]=0
        mat[0][i]=0
    cost = [[]]
    cost = [[0 for x in range(n+1)] for y in range(n+1)]
    for i in range(0,n+1):
        cost[0][i]=8000000000000
        cost[i][0]=8000000000000
    cost[0][1]=0
    cost[1][0]=0
    for i in range (1,n+1):
        for j in range(1,n+1):
            if(cost[i-1][j]!=8000000000000 or cost[i][j-1] != 8000000000000):
                cost[i][j]=min(abs(mat[i][j-1]-mat[i][j])+cost[i][j-1],abs(mat[i-1][j]-mat[i][j])+cost[i-1][j])
    result = cost[n][n]-mat[1][1]
    return result
