class data:
    num=string=None
    def __init__(self,num,string):
        self.num=num
        self.string=string

size = int(raw_input())
num=[]
string=[]

for i in range(size):
    t,t1=map(str,raw_input().split())
    num.append(t)
    string.append(t1)

md = []
for i in range(size):
    md.append(data(num[i],string[i]))
for i in range(size/2):
    md[i].string="-"


def sorted(a):
    for i in range(len(a)-1):
        if a[i].num>a[i+1].num:
            return False
    return True

def quick(a):
    if len(a)<=1:
        return a
    else:
        pivot=a[0].num
        less=[]
        great=[]
        equal=[]
        for i in a:
            if i.num==pivot:
                equal.append(i)
            elif i.num<pivot:
                less.append(i)
            else:
                great.append(i)
        less=quick(less)
        great=quick(great)
        z=less+equal+great
    return z

z = quick(md)
#print "Final after sorting is "
for i in range(len(z)):
    print z[i].string,
