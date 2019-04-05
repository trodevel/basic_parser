/*

Getter.

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

// $Revision: 10773 $ $Date:: 2019-04-05 #$ $Author: serge $

#include "get_value.h"         // self

#include "malformed_request.h"      // MalformedRequest

namespace basic_parser
{

void get_value_or_throw( std::string & res, const std::string & key, const generic_request::Request & r )
{
    if( r.get_value( key, res ) == false )
        throw MalformedRequest( key + " is not defined" );
}

void get_value_or_throw_uint32( uint32_t & res, const std::string & key, const generic_request::Request & r )
{
    if( r.get_value_converted( key, res ) == false )
        throw MalformedRequest( key + " is not defined or not numerical" );
}

void get_value_or_throw_float( float & res, const std::string & key, const generic_request::Request & r )
{
    if( r.get_value_converted( key, res ) == false )
        throw MalformedRequest( key + " is not defined or not numerical" );
}

void get_value_or_throw_double( double & res, const std::string & key, const generic_request::Request & r )
{
    if( r.get_value_converted( key, res ) == false )
        throw MalformedRequest( key + " is not defined or not numerical" );
}

} // namespace basic_parser
