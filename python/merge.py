n = int(raw_input())
a=raw_input().split(" ")
a = [int(i) for i in a]
def merge_sort(lister):
	if len(lister)==1:
		return lister
	else:
		#print "current list is ",lister
		middle = len(lister)/2
		#print "value of middle is ",middle
		temp1 = merge_sort(lister[:middle])
		temp2 = merge_sort(lister[middle:])
		#print "temp1 = ",temp1
		#print "temp2 = ",temp2
		final_temp=[]
		i,j=0,0
		while i<len(temp1) and j<len(temp2):
			if temp1[i]<temp2[j]:
				final_temp.append(temp1[i])
				i=i+1
			elif temp1[i]>temp2[j]:
				final_temp.append(temp2[j])
				j=j+1
			else:
				final_temp.append(temp1[i])
				final_temp.append(temp2[j])
				i=i+1
				j=j+1
		while i<len(temp1):
			final_temp.append(temp1[i])
			i=i+1
		while j<len(temp2):
			final_temp.append(temp2[j])
			j=j+1
		#print "final temp = ",final_temp
		return final_temp

#print "before calling the merge sort function"
for i in merge_sort(a):
	print i
