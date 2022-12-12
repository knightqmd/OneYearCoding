a,b=map(int,input().split())
vs = []
ws = []
dp = [[0 for i in range(a+1)] for j in range(b+1)]
for i in range(a):
    _v,_w = map(int,input().split(" "))
    vs.append(_v)
    ws.append(_w)
for i in range(a+1):
    for j in range(b+1):
        if i == 0:
            break
        if j<vs[i-1]:
            dp[j][i] = dp[j][i-1]
        else:
            dp[j][i] = max(dp[j][i-1],dp[j-vs[i-1]][i-1]+ws[i-1])

print(dp[b][a])    