import json
import urllib

url = raw_input('Enter location: ')

try:
	print 'Retrieving ' + url
	data = urllib.urlopen(url).read()
except:
	print 'Invalid Location'
	quit()

print 'Retrieved', len(data), 'characters'
info = json.loads(data)

sum = 0
count = 0

for item in info['comments']:
	sum += item['count']
	count += 1

print 'Count:', count
print 'Sum:', sum