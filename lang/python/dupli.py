s='0'
while len(s)<=1000:
    d=len(s)
    t=''
    for i in s:
        if i=='1':
            t=t+'0'
        else:
            t=t+'1'
    s=s+t
#print s
test = int(raw_input())
for i in range(test):
    print s[int(raw_input())]
