def penjumlahan(a, b):
    return int(a + b)

def pengurangan(a, b):
    return int(a - b)

def perkalian(a, b):
    return int(a * b)

def pembagian(a, b):
    if b != 0:
        return int(a / b)
    else:
        return "Error! Pembagian dengan nol tidak diperbolehkan."

def main():
    print("Program Operasi Matematika Sederhana")
    print("===================================")
    
    # Meminta input dari pengguna
    a = float(input("Masukkan angka pertama: "))
    b = float(input("Masukkan angka kedua: "))
    
    # Melakukan operasi matematika
    hasil_penjumlahan = penjumlahan(a, b)
    hasil_pengurangan = pengurangan(a, b)
    hasil_perkalian = perkalian(a, b)
    hasil_pembagian = pembagian(a, b)
    
    # Menampilkan hasil
    print("\nHasil Operasi:")
    print(f"penjumlahan= {hasil_penjumlahan}")
    print(f"pengurangan = {hasil_pengurangan}")
    print(f"perkalian = {hasil_perkalian}")
    print(f"pembagian = {hasil_pembagian}")

if __name__ == "__main__":
    main()
