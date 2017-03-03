//
// Created by Patrick Mintram on 02/03/2017.
//

#ifndef RABBITS_RABBIT_T_H
#define RABBITS_RABBIT_T_H

#include <string>
#include <vector>

class rabbit_t
{
public:
    enum sex_t { MALE = 0, FEMALE, sexCOUNT };
    enum colour_t { WHITE = 0, BROWN, BLACK, SPOTTED, colourCOUNT };

    rabbit_t( const std::string& name, const sex_t sex, const colour_t colour, int age )
            : m_age( age ),
              m_SEX( sex ),
              m_COLOUR( colour ),
              m_NAME( name )
    {}

    void grow( void );

    static sex_t get_random_sex( void );
    static colour_t get_random_colour( void );

    int get_age( void ) const;
    const sex_t get_sex( void ) const;
    const std::string& get_sex_string ( void ) const;
    const std::string& get_colour( void ) const;
    const std::string& get_name( void ) const;
    rabbit_t* give_birth( void ) const;
    bool is_adult( void ) const;

    static rabbit_t* get_random_rabbit( void );

protected:
    int m_age;
    const sex_t m_SEX;
    const colour_t m_COLOUR;
    const std::string& m_NAME;
    static const std::vector<std::string> m_SEX_STRINGS;
    static const std::vector<std::string> m_COLOUR_STRINGS;
};


#endif //RABBITS_RABBIT_T_H
