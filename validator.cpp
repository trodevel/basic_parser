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

// $Revision: 13026 $ $Date:: 2020-05-13 #$ $Author: serge $

// includes
#include "validator.h"

namespace basic_parser
{

namespace validator
{

bool validate( const std::string & prefix, const bool r )
{
    return true;
}

bool validate( const std::string & prefix, const int8_t r )
{
    return true;
}

bool validate( const std::string & prefix, const uint8_t r )
{
    return true;
}

bool validate( const std::string & prefix, const int16_t r )
{
    return true;
}

bool validate( const std::string & prefix, const uint16_t r )
{
    return true;
}

bool validate( const std::string & prefix, const int32_t r )
{
    return true;
}

bool validate( const std::string & prefix, const uint32_t r )
{
    return true;
}

bool validate( const std::string & prefix, const int64_t r )
{
    return true;
}

bool validate( const std::string & prefix, const uint64_t r )
{
    return true;
}

bool validate( const std::string & prefix, const float r )
{
    return true;
}

bool validate( const std::string & prefix, const double r )
{
    return true;
}

bool validate( const std::string & prefix, const std::string & r )
{
    return true;
}

bool validate( const std::string & prefix, const std::string & r, bool has_from, bool is_inclusive_from, std::size_t from, bool has_to, bool is_inclusive_to, std::size_t to )
{
    return validate( prefix + ".size()", r.size(), has_from, is_inclusive_from, from, has_to, is_inclusive_to, to );
}

} // namespace validator

} // namespace basic_parser

