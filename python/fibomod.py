t1,t2,n = map(int,raw_input().split())
fib=[]
fib.append(t1)
fib.append(t2)
for i in range(2,n):
    temp = fib[i-2]+fib[i-1]**fib[i-1]
    fib.append(temp)
print fib[n-1]
