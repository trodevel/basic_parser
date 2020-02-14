<?php

/*

Parser.

Copyright (C) 2018 Sergey Kolevatov

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

// $Revision: 11041 $ $Date:: 2019-05-03 #$ $Author: serge $

namespace basic_parser;

require_once __DIR__.'/../php_snippets/nonascii_hex_codec.php';     // \utils\nonascii_hex_codec\decode()

function parse_int( & $resp, & $offset )
{
    // 4;

    $res  = intval( $resp[ $offset++ ] );

    return $res;
}

function parse_float( & $resp, & $offset )
{
    // 4.73;

    $res  = floatval( $resp[ $offset++ ] );

    return $res;
}

function parse_string( & $resp, & $offset )
{
    // Hello,=20world;

    $res  = $resp[ $offset++ ];

    return $res;
}

function parse_enc_string( & $resp, & $offset )
{
    // Hello,=20world;

    $res  = \utils\nonascii_hex_codec\decode( $resp[ $offset++ ] );

    return $res;
}

function parse_MapStrToStr( & $resp, & $offset )
{
    // 4;FIRSTNAME;R=C3=BCdiger;NAME;Schultz;TEXT;Hello,=20world;TYPE;Car=20Inspection;

    $res = array();

    $size = $resp[ $offset++ ];

    //echo "size=$size<br>"; // DEBUG

    for( $i = 0; $i < $size; $i++ )
    {
        $key    = \utils\nonascii_hex_codec\decode( $resp[ $offset++ ] );
        $value  = \utils\nonascii_hex_codec\decode( $resp[ $offset++ ] );

        $res[ $key ] = $value;
    }

    return $res;
}

function parse_VectorInt( & $resp, & $offset )
{
    // 3;121212;232323;454545;

    $res = array();

    $size = intval( $resp[ $offset++ ] );

    //echo "size=$size<br>"; // DEBUG

    //var_dump( $resp );

    for( $i = 0; $i < $size; $i++ )
    {
        $value  = intval( $resp[ $offset++ ] );

        array_push( $res, $value );
    }

    return $res;
}

?>
