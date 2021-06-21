import sys
t=int(raw_input())
for i in range(t):
    m=int(raw_input())
    n=int(raw_input())
    a=[int(x) for x in raw_input().split()]
    b=[]
    for i in range(n):
        b.append(a[i])
    a.sort()
    mini=0
    maxi=-1
    minimax = m-a[mini]
    for i in range(n-1,0,-1):
        if a[i]<=minimax:
            maxi=i
            break
#print a,b,mini,maxi,minimax,a[mini]+a[maxi]
    while mini<maxi and maxi>=mini:
        if a[mini]+a[maxi]>m:
            maxi-=1
        elif a[mini]+a[maxi]<m:
            mini+=1
        elif a[mini]+a[maxi]==m:
            mi = b.index(a[mini])
            b[b.index(a[mini])]=-1
            ma = b.index(a[maxi])
            b[b.index(a[maxi])]=-1
            print min(mi+1,ma+1),
            print max(mi+1,ma+1)
            break
