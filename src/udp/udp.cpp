
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdint.h>
#include <arpa/inet.h>

#include "udp.h"

static constexpr uint32_t loopback_addr = 0x7F'00'00'01;

udp_channel::udp_channel(uint16_t port)
{
    fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (fd < 0)
    {
        return;
    }

}

udp_channel::~udp_channel()
{
    close(fd);
}

int udp_channel::send(const void *data, size_t size)
{
    if (!data)
    {
        return 0;
    }


}

int udp_channel::receive(void *data, size_t size)
{

}

bool udp_channel::subscribe()
{
    if (fd < 0)
    {
        return false;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(loopback_addr);

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        return false;
    }
}
