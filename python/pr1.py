import mechanize
br = mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
br.open('https://doeresults.gitam.edu/onlineresults/pages/Newgrdcrdinput1.aspx')
for b in br.forms():
    print b
br.select_form("form1")
br.form['cbosem']=["2"]
num=1210315449
br.form['txtreg']=str(num)
br.submit(nr=0)
