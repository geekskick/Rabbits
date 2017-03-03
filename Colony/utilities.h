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
    static int get_random_number_in_range( const int max );
    static void second_wait( void );
    static void print_row( const int num, const std::string& name, const int age, const std::string& colour, const std::string& sex );
    static void print_header( void );
    static const std::string& get_random_name( void );


protected:
    template<typename T>
    static void printItem( const T &data, const int width, const char fill = ' ' );
    static const int m_NUM_W;
    static const int m_NAME_W;
    static const int m_AGE_W;
    static const int m_COL_W;
    static const int m_SEX_W;
    static const std::vector<std::string> m_RABBIT_NAMES;


};


#endif //RABBITS_UTILITIES_H
