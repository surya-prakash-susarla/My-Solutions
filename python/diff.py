num,dif = raw_input().split()
dif = int(dif)
a=[int(x) for x in raw_input().split()]

def checker(num):
    #print "checking for ",num
    b=set(a)
    if num in b:
        return True
    return False

counter=0
for i in a:
    if checker(i+dif):
        counter+=1

print counter
