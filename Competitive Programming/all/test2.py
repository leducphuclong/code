from collections import deque

MOD = 10**9 + 7

n, m = map(int, input().split())
a = n
b = 1

adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[v].append(u)

visited = [False] * (n+1)
visited[a] = True
ways = [0] * (n+1)
ways[a] = 1

q = deque()
q.append(a)

while q:
    u = q.popleft()
    for v in adj[u]:
        if not visited[v]:
            visited[v] = True
            q.append(v)
        ways[v] = (ways[v] + ways[u]) % MOD

print(ways[b])