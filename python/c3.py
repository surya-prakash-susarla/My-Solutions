t = int(raw_input())

for o in range(t):
    n = int(raw_input())
    total=0
    for i in range(n):
        temp = int(raw_input())
        total = total+temp
    if total%n==0:
        print("YES")
    else:
        print("NO")
