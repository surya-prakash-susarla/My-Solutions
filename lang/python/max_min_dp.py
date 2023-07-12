
def sum_max(a):
    if len(a)==1:
        return a[0]
    func = sum_max(a[1:])
    print "if added ",a[0]," then the value = ",a[0]+func
    print "if not added then the value = ",func
    print "\nfinally returning======================",max(a[0]+func,func)
    print "present a = ",a
    return max(a[0]+func,func)

print "enter the numbers in the array"
a=[int(x) for x in raw_input().split()]
print sum_max(a)
