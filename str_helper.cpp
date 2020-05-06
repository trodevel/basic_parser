/*

StrHelper.

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

// $Revision: 12972 $ $Date:: 2020-05-07 #$ $Author: serge $

// includes
#include "str_helper.h"

namespace basic_parser
{

namespace str_helper
{

std::ostream & write( std::ostream & os, const bool r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const int8_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const uint8_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const int16_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const uint16_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const int32_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const uint32_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const int64_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const uint64_t r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const float r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const double r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const std::string & r )
{
    os << r; return os;
}

std::ostream & write( std::ostream & os, const char * r )
{
    os << r; return os;
}

} // namespace str_helper

} // namespace basic_parser

