import sqlite3

# Membuat atau menghubungkan ke database
conn = sqlite3.connect('contoh.db')
cursor = conn.cursor()

# Membuat tabel
cursor.execute('''
CREATE TABLE IF NOT EXISTS mahasiswa (
    id INTEGER PRIMARY KEY,
    nama TEXT NOT NULL,
    umur INTEGER NOT NULL
)
''')

# Menyisipkan data
cursor.execute('''
INSERT INTO mahasiswa (nama, umur)
VALUES ('Andi', 20)
''')
conn.commit()

# Mengambil data
cursor.execute('SELECT * FROM mahasiswa')
rows = cursor.fetchall()
for row in rows:
    print(row)

# Menutup koneksi
conn.close()
