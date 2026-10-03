
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "udp.h"

typedef struct lpt {
    lpt_conn_type_t conn_type;
    lpt_addr_t addr;

    int (*send)(const void *, size_t);
    int (*receive)(void *, size_t);
} lpt_t;

lpt_t *lpt_create(const lpt_addr_t *addr, const lpt_conn_type_t conn_type)
{
    if (!addr)
    {
        return NULL;
    }

    lpt_t *new_conn = (lpt_t *) malloc(sizeof(lpt_t));

    if (!new_conn)
    {
        return NULL;
    }

    memcpy(&new_conn->addr, addr, sizeof(new_conn->addr));
    new_conn->conn_type = conn_type;

    switch (conn_type)
    {
        case(UDP_SOCK):
            {

            }
    }
    return new_conn;
}

int lpt_send(lpt_t *endpoint, const void *data, size_t size)
{

}

int lpt_receive(lpt_t *endpoint, void *data, size_t size)
{

}
