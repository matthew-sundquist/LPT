#ifndef UDP_H_
#define UDP_H_

#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

class udp_channel {

public: 
    udp_channel(uint16_t port);
    ~udp_channel();


    udp_channel(const udp_channel&) = delete;
    udp_channel& operator=(const udp_channel&) = delete;

    bool subscribe();
    int send(const void *data, size_t size);
    int receive(void *data, size_t size);

private:
    int fd;
    uint16_t port;
};
#endif
