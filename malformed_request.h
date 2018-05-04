/*

Malformed Request.

Copyright (C) 2016 Sergey Kolevatov

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

// $Revision: 9042 $ $Date:: 2018-05-04 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__MALFORMED_REQUEST_H
#define LIB_BASIC_PARSER__MALFORMED_REQUEST_H

#include <stdexcept>            // std::runtime_error

namespace basic_parser
{

struct MalformedRequest: public std::runtime_error
{
    MalformedRequest( const std::string & str ):
        std::runtime_error( str )
    {}
};

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__MALFORMED_REQUEST_H
