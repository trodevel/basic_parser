#include <iostream>
#include <sstream>

#include "exported_parser.h"
#include "csv_helper.h"

int main()
{
    std::ostringstream os;

    basic_parser::csv_helper::write( os, "hello char" );

    basic_parser::csv_helper::write( os, std::string( "hello std::string" ) );

    std::cout << "example: " << os.str() << std::endl;

    return 0;
}
