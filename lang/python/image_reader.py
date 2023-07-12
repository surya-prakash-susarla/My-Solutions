from PIL import Image
from pytesser import *

image = Image.open('wall.jpg')
#image.show()
#print image_to_string(Image.open('wall.jpg'),lang='eng')
text = image_to_string ( image )
text = image_to_string ( image , graceful_erors=True)
print "===============output===============\n"
print text 
