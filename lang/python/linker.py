import re
from mechanize import Browser
br = Browser()

br.set_handle_robots(False)

br.addheaders = [('User-agent','Firefox')]

br.open("http://google.com")
br.select_form('f')
br.form['q']='foo'
br.submit()
resp=None

for link in br.links():
    siteMatch = re.compile('www.google.com').search(link.url)
    if siteMatch:
        resp = br.follow_link(link)
        break
if resp != None:
    content = resp.get_data()
    print content
