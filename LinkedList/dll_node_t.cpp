//
// Created by Patrick Mintram on 02/03/2017.
//

#include "dll_node_t.h"

dll_node_t *dll_node_t::get_next () const
{
    return m_next;
}

void dll_node_t::set_next ( dll_node_t *m_next )
{
    dll_node_t::m_next = m_next;
}

dll_node_t *dll_node_t::get_previous () const
{
    return m_previous;
}

void dll_node_t::set_previous ( dll_node_t *m_previous )
{
    dll_node_t::m_previous = m_previous;
}

bool dll_node_t::is_start ( void )
{
    return m_previous == NULL;
}

bool dll_node_t::is_end ( void )
{
    return m_next == NULL;
}


const rabbit_t &dll_node_t::get_rabbit () const
{
    return m_rabbit;
}
