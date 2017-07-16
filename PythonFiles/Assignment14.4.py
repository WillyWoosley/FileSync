import json
import sqlite3

conn = sqlite3.connect('coursedb.sqlite')
cur = conn.cursor()

cur.executescript('''
	DROP TABLE IF EXISTS User;
	DROP TABLE IF EXISTS Course;
	DROP TABLE IF EXISTS Member;

	CREATE TABLE User (
		id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
		name TEXT UNIQUE
	);

	CREATE TABLE Course (
		id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
		title TEXT UNIQUE
	);

	CREATE TABLE Member (
		role INTEGER,
		user_id INTEGER,
		course_id INTEGER,
		PRIMARY KEY(user_id, course_id)
	);
	''')

rawdata = open('roster_data.json').read()
json = json.loads(rawdata)

for entry in json:
	name = entry[0]
	course = entry[1]
	role = entry[2]

	cur.execute('INSERT OR IGNORE INTO User (name) VALUES (?)', (name, ))
	cur.execute('SELECT id FROM User WHERE name = ?', (name, ))
	user_id = cur.fetchone()[0]
	cur.execute('INSERT OR IGNORE INTO Course (title) VALUES (?)', (course, ))
	cur.execute('SELECT id FROM Course WHERE title = ?', (course, ))
	course_id = cur.fetchone()[0]
	cur.execute('''INSERT OR REPLACE INTO Member (role, user_id, course_id)
		VALUES (?, ?, ?)''', (role, user_id, course_id))


conn.commit()
cur.close()