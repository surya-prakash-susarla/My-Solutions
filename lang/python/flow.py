t=int(raw_input())
for o in range(t):
    n,rels=map(int,raw_input().split())
    dist=[]
    for i in range(n):
        temp=[]
        for j in range(n):
            temp.append(-1)
        dist.append(temp)
    for i in range(rels):
        a,b=map(int,raw_input().split())
        dist[a-1][b-1]=6
        dist[b-1][a-1]=6
    for k in range(n):
        for i in range(n):
            if i==k:
                continue
            else:
                for j in range(n):
                    if j==k or j==i:
                        continue
                    else:
                        if dist[i][k]!=-1 and dist[k][j]!=-1:
                            if dist[i][j]==-1:
                                dist[i][j]=dist[i][k]+dist[k][j]
                            elif dist[i][j]>dist[i][k]+dist[k][j]:
                                dist[i][j]=dist[i][k]+dist[k][j]
    #print "\n\n\nThe final matrix is "
    #for  i in dist:
    #    print i
    cit = int(raw_input())-1
    for i in range(n):
        if i!=cit:
            print dist[cit][i]," ",
    print ""
