m=int(raw_input())
n=int(raw_input())

a=[]
for i in range(m):
    temp=[int(x) for x in raw_input().split()]
    a.append(temp)

def printer():
    for i in a:
        print i
 
printer()


def finder():
    for i in range(m):
        if 1 in a[i]:
            return i,a[i].index(1)
    return -1

def path_finder(i,j,counter):
    i=int(i)
    j=int(j)
    counter=int(counter)
    counter+=1
    a[i][j]==2
    if i-1>=0:
        if j-1>=0 and a[i-1][j-1]==1:
            counter+=path_finder(i-1,j-1,counter)
        if j>=0 and j<n and a[i-1][j]==1:
            counter+=path_finder(i-1,j,counter)
        if j+1<=n and a[i-1][j+1]==1:
            counter+=path_finder(i-1,j+1,counter)
    if j-1>=0:
        counter+=path_finder(i,j-1,counter)
    if j+1<n:
        counter+=path_finder(i,j+1,counter)
    if i+1<m:
        if j-1>=0 and a[i+1][j-1]==1:
            counter+=path_finder(i+1,j-1,counter)
        if j>=0 and j<n and a[i+1][j]==1:
            counter+=path_finder(i+1,j,counter)
        if j+1<n and a[i+1][j+1]==1:
            counter+=path_finder(i+1,j+1,counter)
    return counter
answers=[]

while finder()!=-1:
    i,j=finder()
    answers.append(path_finder(i,j,0))

print max(answers)
