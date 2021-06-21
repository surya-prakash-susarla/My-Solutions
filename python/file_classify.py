import os
import glob
import shutil


# to move txt files

source = "Z:/codes/*.txt"
destination = "Z:/codes/txt"

for i in glob.glob(source):
    shutil.move(i,destination)

# to move java and javac files

source = "Z:/codes/*.java"
destination = "Z:/codes/java codes"

for i in glob.glob(source):
    shutil.move(i,destination)
source = "Z:/codes/*.javac"

for i in glob.glob(source):
    shutil.move(i,destination)

# to move cpp files

default_directory = "Z:/codes"

source = default_directory+"/*.cpp"
destination = default_directory+"/cpp"

for i in glob.glob(source):
    shutil.move(i,destination)

# to move html files

source = default_directory+"/*.html"
destination = default_directory+"/html"
for i in glob.glob(source):
    shutil.move(i,destination)
source = default_directory+"/*.htm"
for i in glob.glob(source):
    shutil.move(i,destination)
