coin=[int(x) for x in raw_input("enter the coin denominations\n").split()]
value = int(raw_input("enter the sum to be found\n"))

def coiner(val,a):
    print "current value is ",val," the array is ",a
    if val<0:
        return 0
    if val==0:
        return 1
    temp  = coiner(val-a[0],a)
    temper=0
    if len(a)>1:
        temper = coiner(val,a[1:])
    print "number of ways of ",val," using the array ",a," are ",temp+temper
    return temp+temper


print coiner(value,coin)
