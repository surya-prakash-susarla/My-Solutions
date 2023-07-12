a=[]
for i in range(250,501):
    a.append(i)

t= int(raw_input())
while t>0:
    f = int(raw_input())
    for i in range(f):
        print a[i],
    print ""
    t-=1
