a = []
a = raw_input("Enter the numbers\n").split(" ")

def find_lo(f):
	l=a[f]
	index=-1
	for i in range(f+1,len(a)):
		if a[i]<l:
			l=a[i]
			index=i
	a[index]=a[f]
	a[f]=l
	if f<len(a)-1:	
		find_lo(f+1)

find_lo(0)

for i in a:
	print i
