# GITHUB COMMAND LINE SAAT INISIALISASI PROJECT

- git init
 > #####  adalah perintah yang digunakan untuk membuat repositori Git baru atau menginisialisasi repositori Git kosong di direktori kerja saat ini.
 
- git add .
 > #####  adalah perintah yang digunakan untuk menambahkan semua perubahan yang belum dilacak ke dalam staged area (atau index) dalam repositori Git.

- git commit -m "pesan"
 > #####  digunakan untuk membuat commit baru dalam repositori Git dengan pesan komit yang disertakan.

- git branch -M main
 > #####  digunakan untuk mengubah nama branch default dari repositori Git menjadi "main" (biasanya, sebelumnya bernama "master").

- git remote add origin (link kode ssh/https di repository github)
 > #####  digunakan untuk menambahkan remote repository dengan nama "origin" ke dalam repositori lokal Git Anda.

- git push -u origin main
 > #####  digunakan untuk mengirimkan perubahan yang ada di branch lokal "main" ke branch "main" di remote repository yang dinamai "origin". Opsi -u atau --set-upstream juga ditambahkan untuk menetapkan branch lokal sebagai branch upstream dari branch remote.


# GITHUB COMMAND LINE SAAT MAINTENANCE/MONITORING PROJECT (TAMBAH KURANG ISI FILE)

>git add .
>git commit -m "pesannya"
>git push