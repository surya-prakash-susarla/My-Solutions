a  = raw_input("Enter the numbers\n").split(" ")
for j in range(0,len(a)):
	for i in range(len(a)-1):
		if a[i]>a[i+1]:
			a[i],a[i+1]=a[i+1],a[i]
print a
