// Fungsi untuk simulasi top up
function topUp() {
    alert('Anda memilih Top Up!');
    let balance = document.getElementById('balance');
    let newBalance = 1500000 + 500000;
    balance.innerHTML = `Rp ${newBalance.toLocaleString()}`;
}

// Fungsi untuk simulasi transfer
function transfer() {
    alert('Anda memilih Transfer!');
    let balance = document.getElementById('balance');
    let newBalance = 1500000 - 300000;
    balance.innerHTML = `Rp ${newBalance.toLocaleString()}`;
}

// Fungsi untuk simulasi bayar
function bayar() {
    alert('Anda memilih Bayar!');
}

// Fungsi untuk melihat riwayat transaksi
function history() {
    alert('Menampilkan Riwayat Transaksi');
}

// Fungsi untuk scan QR
function scanQR() {
    alert('Anda memilih Scan QR!');
}

// Fungsi untuk opsi lain
function moreActions() {
    alert('Fitur lainnya akan segera hadir!');
}
