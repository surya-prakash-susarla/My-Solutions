from bs4 import BeautifulSoup

import mechanize
br = mechanize.Browser()

br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]

response=br.open("https://weather.com/en-IN/weather/today/l/17.78,83.38?temp=c&par=google")

print response.code

soup = BeautifulSoup(respnse,'html.parser')
