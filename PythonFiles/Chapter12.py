#EXERCISE 12.1
#import socket
#import re
#
#mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#
#inpurl = raw_input('Input a URL: ')
#host = re.findall('http://([\S]+)/', inpurl)
#send = 'GET ' + inpurl + ' HTTP:/1.0\n\n'
#
#try:
#	mysock.connect((host[0], 80))
#	mysock.send(send)
#except:
#	print 'Invalid input URL'
#	quit()
#
#while True:
#    data = mysock.recv(512)
#    if ( len(data) < 1 ) :
#        break
#    print data;
#
#mysock.close()

#EXERCISE 12.2
#import socket
#import re
#
#mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#inpurl = raw_input('Please input URL: ')
#host = re.findall('http://([\S]+)/', inpurl)
#send = 'GET ' + inpurl + ' HTTP/1.0\n\n'
#
#try:
#	mysock.connect((host[0], 80))
#	mysock.send(send)
#except:
#	print 'Invalid URL'
#	quit()
#
#datalimit = 200
#datareceived = ''
#charnum = 0
#
#while True:
#    data = mysock.recv(50)
#    if len(data) < 1: break
#    if len(datareceived) < datalimit: datareceived += data
#    charnum += len(data)
#
#mysock.close()
#print datareceived
#print '\nTotal characters in file: ' + str(charnum) + ', ' + 'At most ' + str(datalimit) + ' printed'

#EXERCISE 12.3
#import urllib
#import re
#
#inpurl = raw_input('Please inut URL: ')
#filename = re.findall('http://.+/([\S]+)', inpurl)
#
#try:
#	file = urllib.urlopen(inpurl)
#	fhand = open(filename[0])
#except:
#	print 'Invalid URL'
#	quit()
#
#totalchar = 0
#maxchar = 50
#printdata = ''
#
#while True:
#    data = file.read(50)
#    if len(data) < 1: break
#    if len(printdata) < maxchar: printdata += data
#    totalchar += len(data)
#
#fhand.close()
#print printdata
#print str(totalchar) + ' characters in file, at most ' + str(maxchar) + ' printed'

#EXERCISE 12.4
#import urllib
#from bs4 import BeautifulSoup
#
#url = 'http://www.spreadsheetconverter.com/support/tutorials/how-to-test-your-web-page-in-iphone-ipad-or-android/'
#html = urllib.urlopen(url).read()
#soup = BeautifulSoup(html, 'lxml')
#tags = soup('p')
#print len(tags)

#EXERCISE 12.5
