import ctypes
import os
drive = "E:\\"
image = "im.jpg"
image_path = os.path.join(drive, image)
SPI_SETDESKWALLPAPER = 20
ctypes.windll.user32.SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, image_path, 3)
