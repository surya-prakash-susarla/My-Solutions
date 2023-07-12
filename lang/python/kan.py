import sys
k1,v1,k2,v2=raw_input().split(" ")
k1=int(k1)
v1=int(v1)
k2=int(k2)
v2=int(v2)
if v1==v2:
	print "NO"
	sys.exit()
z=(k2-k1)%(v1-v2)
r=(k2-k1)/(v1-v2)
z=int(z)
r=int(r)
k1+=v1
k2+=v2
if z==0 and r>=0:
	print "YES"
else:
	print "NO"
