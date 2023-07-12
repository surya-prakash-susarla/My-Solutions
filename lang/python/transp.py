l=[[1,2,3],[2,3,1]]

def transpose(l):
    rows = len(l)
    col = len(l[0])
    print rows,col
    k=[[0 for i in range(rows)] for y in range(col)]
    for i in range(len(l)):
        for j in range(len(l[0])):
            k[j][i]=l[i][j];
    print k

transpose(l)
