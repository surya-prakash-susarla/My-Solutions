p=raw_input()
a=raw_input()
b=[int(x) for x in a.split()]
less=[]
equal=[]
great=[]
pivot=b[0]
def printer(a):
	for i in a:
		print i,
for i in b:
	if i<pivot:
		less.append(i)
	elif i>pivot:
		great.append(i)
	else:
		equal.append(i)
printer(less)
printer(equal)
printer(great)
