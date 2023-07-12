n,s,t=map(int,raw_input().split())
r=[]
for i in range(n):
    r.append(-1)
r[0],g,se,p=map(int,raw_input().split())
for i in range(1,n):
    r[i]=(r[i-1]*g+se)%p
vals=[]
visited=[]
def cir(st,value):
    #print "current postion is ",st , "value is ",value
    global t
    if st==t:
    #    print "found destination , value is ",value
        vals.append(value)
        return
    if st in visited:
        return
    visited.append(st)
    if r[st]==0:
        return
    temp=1
    #print "entering pos while , ",r[st]
    while temp<=r[st]:
        cir((st+temp)%n,value+1)
        temp+=1
    temp=1
    #print "entering neg while"
    while temp<=r[st]:
        if st<temp:
            cir(n+st-temp,value+1)
        else:
            cir(st-temp,value+1)
        temp+=1
    #print "exiting funciton from ",st
    return
cir(s,0)
print min(vals)
