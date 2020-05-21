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

// $Revision: 13103 $ $Date:: 2020-05-21 #$ $Author: serge $

namespace basic_parser;

function to_generic_request__bool( $name, $v )
{
    $v_c = ( $v ) ? "1" : "0";

    $res = "$name=${v_c}";

    return $res;
}

function to_generic_request__int( $name, $v )
{
    $v_c = $v + 0;

    $res = "$name=${v_c}";

    return $res;
}

function to_generic_request__float( $name, $v )
{
    $v_c = $v + 0.0;

    $res = "$name=${v_c}";

    return $res;
}

function to_generic_request__string( $name, $v )
{
    $res = "$name=$v";

    return $res;
}

function to_generic_request__vector( $name, $vect, $func )
{
    $res = "";

    $size = sizeof( $vect );

    $res .= to_generic_request__int( $name . ".SIZE", $size );

    $i = 0;

    foreach( $vect as $v )
    {
        $val = $func( $name . "[" . $i . "]", $v );

        $res .= "&" . $val;

        $i++;
    }

    return $res;
}

function to_generic_request__map( $name, $map, $func1, $func2 )
{
    $res = "";

    $size = sizeof( $map );

    $res .= to_generic_request__int( $name . ".SIZE", $size );

    $i = 0;

    foreach( $vect as $v_k => $v_v )
    {
        $v_1 = $func1( $name . "[" . $i . "].key", $v_k );

        $v_2 = $func2( $name . "[" . $i . "].val", $v_v );

        $res .= "&" . $v_1 . "&" . $v_2;

        $i++;
    }

    return $res;
}

?>
