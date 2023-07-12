t=int(raw_input())
for o in range(t):
    x,y,z = map(int,raw_input().split())
    a=abs(x-z)
    b=abs(y-z)
    if a>b:
        print "Cat B"
    elif a<b:
        print "Cat A"
    elif a==b:
        print "Mouse C"
