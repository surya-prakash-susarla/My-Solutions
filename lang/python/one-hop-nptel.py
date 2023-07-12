
def hopper ( destinations , a ):
    for pairs in range(len(a)):
        i = a[pairs][0]
        j = a[pairs][1]
        for val in range(len(a)):
            temp=[]
            if val!=pairs:
                if i==a[val][0] and j!=a[val][1]:
                    temp.append(a[val][1])
                    temp.append(j)
                    destinations.append(tuple(temp))
                elif i==a[val][1] and j!=a[val][0]:
                    temp.append(a[val][0])
                    temp.append(j)
                    destinations.append(tuple(temp))
    return destinations

a= []

n = int(raw_input("enter the number of tuples\n"))

for i in range(n):
    a.append(tuple(map(int,raw_input().split(','))))
destinations = []
destinations = hopper ( destinations , a )
print destinations
