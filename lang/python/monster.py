n,hit,t = map(int,raw_input().split())
a=[int(x) for x in raw_input().split()]
a.sort()
killed=0
while t>0 and len(a)>=1:
    a[0]-=hit
    if a[0]<=0:
        killed+=1
        a.remove(a[0])
    t-=1
print killed
