#include <iostream>
#include <sstream>

#include "parser.h"
#include "csv_helper.h"
#include "dummy_creator.h"

void test_vector_1()
{
    auto res = basic_parser::create_dummy__vector<std::uint16_t,std::uint16_t(*)()>( & basic_parser::create_dummy__uint16 );
}

int main()
{
    std::ostringstream os;

    basic_parser::csv_helper::write( os, "hello char" );

    basic_parser::csv_helper::write( os, std::string( "hello std::string" ) );

    std::cout << "example: " << os.str() << std::endl;

    std::cout << "dummy_bool: " << (int)basic_parser::create_dummy__bool() << std::endl;
    std::cout << "dummy_uint8: " << (int)basic_parser::create_dummy__uint8() << std::endl;
    std::cout << "dummy_uint16: " << basic_parser::create_dummy__uint16() << std::endl;
    std::cout << "dummy_uint32: " << basic_parser::create_dummy__uint32() << std::endl;
    std::cout << "dummy_uint64: " << basic_parser::create_dummy__uint64() << std::endl;
    std::cout << "dummy_int8: " << (int)basic_parser::create_dummy__int8() << std::endl;
    std::cout << "dummy_int16: " << basic_parser::create_dummy__int16() << std::endl;
    std::cout << "dummy_int32: " << basic_parser::create_dummy__int32() << std::endl;
    std::cout << "dummy_int64: " << basic_parser::create_dummy__int64() << std::endl;
    std::cout << "dummy_string: " << basic_parser::create_dummy__string() << std::endl;
    std::cout << "dummy_float: " << basic_parser::create_dummy__float() << std::endl;
    std::cout << "dummy_double: " << basic_parser::create_dummy__double() << std::endl;

    test_vector_1();

    return 0;
}
