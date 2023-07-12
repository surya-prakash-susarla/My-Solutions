import urllib2

url = "https://wallpapers.wallhaven.cc/wallpapers/full/wallhaven-127104.jpg"

file_name = url.split('/')[-1]
u = urllib2.urlopen(url)
meta = u.info()
file_size = int(meta.getheaders("Content-Length")[0])
meta = u.info()
print "Downloading : %s Bytes: %s"%(file_name, file_size)
f = open(file_name,'wb')
file_size_dl=0
block_sz=8192
while True:
    buffer = u.read(block_sz)
    if not buffer:
        break
    file_size_dl +=len(buffer)
    f.write(buffer)
f.close()