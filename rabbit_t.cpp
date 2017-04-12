//
// Created by Patrick Mintram on 02/03/2017.
//

#include "rabbit_t.h"
#include "Colony/utilities.h"
#include <ctime>
#include <cstdlib>

const std::vector<std::string> rabbit_t::m_SEX_STRINGS = { "Male", "Female" };
const std::vector<std::string> rabbit_t::m_COLOUR_STRINGS = { "White", "Brown", "Black", "Spotted" };
void rabbit_t::grow ( void )
{
    m_age += 1;
}

rabbit_t::sex_t rabbit_t::get_random_sex ( void )
{
    return static_cast<sex_t>( rand() % ( sexCOUNT ) );
}

rabbit_t::colour_t rabbit_t::get_random_colour ( void )
{
    return static_cast<colour_t>( rand() % ( colourCOUNT ) );
}

int rabbit_t::get_age ( void ) const { return m_age; }

const std::string& rabbit_t::get_sex_string ( void ) const { return m_SEX_STRINGS[m_SEX]; }

const std::string& rabbit_t::get_colour ( void ) const { return m_COLOUR_STRINGS[m_COLOUR]; }

const std::string& rabbit_t::get_name ( void ) const { return m_NAME; }

rabbit_t *rabbit_t::give_birth ( void ) const
{
    rabbit_t* rc = nullptr;
    if( is_adult() && m_SEX == FEMALE )
    {
        rc = new rabbit_t( utilities_t::get()->get_random_name(), get_random_sex(), m_COLOUR, 0 );
    }
    return  rc;
}

rabbit_t *rabbit_t::get_random_rabbit ( void )
{
    return new rabbit_t( utilities_t::get()->get_random_name(), get_random_sex(), get_random_colour(), 0 );
}

rabbit_t::sex_t rabbit_t::get_sex( void ) const
{
    return m_SEX;
}

bool rabbit_t::is_adult ( void ) const
{
    return m_age >= 2;
}
