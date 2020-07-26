<?php

/*

Str helper.

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

function to_string__bool( $v )
{
    $res = ( $v ) ? "TRUE" : "FALSE";

    return $res;
}

function to_string__int( $v )
{
    $res = $v + 0;

    return $res;
}

function to_string__float( $v )
{
    $res = $v + 0.0;

    return $res;
}

function to_string__string( $v )
{
    $res = $v;

    return $res;
}

function to_string__vector( $vect, $func )
{
    $res = "";

    foreach( $vect as $v )
    {
        $val = $func( $v );

        $res .=  $val;
    }

    return $res;
}

function to_string__map( $map, $func1, $func2 )
{
    $res = "";

    foreach( $map as $v_k => $v_v )
    {
        $key = $func1( $v_k );

        $val = $func2( $v_v );

        $res .=  "(" . $key . " -> " . $val . ")";
    }

    return $res;
}

?>
