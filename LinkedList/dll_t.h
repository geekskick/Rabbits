//
// Created by Patrick Mintram on 02/03/2017.
//

#ifndef RABBITS_DLL_T_H
#define RABBITS_DLL_T_H

#include "dll_node_t.h"

template<class T>
class dll_t
{
public:
    dll_t()
    : m_head( NULL ),
    m_end( NULL ),
    m_count( 0 )
    {}

    ~dll_t()
    {
        std::cout << "Destroying DLL" << std::endl;
        dll_node_t<T> *item = m_head;
        dll_node_t<T> *next = nullptr;

        while( nullptr != item )
        {
            next = item->get_next();
            delete item;
            item = next;
            m_count -= 1;
        }
    }

    void push_back( T rabbit )
    {
        dll_node_t<T> * node = new dll_node_t<T>( rabbit );
        push_back( node );
    }

    void push_back( dll_node_t<T> *node )
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
    void push_front( dll_node_t<T> *node )
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
    void remove_item( const int item_number )
    {
        int count = 0;
        dll_node_t<T> *item = m_head;
        while( count != item_number )
        {
            item = item->get_next();
            count += 1;
        }
        remove_node( item );

}

    int get_length ( void )
    {
        return m_count;
    }

    dll_node_t<T>& get_item( const int number )
    {
        dll_node_t<T>* item = m_head;
        int count = 0;
        while( count != number )
        {
            item = item->get_next();
            count += 1;
        }
        return *item;
    }

protected:
    void remove_node( dll_node_t<T> *item )
    {
        item->get_previous()->set_next( item->get_next() );
        item->get_next()->set_previous( item->get_previous() );
        delete item;

    }
    dll_node_t<T> *m_head;
    dll_node_t<T> *m_end;
    int m_count;

};


#endif //RABBITS_DLL_T_H
