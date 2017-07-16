import urllib
import xml.etree.ElementTree as ET

url = raw_input('Enter location: ')

print 'Retrieving ' + url

try:
	uh = urllib.urlopen(url)
	data = uh.read()
except:
	print 'Invalid URL'
	quit()

print 'Retrieved ' + str(len(data)) + ' characters'
tree = ET.fromstring(data)

sum = 0
counts = tree.findall('comments/comment')

for item in counts:
	sum += int(item.find('count').text)

print 'Count: ' + str(len(counts))
print 'Sum: ' + str(sum)