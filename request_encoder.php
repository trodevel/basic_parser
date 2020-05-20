<?php

/*

Request Encoder.

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

// $Revision: 13102 $ $Date:: 2020-05-20 #$ $Author: serge $

namespace basic_parser;

function to_generic_request__bool( $key, $v )
{
    $v_c = ( $v ) ? "1" : "0";

    $res = "$key=${v_c}";

    return $res;
}

function to_generic_request__int( $key, $v )
{
    $v_c = $v + 0;

    $res = "$key=${v_c}";

    return $res;
}

function to_generic_request__float( $key, $v )
{
    $v_c = $v + 0.0;

    $res = "$key=${v_c}";

    return $res;
}

function to_generic_request__string( $key, $v )
{
    $res = "$key=$v";

    return $res;
}

function to_generic_request__vector( $key, $vect, $func )
{
    $res = "";

    $size = sizeof( $vect );

    $res .= to_generic_request__int( $key . ".SIZE", $size );

    $i = 0;

    foreach( $vect as $v )
    {
        $val = $func( $key . "[" . $i . "]", $v );

        $res .= "&" . $val;

        $i++;
    }

    return $res;
}

function to_generic_request__map( $key, $map, $func1, $func2 )
{
    $res = "";

    $size = sizeof( $map );

    $res .= to_generic_request__int( $key . ".SIZE", $size );

    $i = 0;

    foreach( $vect as $v_k => $v_v )
    {
        $v_1 = $func1( $key . "[" . $i . "].key", $v_k );

        $v_2 = $func2( $key . "[" . $i . "].val", $v_v );

        $res .= "&" . $v_1 . "&" . $v_2;

        $i++;
    }

    return $res;
}

?>
