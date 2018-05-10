//
// Created by Patrick Mintram on 02/03/2017.
//

#ifndef RABBITS_DLL_NODE_T_H
#define RABBITS_DLL_NODE_T_H

template<class T>
class dll_node_t
{
public:
    dll_node_t( T rabbit )
            : m_rabbit( rabbit ),
              m_next( 0 ),
              m_previous( 0 )
    {}

    const T &get_rabbit () const
    {
        return m_rabbit;
    }
    dll_node_t<T> *get_next () const
    {
        return m_next;
    }
    void set_next ( dll_node_t *m_next )
    {
        dll_node_t::m_next = m_next;
    }

    dll_node_t<T> *get_previous () const
    {
        return m_previous;
    }
    void set_previous ( dll_node_t<T> *m_previous )
    {
        dll_node_t::m_previous = m_previous;
    }

    bool is_start( void )
    {
        return m_previous == 0;
    }
    
    bool is_end( void )
    {
        return m_next == 0;
    }

protected:
    T m_rabbit;
    dll_node_t<T>* m_next;
    dll_node_t<T>* m_previous;

};


#endif //RABBITS_DLL_NODE_T_H
