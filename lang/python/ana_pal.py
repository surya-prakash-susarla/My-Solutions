import sys
s=raw_input()
c=[]
r=[]

for i in s:
	if i in c:
		r[c.index(i)]+=1
	else:
		c.append(i)
		r.append(1)
		
odd=False

for i in r:
	if i%2!=0:
		if not odd:
			odd=True
		else:
			print "NO"
			sys.exit()	
			
print "YES"
