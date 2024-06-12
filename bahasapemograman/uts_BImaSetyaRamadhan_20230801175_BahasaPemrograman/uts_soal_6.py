def menu():
    print("Menu Utama")
    print("1. Penjumlahan")
    print("2. Pengurangan")
    print("3. Perkalian")
    print("4. Pembagian")

def operasi_matematika(operasi):
    a = int(input("Masukkan angka pertama: "))
    b = int(input("Masukkan angka kedua: "))

    if operasi == "penjumlahan":
        hasil = a + b
        print(f"Hasil penjumlahan dari {a} + {b} adalah {hasil}")
    elif operasi == "pengurangan":
        hasil = a - b
        print(f"Hasil pengurangan dari {a} - {b} adalah {hasil}")
    elif operasi == "perkalian":
        hasil = a * b
        print(f"Hasil perkalian dari {a} * {b} adalah {hasil}")
    elif operasi == "pembagian":
        if b != 0:
            hasil = a // b  # Pembagian bulat
            print(f"Hasil pembagian dari {a} / {b} adalah {hasil}")
        else:
            print("Error! Pembagian dengan nol tidak diperbolehkan.")
    else:
        print("Operasi tidak valid")

def main():
    menu()
    pilihan = int(input("Masukkan pilihan anda: "))
    operasi_dict = {
        1: "penjumlahan",
        2: "pengurangan",
        3: "perkalian",
        4: "pembagian"
    }

    if pilihan in operasi_dict:
        operasi_matematika(operasi_dict[pilihan])
    else:
        print("Pilihan tidak valid")

if __name__ == "__main__":
    main()