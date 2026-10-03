#ifndef UDP_H_
#define UDP_H_

#include <stddef.h>

int udp_send(const void *data, size_t size);

int udp_receive(void *data, size_t size);

#endif
