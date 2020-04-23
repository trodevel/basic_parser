#include <iostream>
#include <sstream>

#include "exported_parser.h"
#include "exported_csv_helper.h"

int main()
{
    std::ostringstream os;

    basic_parser::csv_encoder::write( os, "hello char" );

    basic_parser::csv_encoder::write( os, std::string( "hello std::string" ) );

    std::cout << "example: " << os.str() << std::endl;

    return 0;
}
