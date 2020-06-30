<?php

/*

HTML helper.

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

// $Revision: 13324 $ $Date:: 2020-06-30 #$ $Author: serge $

namespace basic_parser;

require_once __DIR__.'/../php_snippets/html_elems.php';     // \get_html_table_header_elems()
require_once 'str_helper.php';                              // to_string_...()

function to_html__bool( $v )
{
    $res = to_string__bool( $v );

    return $res;
}

function to_html__int( $v )
{
    $res = to_string__int( $v );

    return $res;
}

function to_html__float( $v )
{
    $res = to_string__float( $v );

    return $res;
}

function to_html__string( $v )
{
    $res = htmlentities( $v );

    return $res;
}

function to_html__vector( $vect, $func )
{
    $res = "";

    foreach( $vect as $v )
    {
        $val = $func( $v );

        $res .=  $val;
    }

    return $res;
}

function to_html__map( $map, $func1, $func2 )
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

function to_html_table( $header, $data )
{
    $res = get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_tr( get_html_table_header_elems( $header ) ) .
            get_html_table_tr( get_html_table_data_elems( $data ) ) );

    return $res;
}

?>
