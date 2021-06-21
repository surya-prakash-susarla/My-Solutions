import os
import time

not_executed=1

print("Enter the time of the alarm to be set")
x,y=raw_input().split(' ')

while(not_executed):
    dt=list(time.localtime())
    hour=dt[3]
    minute=dt[4]
    print("%s and %s , given %s and %s"%(hour,minute,x,y))
    if hour==x and minute==y:
        print "Inside the loop "
        os.popen2("open E:\Songs\TOD.mp3")
        not_executed=0