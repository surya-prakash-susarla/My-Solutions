t=int(raw_input())
import sys
for o in range(t):
    size=int(raw_input())
    a=[]
    for i in range(size):
        temp=raw_input()
        li = list(temp)
        li.sort()
        temp = ''.join(str(x) for x in li)
        a.append(temp)
    for i in range(1,size):
        if a[i][0]<a[i-1][0]:
            a[i],a[i-1]=a[i-1],a[i]
    for i in range(size):
        for j in range(1,size):
            if a[i][j]<a[i][j-1]:
                print "NO"
                sys.exit()
    print "YES"
