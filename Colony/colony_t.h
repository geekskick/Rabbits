//
// Created by Patrick Mintram on 03/03/2017.
//

#ifndef RABBITS_COLONY_T_H
#define RABBITS_COLONY_T_H


#include <vector>
#include "../rabbit_t.h"

class colony_t
{
public:
    static colony_t* get( void );
    void print_info( void );
    void grow( void );
    bool is_alive( void );
    void deinit( void );

protected:

    bool contains_male ( void ) const;
    static colony_t* m_INSTANCE;
    ~colony_t ();
    colony_t();

    typedef std::vector<rabbit_t*> pop_t;
    pop_t m_population;
    const int m_MAX_AGE;
    const int m_FOOD_LIMIT;

    bool has_food_shortage ( void ) const;
    void cull( void );
    void kill_wabbit ( rabbit_t *r );
};


#endif //RABBITS_COLONY_T_H
