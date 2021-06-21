import mechanize
br = mechanize.Browser()
br.set_handle_robots(False)
br.addheaders=[('User-agent','Firefox')]
br.open('https://doeresults.gitam.edu/onlineresults/pages/Newgrdcrdinput1.aspx')
for b in br.forms():
    print b
#print("\n\n\n\n\n\n")
br.select_form("form1")
#for control in br.form.controls:
#    print control
    #print "type=%s, name=%s value=%s" % (control.type, control.name, br[control.name])
br.form['cbosem']=["2"]
br.submit(nr=0)

print br
