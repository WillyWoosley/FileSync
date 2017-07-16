import sqlite3
import xml.etree.ElementTree as ET

conn = sqlite3.connect('music.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Artist')
cur.execute('DROP TABLE IF EXISTS Genre')
cur.execute('DROP TABLE IF EXISTS Album')
cur.execute('DROP TABLE IF EXISTS Track')

cur.execute('''CREATE TABLE Artist (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE)''')

cur.execute('''CREATE TABLE Genre (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE)''')

cur.execute('''CREATE TABLE Album (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	artist_id INTEGER,
	title TEXT UNIQUE)''')

cur.execute('''CREATE TABLE Track (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	title TEXT UNIQUE,
	album_id INTEGER,
	genre_id INTEGER,
	len INTEGER,
	rating INTEGER,
	count INTEGER)''')

def lookup(passeddict, key):
	found = False

	for child in passeddict:
		if found : return child.text
		if child.tag == 'key' and child.text == key: found = True

	return None

parsedfile = ET.parse('Library.xml')
allXML = parsedfile.findall('dict/dict/dict')

for entry in allXML:
	if (lookup(entry, 'Track ID') is None) : continue

	trackname = lookup(entry, 'Name')
	genre = lookup(entry, 'Genre')
	albumname = lookup(entry, 'Album')
	length = lookup(entry, 'Total Time')
	rating = lookup(entry, 'Rating')
	count = lookup(entry, 'Play Count')
	artist = lookup(entry, 'Artist')

	
	if artist is None or albumname is None or trackname is None or genre is None:
		continue

	cur.execute('INSERT OR IGNORE INTO Artist (name) VALUES (?)', (artist, ))
	cur.execute('SELECT id FROM Artist WHERE name = ?', (artist, ))
	artist_id = cur.fetchone()[0]
	cur.execute('INSERT OR IGNORE INTO Genre (name) VALUES (?)', (genre, ))
	cur.execute('SELECT id FROM Genre WHERE name = ?', (genre, ))
	genre_id = cur.fetchone()[0]
	cur.execute('INSERT OR IGNORE INTO Album (artist_id, title) VALUES (?, ?)', (artist_id, albumname))
	cur.execute('SELECT id from Album WHERE title = ?', (albumname, ))
	album_id = cur.fetchone()[0]
	cur.execute('''INSERT OR REPLACE INTO Track (title, album_id, genre_id, len, rating, count)
		VALUES (?, ?, ?, ?, ?, ?)''', (trackname, album_id, genre_id, length, rating, count))

conn.commit()
conn.close()