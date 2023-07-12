a=str(raw_input())
b=str(raw_input())

a = int(a,2)
b = int(b,2)

print a,b

summer=0
for i in range(314160):
    print "in for loop"
    b=b<<i
    temp = a^b
    summer+=temp


print "for loop compeleted"
print summer%(10**9+7)
