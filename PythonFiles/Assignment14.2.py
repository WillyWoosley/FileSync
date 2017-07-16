import sqlite3
import re

conn = sqlite3.connect('emaildb.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Counts')
cur.execute('CREATE TABLE Counts (org TEXT, count INTEGER)')

fname = ('mbox.txt')
fhandle = open(fname)

for line in fhandle:
	if not line.startswith('From: '): continue
	line.strip()
	fromline = re.findall('.*@([\S]*)', line)
	orginization = fromline[0]

	cur.execute('SELECT count FROM Counts WHERE org = ?', (orginization,))
	row = cur.fetchone()

	if row is None:
		cur.execute('INSERT INTO Counts (org, count) VALUES (?, 1)', (orginization, ))
	else:
		cur.execute('UPDATE Counts SET count = count + 1 WHERE org = ?', (orginization, ))

conn.commit()

sqlstr = 'SELECT org, count FROM Counts ORDER BY count'

for row in cur.execute(sqlstr):
	print str(row[0]), row[1]

cur.close()