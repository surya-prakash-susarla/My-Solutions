import mechanize
from bs4 import BeautifulSoup

br = mechanize.Browser()

br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
br.open("http://xlearn.gitam.edu/moodle/login/index.php")
