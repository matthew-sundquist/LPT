
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "udp.h"

class lpt {
    public:
        lpt(const lpt_addr_t *addr, const lpt_conn_type_t conn_type);
        int lpt_send(const void *data, size_t size);
        int lpt_receive(void *data, size_t size);

    private:
        lpt_conn_type_t conn_type;
        lpt_addr_t address;
};


lpt::lpt(const lpt_addr_t *addr, const lpt_conn_type_t conn_type)
    : 
{
    if (!addr)
    {
        return;
    }

    memcpy(&address, addr, sizeof(address));
}

int lpt_send(lpt_t *endpoint, const void *data, size_t size)
{

}

int lpt_receive(lpt_t *endpoint, void *data, size_t size)
{

}
