//
// Created by Patrick Mintram on 03/03/2017.
//

#ifndef RABBITS_UTILITIES_H
#define RABBITS_UTILITIES_H

#include <string>
#include <vector>

class utilities_t
{

public:
    static utilities_t* get( void );
    unsigned long get_random_number_in_range( const unsigned long max );
    void second_wait( void );
    void print_row( const int num, const std::string& name, const int age, const std::string& colour, const std::string& sex );
    void print_header( void );
    const std::string& get_random_name( void );


protected:
    static utilities_t *m_INSTANCE;
    utilities_t();
    template<typename T>
    void printItem( const T &data, const int width, const char fill = ' ' );
    const int m_NUM_W;
    const int m_NAME_W;
    const int m_AGE_W;
    const int m_COL_W;
    const int m_SEX_W;
    const std::vector<std::string> m_RABBIT_NAMES;


};


#endif //RABBITS_UTILITIES_H
