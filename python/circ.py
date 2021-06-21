n,st,t= map(int,raw_input().split())
a=[]
for i in range(n):
    a.append(-1)
a[0],g,se,p =map(int,raw_input().split())
for i in range(1,n):
    a[i]=(a[i-1]*g+se)%p
visited=[]
vals=[]
def trav(s,val):
    print s,val
    if s in visited:
        return
    visited.append(s)
    global t
    if s==t:
        vals.append(val)
        return
    if a[s]==0:
        return
    g=1
    temp=val+1
    while g<=a[s]:
        print "in while loop"
        trav((s+g)%n,temp)
        if s<g:
            trav(n+s-g,temp)
        else:
            trav((s-g),temp)
        g+=1
    return

trav(st,0)
print "final value is ",min(vals)
