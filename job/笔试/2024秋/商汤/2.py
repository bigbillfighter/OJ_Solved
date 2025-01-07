import sys

line_data = []

for line in sys.stdin:
    line_data.append(line.strip())

# line_data = ["6 6 3 3"]

line_data = line_data[0].split(' ')
n, m, x, y = int(line_data[0]), int(line_data[1]), int(line_data[2]), int(line_data[3])

ans = 0

places = [(x, y), (x-1, y+2), (x-1, y-2), (x+1, y+2), (x+1, y-2), (x-2, y+1), (x-2, y-1), (x+2, y-1), (x+2, y+1)]
places = [(p[0], p[1]) for p in places if ((p[0] >= 0 and p[0] <=n) and (p[1] >=0 and p[1] <= m))]

def dfs(x, y, n, m):
    global ans
    if x==n and y == m:
        ans += 1
        return
    if(x > n or y > m):
        return
    
    if((x, y) in places):
        return
    
    dfs(x, y+1, n, m)
    dfs(x+1, y, n, m)

dfs(0, 0, n, m)
print(ans)
