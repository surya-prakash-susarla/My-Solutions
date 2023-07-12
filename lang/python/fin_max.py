a=[int(x) for x in raw_input().split()]
highest=-1
def contig_max(a):
    global highest
    if(len(a)==1):
        return a[0]
    func=contig_max(a[1:])
    added=a[0]+func
    not_added=func
    print added , not_added
    if max(added,not_added)==added:
        print "max sum is contiguous"
        return added
    else:
        if highest==-1 or not_added>highest:
            highest=not_added
        print "non contiguous max sum"
        return 0

print contig_max(a)
