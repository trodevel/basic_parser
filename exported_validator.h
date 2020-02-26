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

// $Revision: 12800 $ $Date:: 2020-02-26 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__EXPORTED_VALIDATOR_H
#define LIB_BASIC_PARSER__EXPORTED_VALIDATOR_H

// system includes
#include <string>
#include <vector>
#include <map>

namespace basic_parser
{

namespace validator
{

bool validate( const bool r );
bool validate( const int8_t r );
bool validate( const uint8_t r );
bool validate( const int16_t r );
bool validate( const uint16_t r );
bool validate( const int32_t r );
bool validate( const uint32_t r );
bool validate( const int64_t r );
bool validate( const uint64_t r );
bool validate( const float r );
bool validate( const double r );
bool validate( const std::string & r );

template <class T>
bool validate( const std::vector<T> & r )
{
    for( auto & e : r )
    {
        validate( e );
    }

    return true;
}

template <class U, class V>
bool validate( const std::map<U,V> & r )
{
    for( auto & e : r )
    {
        validate( e.first );
        validate( e.second );
    }

    return true;
}

} // namespace validator

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__EXPORTED_VALIDATOR_H
