#include <stdio.h>
#include "./get_opt/get_opt_size.h"
#include "./get_opt/get_path.h"
#include "./get_opt/is_l.h"

#include "./print_file/show_file_all_info.h"
#include "./print_file/show_file_names.h"

int main(int argc, char const *argv[])
{
    
    int size = get_opt_size(argc);
    int have_l = is_l(argc, argv);
    switch (size)
    {
    case 0:
        show_file_names("./");
        break;
    case 1:
        if(have_l){
            show_file_all_info("./");
        }else{
            show_file_all_info(get_path(argc, argv));
        }
        break;
    case 2:
        if(have_l){
            show_file_all_info(get_path(argc, argv));
        }
        break;
    default:
        break;
    }


    return 0;
}

