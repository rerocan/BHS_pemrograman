def bagi(a, b):
    try:
        hasil = a / b
    except ZeroDivisionError:
        return "Error: Tidak bisa membagi dengan nol!"
    except TypeError:
        return "Error: Input harus berupa angka!"
    else:
        return f"Hasilnya adalah {hasil}"
    finally:
        print("Eksekusi blok finally selesai.")

# Contoh penggunaan fungsi dengan exception handling
print(bagi(10, 2))   # Output: Hasilnya adalah 5.0
print(bagi(10, 0))   # Output: Error: Tidak bisa membagi dengan nol!
print(bagi(10, 'a')) # Output: Error: Input harus berupa angka!