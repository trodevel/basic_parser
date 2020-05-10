/*

CsvHelper.

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

// $Revision: 12985 $ $Date:: 2020-05-07 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__CSV_HELPER_H
#define LIB_BASIC_PARSER__CSV_HELPER_H

// system includes
#include <sstream>
#include <vector>
#include <map>

namespace basic_parser
{

namespace csv_helper
{

std::ostream & write( std::ostream & os, const bool r );
std::ostream & write( std::ostream & os, const int8_t r );
std::ostream & write( std::ostream & os, const uint8_t r );
std::ostream & write( std::ostream & os, const int16_t r );
std::ostream & write( std::ostream & os, const uint16_t r );
std::ostream & write( std::ostream & os, const int32_t r );
std::ostream & write( std::ostream & os, const uint32_t r );
std::ostream & write( std::ostream & os, const int64_t r );
std::ostream & write( std::ostream & os, const uint64_t r );
std::ostream & write( std::ostream & os, const float r );
std::ostream & write( std::ostream & os, const double r );
std::ostream & write( std::ostream & os, const std::string & r );

template <class T, class W >
std::ostream & write_t( std::ostream & os, const std::vector<T> & r, W writer )
{
    write( os, r.size() );

    for( auto & e : r )
    {
        writer( os, e );
    }

    return os;
}

template <class U, class V, class W1, class W2>
std::ostream & write_t( std::ostream & os, const std::map<U,V> & r, W1 writer1, W2 writer2 )
{
    write( os, r.size() );

    for( auto & e : r )
    {
        writer1( os, e.first );
        writer2( os, e.second );
    }

    return os;
}

} // namespace csv_helper

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__CSV_HELPER_H
