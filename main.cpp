#include <iostream>
#include <iomanip>

#include "rabbit_t.h"
#include "LinkedList/dll_t.h"
#include "Colony/colony_t.h"
#include "Colony/utilities.h"


int main ()
{
    {
        std::cout << "Hello, World Task 1" << std::endl;

        dll_t linked_list;

        // populate dll
        for ( int i = 20; i > 0; i-- )
        {

            linked_list.push_back(rabbit_t(utilities_t::get_random_name(),
                                           rabbit_t::get_random_sex(),
                                           rabbit_t::get_random_colour(),
                                           i));
        }

        // print dll information
        const int max = linked_list.get_length() - 1;

        utilities_t::print_header();

        for ( int i = 0; i <= max; i++ )
        {
            utilities_t::print_row(i + 1,
                               linked_list.get_item(i).get_rabbit().get_name(),
                               linked_list.get_item(i).get_rabbit().get_age(),
                               linked_list.get_item(i).get_rabbit().get_colour(),
                               linked_list.get_item(i).get_rabbit().get_sex_string());
        }

        std::cout << "Done" << std::endl;
    }
    {
        std::cout << "Hello, World Task 2" << std::endl;

        while( colony_t::get()->is_alive() )
        {
            colony_t::get()->grow();
            utilities_t::second_wait();
            colony_t::get()->print_info();
            utilities_t::second_wait();
        }

        colony_t::get()->deinit();
        std::cout << "Done" << std::endl;
    }

    return 0;
}