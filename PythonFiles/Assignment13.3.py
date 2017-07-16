import json
import urllib

serviceurl = 'http://python-data.dr-chuck.net/geojson?'

while True:
	address = raw_input('Enter location: ')
	if len(address) < 1: break

	url = serviceurl + urllib.urlencode({'sensor':'false', 'address':address})
	print 'Retrieving ', url
	data = urllib.urlopen(url).read()
	print 'Retrieved', len(data), 'characters'

	try:
		js = json.loads(data)
	except:
		js = None

	if 'status' not in js or js['status']!='OK':
		print '===Failure to Retrive==='
		print data
		continue

	print 'Place id', json.dumps(js['results'][0]['place_id'])