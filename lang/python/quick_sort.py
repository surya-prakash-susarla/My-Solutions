a=raw_input("Enter the numbers\n").split(" ")
def quick(a):
	if len(a)<=1:
		return a
	pivot=len(a)/2
	i=0
	j=len(a)-1
	num=a[pivot]
	while i<=pivot and j>=pivot:
		if a[i]<a[pivot] and a[j]>a[pivot]:
			i+=1
			j-=1
		if a[i]<a[pivot] and a[j]<a[pivot]:
			i+=1
		if a[i]>a[pivot] and a[j]>a[pivot]:
			j-=1
		if a[i]>a[pivot] and a[j]<a[pivot]:
			a[i],a[j]=a[j],a[i]
			i+=1
			j-=1
		if i==pivot and j>pivot:
			if a[i]>a[j]:
				a[i],a[j]=a[j],a[i]
				j-=1
			elif a[i]<a[j]:
				j-=1
		if j==pivot and i<pivot:
			if a[j]<a[i]:
				a[i],a[j]=a[j],a[i]
				i+=1
			elif a[j]>a[i]:
				i+=1
				
		if i==j:
			break
	pivot = a.index(num)
	f=quick(a[0:pivot])
	g=quick(a[pivot+1:len(a)])
	f.append(a[pivot])
	f=f+g
	return f
	
print quick(a)
