
# -*- coding: utf-8 -*-

import urllib
import urllib.request as request
from bs4 import BeautifulSoup
import bs4
import sys
import io
import os
import time
import re

new_path=[]
old_path=(os.listdir('C:/Users/xyy/PAT-Advanced'))
for i in old_path:
	a=re.sub('\(','_',i)
	b=re.sub('\)','',a)
	c=re.sub(' ','',b)
	new_path.append(c)
for i,value in enumerate(new_path):
	os.rename(old_path[i],new_path[i])
	print(i,value)
	
'''
sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf-8')


cnt = []
path = 'C:/Users/xyy/Desktop/777.html'
htmlfile = open(path, 'r', encoding='utf-8')
req = htmlfile.read()
soup = bs4.BeautifulSoup(req, "lxml")
tbody = soup.find('tbody').children
for tr in tbody:
	if isinstance(tr, bs4.element.Tag):
		tds = tr('td')
		astr = tds[2].find('a')
		if(astr.string)
		cnt.append([tds[1].string, astr.string, tds[3].string])
path = os.getcwd()

for i in cnt:
	name=(path+'\\'+'X_'+i[0]+'_'+i[1][:-5]+'('+i[2]+')'+'.cpp')
	if not os.path.exists(name):
		if (1000<int(i[0])<=1067):
			#fo = open(name,'w')
			#fo.close()
		#print(os.path.exists(name))
			print(name)

'''


