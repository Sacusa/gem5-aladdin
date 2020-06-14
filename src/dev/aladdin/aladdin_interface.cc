#include "dev/aladdin/aladdin_interface.hh"

#include "base/trace.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"

Tick AladdinInterface::read(PacketPtr pkt)
{
    assert(pkt->getAddr() == pioAddr);
    assert(pkt->getSize() == 1);
    DPRINTF(AladdinInterface, "Reading from aladdin device\n");
    pkt->makeAtomicResponse();
    return latency;
}

Tick AladdinInterface::write(PacketPtr pkt)
{
    assert(pkt->getAddr() == pioAddr);
    assert(pkt->getSize() == 1);
    DPRINTF(AladdinInterface, "Writing to aladdin device\n");
    pkt->makeAtomicResponse();
    return latency;
}

AddrRangeList AladdinInterface::getAddrRanges() const
{
    AddrRangeList ranges;
    ranges.push_back(RangeSize(pioAddr, pioSize));
    return ranges;
}

AladdinInterface *AladdinInterfaceParams::create()
{
    return new AladdinInterface(this);
}
