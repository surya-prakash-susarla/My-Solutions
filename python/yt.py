from bs4 import BeautifulSoup
import mechanize
import youtube_dl
from subprocess import call
import os
import sys
def dash_printer():
	for i in range(15):
		sys.stdout.write("-")
br=mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
dash_printer()
sys.stdout.write("Attempting to get Youtube main page")
dash_printer()
sys.stdout.write("\n")
response=br.open("https://www.youtube.com/")
br.select_form(id="masthead-search")
search = br.form.find_control(id="masthead-search-term")
#Enter the name to be searched
dash_printer()
sys.stdout.write("Enter the name of the file to be downloaded")
dash_printer()
sys.stdout.write("\n")
inp_search_string=raw_input()
search.value=inp_search_string
response=br.submit(id="search-btn")
#print response.get_data()
if int(response.code)==200:
	print "Video found after search"
soup=BeautifulSoup(response,'html.parser')
vid=soup.find(attrs={'class':'yt-uix-tile-link'})
print vid['href']
st="https://www.youtube.com"+vid['href']
dash_printer()
sys.stdout.write("Video found.Download starts now")
dash_printer()
sys.stdout.write("\n")
#change video url for enabing search based downloads
#st="https://www.youtube.com/watch?v=bCGmUCDj4Nc"
print st
command = "youtube-dl "+st
print command,"\n\n"
prev_file=[]
for f in os.listdir('.'):
	prev_file.append(f)
call(command.split(),shell=False)
call(['ls','-1'])
dash_printer()
sys.stdout.write("Download done. Conversion about to begin.")
dash_printer()
sys.stdout.write("\n")
new_file=[]
for f in os.listdir('.'):
	new_file.append(f)
fil_found=set(prev_file)^set(new_file)
print fil_found
if len(fil_found)==0:
	dash_printer()
	sys.stdout.write("File with same name already exists")
	dash_printer()
	sys.stdout.write("\n")
	sys.exit()
fil_found=list(fil_found)
call(["mplayer","-novideo","-nocorrect-pts","-ao","pcm:waveheader",fil_found[0]])
name=fil_found[0].rsplit('.',1)[0]
print "\n",name,"\n"
call(['lame','-h','-b','320','audiodump.wav',name+'.mp3'])
os.remove('audiodump.wav')
dash_printer()
sys.stdout.write("Conversion done")
dash_printer()
sys.stdout.write("\n")
print "File can be found in the current working directory"
dash_printer()
sys.stdout.write("Operation done.")
dash_printer()
sys.stdout.write("\n")
