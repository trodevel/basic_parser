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

// $Revision: 13339 $ $Date:: 2020-07-02 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__PARSER_H
#define LIB_BASIC_PARSER__PARSER_H

#include "generic_request/request.h"    // generic_request::Request

#include <vector>
#include <map>

namespace basic_parser
{

namespace parser
{

void get_value_or_throw( bool * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( uint8_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( uint16_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( uint32_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( uint64_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( int8_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( int16_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( int32_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( int64_t * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( float * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( double * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( std::string * res, const std::string & key, const generic_request::Request & r );

template <class T, class W>
void get_value_or_throw_t( std::vector<T> * res, const std::string & prefix, const generic_request::Request & r, W parser )
{
    std::size_t size;

    get_value_or_throw( & size, prefix + ".SIZE", r );

    if( size == 0 )
        return;

    res->resize( size );

    for( std::size_t i = 0; i < size; ++i )
    {
        auto prefix_idx = prefix + "[" + std::to_string( i ) + "]";

        parser( & res->at( i ), prefix_idx , r );
    }
}

template <class U, class V, class W1, class W2>
void get_value_or_throw_t( std::map<U,V> * res, const std::string & prefix, const generic_request::Request & r, W1 parser1, W2 parser2 )
{
    std::size_t size;

    get_value_or_throw( & size, prefix + ".SIZE", r );

    if( size == 0 )
        return;

    for( std::size_t i = 0; i < size; ++i )
    {
        auto prefix_key = prefix + "[" + std::to_string( i ) + "].key";
        auto prefix_val = prefix + "[" + std::to_string( i ) + "].val";

        U key;
        V value;

        parser1( & key, prefix_key, r );
        parser2( & value, prefix_val, r );

        res->insert( std::make_pair( key, value ) );
    }
}

} // namespace parser

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__PARSER_H
