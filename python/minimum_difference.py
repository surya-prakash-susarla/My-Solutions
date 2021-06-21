n = int(raw_input())
lister = raw_input().split(" ")
lister = [int(i) for i in lister]

def quick_sort(lister):
	if len(lister)<=1:
		return lister
	middle = len(lister)/2
	element = lister[middle]
	left =[]
	right = []
	for i in range(len(lister)):
		if i!=middle:
			if lister[i]<element:
				left.append(lister[i])
			else:
				right.append(lister[i])
	left = quick_sort(left)
	right = quick_sort(right)
	final_temp = left
	final_temp.append(element)
	final_temp = final_temp+right
	return final_temp

#print "sending the list for sorting"
lister = quick_sort(lister)
#print "the list after sorting is "
#print lister

def mini_pairs ( lister ):
	mini =-1
	final_answer = []
	for i in range(n-1):
		if mini==-1:
			mini = lister[i+1] - lister[i]
			final_answer.append(lister[i])
			final_answer.append(lister[i+1])
			print "appending ",lister[i]," ",lister[i+1]
		elif lister[i+1]-lister[i]<mini:
			del final_answer[:]
            print "appending ",lister[i]," ",lister[i+1]
			final_answer.append(lister[i])
			final_answer.append(lister[i+1])
		elif lister[i+1]-lister[i]==mini:
            print "appending ",lister[i]," ",lister[i+1]
			final_answer.append(lister[i])
			final_answer.append(lister[i+1])
	return final_answer

#print "calculating the answer function"
answer = mini_pairs(lister)
final_answer = quick_sort(answer)
for i in final_answer:
	print i,
