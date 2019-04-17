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

// $Revision: 10846 $ $Date:: 2019-04-18 #$ $Author: serge $

#include "generic_request/request.h"    // generic_request::Request

namespace basic_parser
{

void get_value_or_throw( std::string & res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw_uint32( uint32_t & res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw_float( float & res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw_double( double & res, const std::string & key, const generic_request::Request & r );

} // namespace basic_parser
