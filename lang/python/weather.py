from bs4 import BeautifulSoup

import mechanize

br = mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
response=br.open("http://www.accuweather.com/en/in/visakhapatnam/202192/current-weather/202192")

#print response.code

soup = BeautifulSoup(response, 'html.parser')

weather = soup.find('span',attrs={'class':'cond'})

print weather.text

temp = soup.find('span',attrs={'class':'large-temp'})

print temp.text
