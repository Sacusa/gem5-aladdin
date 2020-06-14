from m5.params import *
from m5.proxy import *

from m5.objects.Device import BasicPioDevice
from m5.objects.Serial import SerialDevice

class AladdinInterface(BasicPioDevice):
    type = 'AladdinInterface'
    cxx_header = "dev/aladdin/aladdin_interface.hh"
