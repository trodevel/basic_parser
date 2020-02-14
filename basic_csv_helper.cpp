/*

CSV Helpers.

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

// $Revision: 12714 $ $Date:: 2020-02-14 #$ $Author: serge $

// includes
#include "basic_csv_helper.h"
#include "utils/csv_helper.h"

namespace basic_parser
{

namespace csv_encoder
{

std::ostream & write( std::ostream & os, const bool r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const int8_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const uint8_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const int16_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const uint16_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const int32_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const uint32_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const int64_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const uint64_t r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const float r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const double r )
{
    return utils::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const std::string & r )
{
    return utils::CsvHelper::write( os, r );
}

} // namespace csv_encoder

} // namespace basic_parser

