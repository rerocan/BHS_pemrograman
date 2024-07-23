<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class InventarisSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        $timestamp = \Carbon\Carbon::now()->toDateTimeString();
            DB::table('inventariss')->insert([
                'name_barang' => 'name_barang',
                'jumlah_barang' => 'jumlah_barang',
                'kondisi_barang' => 'kondisi_barang',
                'Tipe_barang' => 'Tipe_barang',
                'created_at' => $timestamp,
                'updated_at' => $timestamp,
            ]);
    }
}
