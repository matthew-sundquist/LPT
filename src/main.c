#include <stdio.h>

#include "interface.h"


int main()
{
    lpt_addr_t addr = {.addr = "test", .len = 4};

    lpt_conn_type_t conn_type = UDP_SOCK;


    lpt_t *inst = lpt_create(&addr, conn_type);
    
    printf("sigma!");
    return 0;
}
