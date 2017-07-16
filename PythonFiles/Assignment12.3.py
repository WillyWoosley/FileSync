import re
import urllib
from bs4 import BeautifulSoup

link = [raw_input('Enter URL: ')]
linkiter = int(raw_input('Enter count: '))
linknum = int(raw_input('Enter position: '))


def getlink(passedurl):
	html = urllib.urlopen(passedurl).read()
	soup = BeautifulSoup(html, 'lxml')
	tags = soup('a')
	return re.findall('href="(.+)"', str(tags[linknum-1]))

while linkiter > 0:
	link = getlink(link[0])
	print 'Retrieving: ' + link[0]
	linkiter -= 1