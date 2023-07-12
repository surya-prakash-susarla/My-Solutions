from bs4 import BeautifulSoup
import urllib
url = urllib.urlopen("te.html")
soup = BeautifulSoup(url,'html.parser')
print soup.prettify()

name = soup.find('div',attrs={'class':'super'})

print name['data-title']
