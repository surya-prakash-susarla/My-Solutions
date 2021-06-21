#setup.py

from distutils.core import setup
import py2exe
from glob import glob
data_files = [("Microsoft.VC90.CRT", glob(r'C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\*.*'))]
setup(
    data_files=data_files,
    console=['wiki.py'],
    options={
        'py2exe' : {
                'packages' : ['pocketsphinx','win32com','speech_recognition','os','wikipedia'],
                "dll_excludes": ["MSVFW32.dll",
                 "AVIFIL32.dll",
                 "AVICAP32.dll",
                 "ADVAPI32.dll",
                 "CRYPT32.dll",
                 "WLDAP32.dll"]
            }
        }
      )