<?php

/*

Dummy Creator.

Copyright (C) 2020 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 13339 $ $Date:: 2020-07-02 #$ $Author: serge $

namespace basic_parser;

function create_dummy__bool()
{
    $res = rand() % 2;

    return $res;
}

function create_dummy__int8()
{
    $res = rand() % 256;

    return $res;
}

function create_dummy__int16()
{
    $res = rand() % 32768;

    return $res;
}

function create_dummy__int32()
{
    $res = rand() % 65536;

    return $res;
}

function create_dummy__int64()
{
    $res = rand();

    return $res;
}

function create_dummy__float()
{
    $res = mt_rand() / mt_getrandmax();

    return $res;
}

function create_dummy__string()
{
    $length = rand( 1, 20 );
    $res = substr(str_shuffle(str_repeat($x='0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_ !@#$%^&*()_-+=){}"|,./<>?:;', ceil($length/strlen($x)) )),1,$length);

    return $res;
}

function create_dummy__vector( $func )
{
    $res = array();

    $size = rand( 1, 20 );

    for( $i = 0; $i < $size; $i++ )
    {
        $v = $func();

        array_push( $res, $v );
    }

    return $res;
}

function create_dummy__map( $func1, $func2 )
{
    $res = array();

    $size = rand( 1, 20 );

    for( $i = 0; $i < $size; $i++ )
    {
        $k = $func1();
        $v = $func2();

        $res[$k] = $v;
    }

    return $res;
}

?>
