/*

Validator.

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

// $Revision: 13027 $ $Date:: 2020-05-13 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__VALIDATOR_H
#define LIB_BASIC_PARSER__VALIDATOR_H

// system includes
#include <string>
#include <vector>
#include <map>

#include "malformed_request.h"  // MalformedRequest

namespace basic_parser
{

namespace validator
{

bool validate( const std::string & prefix, const bool r );
bool validate( const std::string & prefix, const int8_t r );
bool validate( const std::string & prefix, const uint8_t r );
bool validate( const std::string & prefix, const int16_t r );
bool validate( const std::string & prefix, const uint16_t r );
bool validate( const std::string & prefix, const int32_t r );
bool validate( const std::string & prefix, const uint32_t r );
bool validate( const std::string & prefix, const int64_t r );
bool validate( const std::string & prefix, const uint64_t r );
bool validate( const std::string & prefix, const float r );
bool validate( const std::string & prefix, const double r );
bool validate( const std::string & prefix, const std::string & r );

template <class T>
bool validate( const std::string & prefix, const T r, bool has_from, bool is_inclusive_from, T from, bool has_to, bool is_inclusive_to, T to )
{
    if( has_from )
    {
        if( is_inclusive_from )
        {
            if( r < from )
                throw MalformedRequest( prefix + " < " + std::to_string( from ) );
        }
        else
        {
            if( r <= from )
                throw MalformedRequest( prefix + " <= " + std::to_string( from ) );
        }
    }

    if( has_to )
    {
        if( is_inclusive_to )
        {
            if( r > to )
                throw MalformedRequest( prefix + " > " + std::to_string( to ) );
        }
        else
        {
            if( r >= to )
                throw MalformedRequest( prefix + " >= " + std::to_string( to ) );
        }
    }

    return true;
}

bool validate( const std::string & prefix, const std::string & r, bool has_from, bool is_inclusive_from, std::size_t from, bool has_to, bool is_inclusive_to, std::size_t to );

template <class T, class W>
bool validate_t( const std::string & prefix, const std::vector<T> & r, W validator )
{
    std::size_t i = 0;

    for( auto & e : r )
    {
        auto prefix_idx = prefix + "[" + std::to_string( i ) + "]";

        validator( prefix_idx , e );

        i++;
    }

    return true;
}

template <class U, class V, class W1, class W2>
bool validate_t( const std::string & prefix, const std::map<U,V> & r, W1 validator1, W2 validator2 )
{
    std::size_t i = 0;

    for( auto & e : r )
    {
        auto prefix_key = prefix + "[" + std::to_string( i ) + "].key";
        auto prefix_val = prefix + "[" + std::to_string( i ) + "].val";

        validator1( prefix_key, e.first );
        validator2( prefix_val, e.second );

        i++;
    }

    return true;
}

} // namespace validator

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__VALIDATOR_H
