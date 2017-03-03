//
// Created by Patrick Mintram on 03/03/2017.
//

#include "utilities.h"
#include <iostream>
#include <iomanip>


const int utilities_t::m_AGE_W = 5;
const int utilities_t::m_NAME_W = 10;
const int utilities_t::m_SEX_W = 5;
const int utilities_t::m_COL_W = 8;
const int utilities_t::m_NUM_W = 5;


int utilities_t::get_random_number_in_range ( const int max )
{
    return ( rand() % ( max ) );
}

void utilities_t::second_wait ( void )
{
    clock_t start_time = clock() / CLOCKS_PER_SEC;
    clock_t end_time =  1 + start_time;
    clock_t current_time = clock() / CLOCKS_PER_SEC;
    while( current_time < end_time )
    {
        current_time = clock() / CLOCKS_PER_SEC;
    }

}

void utilities_t::print_header ( void )
{
    std::cout << std::endl;
    printItem( "Num", m_NUM_W );
    printItem( "Name", m_NAME_W );
    printItem( "Age", m_AGE_W );
    printItem( "Colour", m_COL_W );
    printItem( "Sex", m_SEX_W );
    std::cout << std::endl;
    printItem( "-", m_AGE_W + m_COL_W + m_NAME_W + m_NUM_W + m_SEX_W, '-' );
    std::cout << std::endl;
}

template<typename T>
void utilities_t::printItem( const T& data, const int width, const char fill )
{
    std::cout << std::left << std::setw(width) << std::setfill( fill ) << data;
}

void utilities_t::print_row ( const int num, const std::string &name, const int age, const std::string &colour,
                          const std::string &sex )
{
    printItem( num, m_NUM_W );
    printItem( name, m_NAME_W );
    printItem( age, m_AGE_W );
    printItem( colour, m_COL_W );
    printItem( sex, m_SEX_W );
    std::cout <<std::endl;

}

const std::vector<std::string> utilities_t::m_RABBIT_NAMES = { "Richard", "Leah", "Matt", "Tim",
                                                           "Phil", "Henry", "Nathan", "Joe", "James" , "DJ Khaled" };

const std::string &utilities_t::get_random_name ( void )
{
    return m_RABBIT_NAMES[( rand() % m_RABBIT_NAMES.size() )];
}

