<?php

namespace App\Http\Controllers;

use App\Models\Inventaris;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;

class InventarisController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $data = DB::connection('mysql')->table('inventariss')->get();
        return response()->json($data, 200);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $this->validate($request, [
            'name_barang' => 'required|string',
            'jumlah_barang' => 'required|string',
            'kondisi_barang' => 'required|string',
            'Tipe_barang' => 'required|string'
        ]);
        $inventaris = [
            'name_barang' => $request->input('name_barang'),
            'jumlah_barang' => $request->input('jumlah_barang'),
            'kondisi_barang' => $request->input('kondisi_barang'),
            'Tipe_barang' => $request->input('Tipe_barang'),
            'created_at' => \Carbon\Carbon::now()->toDateTimeString(),
            'updated_at' => \Carbon\Carbon::now()->toDateTimeString(),
        ];
        $id = DB::connection('mysql')->table('inventariss')->insertGetid($inventaris);
        $data = DB::connection('mysql')->table('inventariss')->where('id', $id)->first();
        $response = [
            'message' => 'true',
            'message' => 'Inventaris Created',
            'date' => $data
        ];
        return response()->json($response, 201);
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Inventaris  $inventaris
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $data = Inventaris::find($id);
        if ($data) {
            return response()->json([
                'success' => 'true',
                'message' => 'Data Retrieve',
                'data' => $data
            ]);
        } else {
            return response()->json([
                'success' => 'false',
                'message' => 'Parameter Not Found',
            ]);
        }
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Inventaris  $inventaris
     * @return \Illuminate\Http\Response
     */
    public function edit(Request $request, $id)
    {
        $this->validate($request, [
            'name_barang' => 'required|string',
            'jumlah_barang' => 'required|string',
            'kondisi_barang' => 'required|string',
            'Tipe_barang' => 'required|string',
        ]);
        $data = Inventaris::find($id);
        if ($data) {
            $data->name_barang = $request->input('name_barang');
            $data->jumlah_barang = $request->input('jumlah_barang');
            $data->kondisi_barang = $request->input('kondisi_barang');
            $data->Tipe_barang = $request->input('Tipe_barang');
            $data->updated_at = \Carbon\Carbon::now()->toDateTimeString();
            $data->save();
            return response()->json([
                'success' => 'true',
                'message' => 'Data Updated',
                'data' => $data
            ]);
        } else {
            return response()->json([
                'success' => 'true',
                'message' => 'Error Updated',
            ]);
        }
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \App\Models\Inventaris  $inventaris
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Inventaris $inventaris)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Inventaris  $inventaris
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $data = Inventaris::find($id);
        if($data){
            $data ->delete();
            return response()->json([
                'success' => 'true',
                'message' => 'Berhasil di Hapus',
            ]);
        }else{
            return response()->json([
                'success' => 'false',
                'message' => 'Parameter Not Found',
            ]);
        }
    }
}
