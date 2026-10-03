#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stddef.h>

/*
 * C-compatable interface for sending, creating, and receiving messages
 */

typedef struct lpt_addr {
    const char *addr;
    size_t len;
} lpt_addr_t;

typedef enum {
    UDP_SOCK,
    TCP_SOCK,
    UNIX_SOCK,
    SHARED_MEM
} lpt_conn_type_t;

typedef struct lpt lpt_t;

int lpt_send(lpt_t *endpoint, const void *data, size_t size);
int lpt_receive(lpt_t *endpoint, void *data, size_t size);

lpt_t *lpt_create(const lpt_addr_t *addr, const lpt_conn_type_t conn_type);

#endif
