n = int(raw_input())
a=[]
for i in range(n):
    a.append(int(raw_input()))

def quick_sort ( lister ):
    #print "current list is ",lister
    if len(lister)<=1:
        return lister
    else:
        middle = len(lister)/2
        pivot = lister[middle]
        #print "value of middle = ",middle,"\tvalue of pivot = ",pivot
        left =[]
        right =[]
        for i in range(len(lister)):
            if i!=middle:
                if lister[i]<pivot:
                    left.append(lister[i])
                else:
                    right.append(lister[i])
        #print "the initial value of left is ",left
        #print "the initial value of right is ",right
        left = quick_sort(left)
        right = quick_sort(right)
        #print "final value of left is ",left
        #print "final value of right is ",right
        final_temp = left
        final_temp.append(pivot)
        final_temp = final_temp+right
        #print "final value of final_temp is ",final_temp
        return final_temp

answer = quick_sort(a)
#print "printing the answer"
for i in answer:
    print i
