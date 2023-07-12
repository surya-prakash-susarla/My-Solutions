size=int(raw_input())

a=[]

for i in range(size):
    t,t1 = raw_input().split()
    if i<size/2:
        temp=[]
        temp.append(int(t))
        temp.append("-")
        a.append(temp)
    else:
        temp=[]
        temp.append(int(t))
        temp.append(t1)
        a.append(temp)

a.sort(key=lambda tup:tup[0])

for i in a:
    print i[1],
