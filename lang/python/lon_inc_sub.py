a=raw_input("enter numbers\n").split(" ")
l=[]
for i in range(len(a)):
	l.append(1)
	largest=1
	for j in range(0,i):
		if a[j]<a[i] and l[j]>largest:
			largest=l[j]
	l[i]+=largest

print largest
