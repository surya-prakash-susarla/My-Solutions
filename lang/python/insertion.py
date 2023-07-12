a = [] 
a = raw_input("Enter the numbers\n").split(" ")
for i in range(1,len(a)):
	j = i-1
	k = i
	while j>=0:
		if a[j]>a[k]:
			temp = a[j]
			a[j] = a[k]
			a[k] = temp
			k = j
		j = j-1
for i in a:
	print i
		
	
