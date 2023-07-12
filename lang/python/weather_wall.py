from bs4 import BeautifulSoup
import ctypes
import os
import mechanize

br = mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
response=br.open("http://www.accuweather.com/en/in/visakhapatnam/202192/current-weather/202192")

soup = BeautifulSoup(response, 'html.parser')

f = open("Weather_Info.txt",'w')

weather = soup.find('span',attrs={'class':'cond'})

print >>f,weather.text

temp = soup.find('span',attrs={'class':'large-temp'})

print >>f,temp.text.encode('utf-8')


drive = "E:\\"
folder = "c\\images"

if "sunny" in weather.text:
    image="sunny.jpg"
elif "rainy" in weather.text:
    image="rainy.jpg"
elif "cloudy" in weather.text:
    image="cloudy.jpg"
else:
    image="general.jpg"


image_path = os.path.join(drive,folder, image)
SPI_SETDESKWALLPAPER = 20
ctypes.windll.user32.SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, image_path, 3)
