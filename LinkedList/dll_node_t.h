//
// Created by Patrick Mintram on 02/03/2017.
//

#ifndef RABBITS_DLL_NODE_T_H
#define RABBITS_DLL_NODE_T_H

#include "../rabbit_t.h"

class dll_node_t
{
public:
    dll_node_t( rabbit_t rabbit )
            : m_rabbit( rabbit ),
              m_next( NULL ),
              m_previous( NULL )
    {}

    const rabbit_t &get_rabbit () const;
    dll_node_t *get_next () const;
    void set_next ( dll_node_t *m_next );
    dll_node_t *get_previous () const;
    void set_previous ( dll_node_t *m_previous );
    bool is_start( void );
    bool is_end( void );

protected:
    rabbit_t m_rabbit;
    dll_node_t* m_next;
    dll_node_t* m_previous;

};


#endif //RABBITS_DLL_NODE_T_H
