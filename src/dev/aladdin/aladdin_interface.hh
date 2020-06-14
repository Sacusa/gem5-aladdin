#ifndef __DEV_ALADDIN_INTERFACE__
#define __DEV_ALADDIN_INTERFACE

#include "params/AladdinInterface.hh"
#include "dev/io_device.hh"


class AladdinInterface : public BasicPioDevice
{
  protected:
    Tick latency;

  public:
    typedef AladdinInterfaceParams Params;

    const Params *params() const
    {
        return dynamic_cast<const Params *>(_params);
    }

    AladdinInterface(Params *p) : BasicPioDevice(p, 1), latency(p->pio_latency)
    {
        std::cout << "Created a new AladdinInterface object" << std::endl;
    }

    Tick read(PacketPtr pkt) override;

    Tick write(PacketPtr pkt) override;

    AddrRangeList getAddrRanges() const override;
};

#endif // __DEV_ALADDIN_INTERFACE
