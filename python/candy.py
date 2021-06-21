size = int(raw_input())
a=[int(x) for x in raw_input().split()]
f=[]
f[0]=1
for i in range(1,size):
    if a[i]>a[i-1]:
        f[i]=f[i-1]+1
    else:
        f[i]=1

for i in range(size,1,-1):
    if a[i]>a[i-1]:
        f[i]=f[i-1]+1
    else:
        f[i]=i

print sum(f)
