import tkinter as tk
from tkinter import messagebox

def on_button_click():
    messagebox.showinfo("Info", "Tombol diklik!")

# Membuat instance dari Tkinter
root = tk.Tk()

# Menentukan judul jendela
root.title("Contoh GUI dengan Tkinter")

# Menentukan ukuran jendela
root.geometry("300x200")

# Membuat label
label = tk.Label(root, text="Halo, ini adalah contoh GUI!")
label.pack(pady=10)

# Membuat tombol
button = tk.Button(root, text="Klik Saya", command=on_button_click)
button.pack(pady=10)

# Menjalankan aplikasi
root.mainloop()
