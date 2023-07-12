import sys
t=raw_input()
a=raw_input()
b=[int(x) for x in a.split()]
def sorted(a):
	for i in range(len(a)-1):
		if a[i]>a[i+1]:
			return False
	return True
def printer(a):
	for i in a:
		print i,
def quick(a):
	#print "array to be sorted is ",a
	if len(a)<=1:
		return a
	else:
		pivot=a[0]
		less=[]
		great=[]
		equal=[]
		for i in a:
			if i==pivot:
				equal.append(i)
			elif i<pivot:
				less.append(i)
			else:
				great.append(i)
		less=quick(less)
		great=quick(great)
		#if sorted(less) and len(less)>1:
		#	printer(less)
		#	sys.stdout.write("\n")
		#if sorted(great) and len(great)>1:
		#	printer(great)
		#	sys.stdout.write("\n")
		z=less+equal+great
		if sorted(z) and len(z)>1:
			printer(z)
			sys.stdout.write("\n")
	return z
f=quick(b)
