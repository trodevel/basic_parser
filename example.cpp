#include <iostream>
#include <sstream>

#include "parser.h"
#include "csv_helper.h"
#include "str_helper.h"
#include "dummy_creator.h"

void test_vector_1()
{
    auto res = basic_parser::dummy::create__vector_t<std::uint16_t,std::uint16_t(*)()>( & basic_parser::dummy::create__uint16 );

    std::ostringstream os;

    basic_parser::str_helper::write_t( os, res, static_cast<std::ostream & (*)( std::ostream &, const std::uint16_t )>( &basic_parser::str_helper::write ) );

    std::cout << "test_vector_1: " << os.str() << std::endl;
}

void test_vector_2()
{
    auto res = basic_parser::dummy::create__vector_t<std::string,std::string(*)()>( & basic_parser::dummy::create__string );

    std::ostringstream os;

    basic_parser::str_helper::write_t( os, res, static_cast<std::ostream & (*)( std::ostream &, const std::string & )>( &basic_parser::str_helper::write ) );

    std::cout << "test_vector_2: " << os.str() << std::endl;
}

void test_map_1()
{
    auto res = basic_parser::dummy::create__map_t<std::uint16_t,std::string,std::uint16_t(*)(),std::string(*)()>( & basic_parser::dummy::create__uint16, & basic_parser::dummy::create__string );

    std::ostringstream os;

    basic_parser::str_helper::write_t( os, res, static_cast<std::ostream & (*)( std::ostream &, const std::uint16_t )>( &basic_parser::str_helper::write ), static_cast<std::ostream & (*)( std::ostream &, const std::string & )>( &basic_parser::str_helper::write ) );

    std::cout << "test_map_1: " << os.str() << std::endl;
}

int main()
{
    std::ostringstream os;

    basic_parser::csv_helper::write( os, "hello char" );

    basic_parser::csv_helper::write( os, std::string( "hello std::string" ) );

    std::cout << "example: " << os.str() << std::endl;

    std::cout << "dummy_bool: " << (int)basic_parser::dummy::create__bool() << std::endl;
    std::cout << "dummy_uint8: " << (int)basic_parser::dummy::create__uint8() << std::endl;
    std::cout << "dummy_uint16: " << basic_parser::dummy::create__uint16() << std::endl;
    std::cout << "dummy_uint32: " << basic_parser::dummy::create__uint32() << std::endl;
    std::cout << "dummy_uint64: " << basic_parser::dummy::create__uint64() << std::endl;
    std::cout << "dummy_int8: " << (int)basic_parser::dummy::create__int8() << std::endl;
    std::cout << "dummy_int16: " << basic_parser::dummy::create__int16() << std::endl;
    std::cout << "dummy_int32: " << basic_parser::dummy::create__int32() << std::endl;
    std::cout << "dummy_int64: " << basic_parser::dummy::create__int64() << std::endl;
    std::cout << "dummy_string: " << basic_parser::dummy::create__string() << std::endl;
    std::cout << "dummy_float: " << basic_parser::dummy::create__float() << std::endl;
    std::cout << "dummy_double: " << basic_parser::dummy::create__double() << std::endl;

    test_vector_1();
    test_vector_2();
    test_map_1();

    return 0;
}
