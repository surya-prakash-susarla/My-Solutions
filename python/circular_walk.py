n,s,t = map(int,raw_input().split())
a=[]
for i in range(n):
    a.append(-1)
a[0],g,se,p = map(int,raw_input().split())
for i in range(1,n):
    a[i] =(a[i-1]*g+se)%p


visited=[]
possib=[]
def cir(st,val):
    #print "current position : ",st
    global t
    #print "destination point is ",t
    #print "destination tracker " , st==t
    if st in visited:
        return
    if st==t:
    #    print "\n\t\tReturning the value of traversal ----- ",val
        possib.append(val)
        return val
    dist = a[st]
    #print "max distance is ",dist
    visited.append(st)
    temp=1
    w=r=None
    while temp<=dist:
    #    print "in while loop----temp=",temp
        w = cir((st+temp)%n,val+1)
        if st<temp:
            r = cir((n+st-temp),val+1)
        else:
            r = cir(st-temp,val+1)
        temp+=1
    if w!=None and r!=None:
        return min(w,r)
    elif w!=None:
        return w
    elif r!=None:
        return r
    else:
    	return
    	
cir(s,0)
print min(possib)
