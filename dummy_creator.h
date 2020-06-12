/*

Dummy Creator.

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

// $Revision: 13252 $ $Date:: 2020-06-12 #$ $Author: serge $

#ifndef LIB_BASIC_PARSER__DUMMY_CREATOR_H
#define LIB_BASIC_PARSER__DUMMY_CREATOR_H

// system includes
#include <cstdint>
#include <string>
#include <vector>
#include <map>

namespace basic_parser
{

namespace dummy
{

bool create__bool();
std::uint8_t create__uint8();
std::uint16_t create__uint16();
std::uint32_t create__uint32();
std::uint64_t create__uint64();
std::int8_t create__int8();
std::int16_t create__int16();
std::int32_t create__int32();
std::int64_t create__int64();
float create__float();
double create__double();
std::string create__string();

template <class T, class W>
std::vector<T> create__vector( W creator )
{
    std::vector<T> res;

    std::size_t size = create__uint8();

    for( std::size_t i = 0; i < size; ++i )
    {
        T v = creator();

        res.push_back( v );
    }

    return res;
}

template <class U, class V, class W1, class W2>
std::map<U,V> create__map( W1 creator1, W2 creator2 )
{
    std::map<U,V> res;

    std::size_t size = create__uint8();

    for( std::size_t i = 0; i < size; ++i )
    {
        U k = creator1();
        V v = creator2();

        res.insert( std::make_pair( k, v ) );
    }

    return res;
}

} // namespace dummy

} // namespace basic_parser

#endif // LIB_BASIC_PARSER__DUMMY_CREATOR_H
