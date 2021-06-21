import mechanize
from bs4 import BeautifulSoup

br = mechanize.Browser()

response = br.open("https://en.wikipedia.org/wiki/Simha_(film)")

print response.text
