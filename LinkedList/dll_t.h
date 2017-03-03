//
// Created by Patrick Mintram on 02/03/2017.
//

#ifndef RABBITS_DLL_T_H
#define RABBITS_DLL_T_H

#include "dll_node_t.h"

class dll_t
{
public:
    dll_t()
    : m_head( NULL ),
    m_end( NULL ),
    m_count( 0 )
    {}
    ~dll_t ();

    void push_back( rabbit_t rabbit );
    void push_back( dll_node_t *node );
    void push_front( dll_node_t *node );
    void remove_item( const int item_number );
    int get_length( void );
    dll_node_t& get_item( const int number );

protected:
    void remove_node( dll_node_t *item );
    dll_node_t *m_head;
    dll_node_t *m_end;
    int m_count;

};


#endif //RABBITS_DLL_T_H
