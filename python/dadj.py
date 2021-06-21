n = int(raw_input())
a=[]
for i in range(n):
    temp = [int(x) for x in raw_input().split()]
    a.append(temp)

visited=[]
s,d = map(int,raw_input().split())

def dfs(row,val):
    print row,d
    temp=row[d]
    if temp==1:
        return val
    for i in row:
        if i==1 and i not in visited:
            dfs(i,val+1)
    return -1

print dfs(a[s],0)
