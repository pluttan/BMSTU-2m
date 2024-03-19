import sqlite3 as sl
con = sl.connect('tableDB.db')
with con:
    con.execute("""
        CREATE TABLE Table (
            id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            age INTEGER
        );
    """)
