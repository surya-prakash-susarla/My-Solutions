t = int(raw_input())
for x in range(t):
    m,n = raw_input().split()
    m=int(m)
    n=int(n)
    a=[]
    for x in range(m):
        a.append(raw_input())
    guess=int(raw_input())
    c='M'
    def find_starting_point():
        #print "searching for the starting point of the matrix "
        for i in range(m):
            if c in a[i]:
        #        print "starting point found at ",i," ",a[i].index(c)
                return i,a[i].index(c)
        return -1
    stx,sty=find_starting_point()
    c='*'
    def find_port_hole():
        #print "searching for port hole"
        for i in range(m):
            if c in a[i]:
        #        print "port hole found at ",i," ",a[i].index(c)
                return i,a[i].index(c)
        return -1
    enx,eny=find_port_hole()
    
    def find_multi_path(x,y,inx,iny):
        #print "searching if multiple paths exist for given point ",x," ",y
        par_po=[x,y]
        prev=[inx,iny]
        pts=[]
        if x-1>=0 and (a[x-1][y]=='.' or a[x-1][y]=='*'):
            temp=[]
            temp.append(x-1)
            temp.append(y)
            pts.append(temp)
        if x+1<m and (a[x+1][y]=='.' or a[x+1][y]=='*'):
            temp=[]
            temp.append(x+1)
            temp.append(y)
            pts.append(temp)
        #print a[x][y-1]
        if y-1>=0 and (a[x][y-1]=='.' or a[x][y-1]=='*'):
            temp=[]
            temp.append(x)
            temp.append(y-1)
            pts.append(temp)
        if y+1<n and (a[x][y+1]=='.' or a[x][y+1]=='*'):
            temp=[]
            temp.append(x)
            temp.append(y+1)
            pts.append(temp)
        if prev in pts:
            pts.remove(prev)
        #print "total further destinations are ",pts
        if len(pts)>1:
            return True,pts,par_po
        else:
            return False,pts,par_po
    k=0
    main_k=-1
    def find_path(start,end,inx,iny,k):
        global main_k
        #print "current point is ",start," ",end
        #print "parent point is ",inx," ",iny
        #print "current wand wave value is ",k
        if start==enx and end==eny:
        #    print "\nreached end value. Value of k is ",k
            main_k=k
            return k
        #print "not at end point , finding further directions"
        val,pts,par = find_multi_path(start,end,inx,iny)
        if val:
        #    print "\nwand waved , value updated ",k
            k+=1
        for i in pts:
            find_path(i[0],i[1],par[0],par[1],k)
    #print "beginning search"
    k=find_path(stx,sty,-1,-1,k)
    #print "search ended. value of k is ",k
    if main_k==guess:
        print "Impressed"
    else:
        print "Oops!"
