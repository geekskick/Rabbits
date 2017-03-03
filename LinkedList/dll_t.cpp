//
// Created by Patrick Mintram on 02/03/2017.
//

#include <iostream>
#include "dll_t.h"

int dll_t::get_length ( void )
{
    return m_count;
}

void dll_t::push_back ( dll_node_t *node )
{
    if( NULL != m_end )
    {
        m_end->set_next(node);
        node->set_previous(m_end);
        m_end = node;
    }
    else
    {
        m_head = node;
        m_end = node;
    }
    m_count += 1;
}

dll_t::~dll_t ()
{
    std::cout << "Destroying DLL" << std::endl;
    dll_node_t *item = m_head;
    dll_node_t *next = nullptr;

    while( nullptr != item )
    {
        next = item->get_next();
        delete item;
        item = next;
        m_count -= 1;
    }
}

void dll_t::push_front ( dll_node_t *node )
{
    if( NULL != m_head )
    {
        m_head->set_previous(node);
        m_head = m_head->get_previous();
    }
    else
    {
        m_head = node;
        m_end = node;
    }
    m_count += 1;

}

void dll_t::remove_item ( const int item_number )
{
    int count = 0;
    dll_node_t *item = m_head;
    while( count != item_number )
    {
        item = item->get_next();
        count += 1;
    }
    remove_node( item );

}

void dll_t::remove_node ( dll_node_t *item )
{
    item->get_previous()->set_next( item->get_next() );
    item->get_next()->set_previous( item->get_previous() );
    delete item;

}

dll_node_t &dll_t::get_item ( const int number )
{
    dll_node_t* item = m_head;
    int count = 0;
    while( count != number )
    {
        item = item->get_next();
        count += 1;
    }
    return *item;
}

void dll_t::push_back ( rabbit_t rabbit )
{
    dll_node_t * node = new dll_node_t( rabbit );
    push_back( node );
}
