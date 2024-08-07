<?php

/** @var \Laravel\Lumen\Routing\Router $router */

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It is a breeze. Simply tell Lumen the URIs it should respond to
| and give it the Closure to call when that URI is requested.
|
*/

$router->get('/', function () use ($router) {
    return $router->app->version();
});

$router->group(['prefix' => 'api/v1/user', 'middleware'=> 'auth'], function () use ($router) {
    $router->get('/', ['uses' => 'UserController@index']);
});

$router->group(['prefix' => 'api/v1/inventaris', 'middleware' => 'auth'], function() use ($router){
    $router->get('/', ['uses' => 'InventarisController@index']);
	$router->post('/', ['uses' => 'InventarisController@store']);
	$router->get('/{id}', ['uses' => 'InventarisController@show']);
	$router->delete('/{id}', ['uses' => 'InventarisController@destroy']);
	$router->put('/{id}', ['uses' => 'InventarisController@edit']);
});