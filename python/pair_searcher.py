size,diff=raw_input().split()
diff=int(diff)
size=int(size)
a=[int(x) for x in raw_input().split()]

a.sort()

def bin_search(element, start ,stop):
    start=int(start)
    stop=int(stop)
    while start<=stop:
        mid=(start+stop)/2
#        print "mid=",mid
        mid_ele=a[mid]

        if element>mid_ele:
            start=mid+1
        elif element<mid_ele:
            stop=mid-1
        elif element==mid_ele:
            return True
    return False

counter=0
for i in a:
    i=int(i)
    if bin_search(i+diff,0,size-1):
        counter+=1

print counter
