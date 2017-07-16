import urllib
from bs4 import BeautifulSoup

url = raw_input('Enter - ')
html = urllib.urlopen(url).read()
soup = BeautifulSoup(html, 'lxml')
tags = soup('span')

allspans = 0
sumspans = 0

for tag in tags:
	allspans += 1
	sumspans += int(tag.contents[0])

print 'Count ' + str(allspans)
print 'Sum ' + str(sumspans)