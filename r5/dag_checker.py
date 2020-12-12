from collections import defaultdict

if __name__ == "__main__":
    n = int(input())
    adj = {}
    for node in range(1, n + 1):
        targets = [int(x) for x in input().strip().split(' ')]
        if len(targets) != 2:
            raise ValueError('wrong number of target nodes')
        targets = [t for t in targets if t != -1]
        adj[node] = targets
    paths = defaultdict(int)
    paths[1] = 1
    for node in range(1, n):
        for target in adj[node]:
            paths[target] += paths[node]
    total = paths[n]
    print(f'{total} paths found from 1 to {n}')
