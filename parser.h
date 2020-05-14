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

// $Revision: 13054 $ $Date:: 2020-05-15 #$ $Author: serge $

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

template <class T>
void get_value_or_throw( std::vector<T> * res, const std::string & key, const generic_request::Request & r )
{
    // TODO
}

template <class U, class V>
void get_value_or_throw( std::map<U,V> * res, const std::string & key, const generic_request::Request & r )
{
    // TODO
}

} // namespace parser

} // namespace basic_parser
