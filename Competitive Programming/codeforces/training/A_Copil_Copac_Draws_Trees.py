# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def insr():
    s = input()
    return list(s[:len(s) - 1])

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############

def dfs(u, edges, dp, idx):
    for edge in edges[u]:
        v = edge[0]
        crt_id = edge[1]
        if dp[v] == 0:
            dp[v] = dp[u]
            if crt_id < idx[u]:
                dp[v] += 1
            idx[v] = crt_id
            dfs(v, edges, dp, idx)

# Main function
for _ in range(inp()):
    n = inp()
    edges = [[] for _ in range(n+1)]
    for i in range(n-1):
        u, v = invr()
        edges[v].append([u, i])
        edges[u].append([v, i])
    idx = [0]*(n+1)
    dp = [0]*(n+1)
    dp[0] = dp[1] = 1
    dfs(1, edges, dp, idx)
    print(max(dp))
        