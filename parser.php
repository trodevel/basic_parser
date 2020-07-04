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

// $Revision: 13364 $ $Date:: 2020-07-04 #$ $Author: serge $

namespace basic_parser;

require_once __DIR__.'/../php_snippets/convert_csv_to_array.php';   // \convert_csv_to_array()
require_once __DIR__.'/../php_snippets/nonascii_hex_codec.php';     // \utils\nonascii_hex_codec\decode()

function parse__bool( & $resp, & $offset )
{
    // 4;

    $v  = intval( $resp[ $offset++ ] );

    $res = FALSE;

    if( $v > 0 )
    {
        $res = TRUE;
    }

    return $res;
}

function parse__int( & $resp, & $offset )
{
    // 4;

    $res  = intval( $resp[ $offset++ ] );

    return $res;
}

function parse__float( & $resp, & $offset )
{
    // 4.73;

    $res  = floatval( $resp[ $offset++ ] );

    return $res;
}

function parse__string( & $resp, & $offset )
{
    // Hello,=20world;

    $res  = $resp[ $offset++ ];

    return $res;
}

function parse__enc_string( & $resp, & $offset )
{
    // Hello,=20world;

    $res  = \utils\nonascii_hex_codec\decode( $resp[ $offset++ ] );

    return $res;
}

function parse__MapStrToStr( & $resp, & $offset )
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

function parse__VectorInt( & $resp, & $offset )
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

class Parser
{
    public static function parse( $arr )
    {
        echo "TRACE: \\basic_parser\\Parser::parse()\n";

        //var_dump( $arr );

        if( sizeof( $arr ) < 1 )
            return NULL;

        $csv_arr = \convert_csv_to_array( $arr );

        //var_dump( $csv_arr );

        return static::parse_csv_array( $csv_arr );
    }

    protected static function parse_csv_array( $csv_arr )
    {
        echo "TRACE: \\basic_parser\\Parser::parse_csv_array()\n";

        return NULL;
    }

    protected static function create_parse_error()
    {
        // ERROR_RESPONSE;1;authentication failed;

        $res = new ErrorResponse( ErrorResponse::PARSE_ERROR, "cannot parse response" );

        return $res;
    }
}

?>
