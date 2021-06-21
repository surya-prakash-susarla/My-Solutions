from bs4 import BeautifulSoup
import mechanize

br = mechanize.Browser()
br. set_handle_robots(False)
br.set_user_agent(['User-agent','Firefox'])

resp = br.open("https://www.flipkart.com/u-s-polo-assn-men-s-t-shirt/p/itmet7pks7eyktqh?pid=TSHE7C4GRXTKE4VK&srno=b_1_1&otracker=hp_omu_Deals%20of%20the%20day%20_2_40-80%25%20Off_AR6U9H5HYY_0&lid=LSTTSHE7C4GRXTKE4VK39OPCJ")

bs = BeautifulSoup(resp , 'html.parser')

val  = bs.find('div', attrs={'class':'_1vC4OE _37U4_g'})

print val.strip().text()
