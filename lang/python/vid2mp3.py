#sudo apt-get install lame
#sudo apt-get install mplayer
from subprocess import call
import os
print os.getcwd()
os.chdir("/home")
print os.path.exists('ret.mp4')
os.chdir("/home/surya/Desktop/code")
print os.path.getsize('ret.mp4')
print os.path.splitext('ret.mp4')
call(['mplayer',"-novideo","-nocorrect-pts","-ao","pcm:waveheader",'ll.mkv'])
call(['lame','-h','-b','320','audiodump.wav','ll.mp3'])
os.remove('audiodump.wav')
print "operation done"
