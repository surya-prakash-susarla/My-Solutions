def recursive_thinker(a,sumval,highest,mod):
    mod=int(mod)
    sumval=int(sumval)
    highest=int(highest)
    if a==None or len(a)==0:
        return highest
    tem = sumval+a[0]
    if sumval%mod>highest:
        highest=sumval%mod
    if tem%mod>highest:
        highest=tem%mod
    a.remove(a[0])
    return max(recursive_thinker(a,tem,highest,mod),recursive_thinker(a,sumval,highest,mod))


lopper = int(raw_input())
for o in range(lopper):
    n,mod = raw_input().split()
    a = [int(x) for x in raw_input().split()]
    highest=-1
    print recursive_thinker(a,0,highest,mod) 
