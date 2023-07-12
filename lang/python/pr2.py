import mechanize
from bs4 import BeautifulSoup
br = mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
response = br.open('https://www.youtube.com/playlist?list=PLKHT767gKxYBZKZhEwCZjJ2XLu9aI7psz')
print response.code
soup = BeautifulSoup(response,'html.parser')
name  = soup.find(attrs={'class':'pl-video yt-uix-tile yt-uix-dragdrop-draggable-item'})
n = name['data-title']
print n
