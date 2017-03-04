//
// Created by Patrick Mintram on 03/03/2017.
//

#include "colony_t.h"
#include <iostream>
#include "utilities.h"


colony_t* colony_t::m_INSTANCE = nullptr;
colony_t::colony_t ()
    : m_MAX_AGE( 10 ),
      m_FOOD_LIMIT( 50 )
{
    m_population.push_back( rabbit_t::get_random_rabbit() );
    m_population.push_back( rabbit_t::get_random_rabbit() );
    m_population.push_back( rabbit_t::get_random_rabbit() );
    m_population.push_back( rabbit_t::get_random_rabbit() );
    m_population.push_back( rabbit_t::get_random_rabbit() );
}

colony_t* colony_t::get ( void )
{
    if( nullptr == m_INSTANCE )
    {
        m_INSTANCE = new colony_t();
    }

    return  m_INSTANCE;
}

colony_t::~colony_t ()
{


}

bool colony_t::is_alive ( void )
{
    return !m_population.empty();
}

void colony_t::print_info ( void )
{
    int i = 0;

    utilities_t::get()->print_header();
    for( ; i < m_population.size(); i++ )
    {
        utilities_t::get()->print_row( i + 1, m_population[i]->get_name(), m_population[i]->get_age(), m_population[i]->get_colour(),
                            m_population[i]->get_sex_string() );
    }

}

void colony_t::grow ( void )
{
    pop_t new_wabbits;
    rabbit_t *p_rabbit = nullptr;
    bool make_babies = contains_male();
    unsigned long max = m_population.size();
    int i;

    for( i = 0; i < max; i++ )
    {
        p_rabbit = m_population[i];
        p_rabbit->grow();

        if( p_rabbit->get_age() >= m_MAX_AGE )
        {

            kill_wabbit( p_rabbit );
            std::cout << p_rabbit->get_name() << " died" << std::endl;
            max--;

        }
        if( make_babies && ( p_rabbit->get_sex() == rabbit_t::FEMALE ) && ( p_rabbit->is_adult() ) )
        {
            new_wabbits.push_back( p_rabbit->give_birth() );
            std::cout << p_rabbit->get_name() << " gave birth to " << new_wabbits.back()->get_name() << std::endl;
        }

    }

    m_population.insert( m_population.end(), new_wabbits.begin(), new_wabbits.end() );

    if( has_food_shortage() )
    {
        std::cout << "-- FOOD SHORTAGE -- " << std::endl;
        cull();
    }

}

bool colony_t::has_food_shortage ( void ) const
{
    return m_population.size() >= m_FOOD_LIMIT;
}

bool colony_t::contains_male ( void ) const
{
    bool rc = false;
    pop_t::const_iterator it = m_population.begin();
    for( ; it != m_population.end(); it++ )
    {
        if( (*it)->get_sex() == rabbit_t::MALE && ( *it )->is_adult() )
        {
            rc = true;
            break;
        }
    }

    return rc;
}

void colony_t::cull ( void )
{
    unsigned long number_of_victims = m_population.size() / 2;
    for( int i = 0 ; i < number_of_victims; i++ )
    {
        kill_wabbit( m_population[ utilities_t::get()->get_random_number_in_range( m_population.size() ) ] );
    }

}

void colony_t::kill_wabbit( rabbit_t* r )
{
    pop_t::iterator new_end = std::remove( m_population.begin(), m_population.end(), r );
    m_population.erase( new_end, m_population.end() );
    delete r;
}
void colony_t::deinit ( void )
{

    pop_t::iterator it = m_population.begin();

    for( ; it != m_population.end(); it++ )
    {
        m_population.erase( it );
    }
}
