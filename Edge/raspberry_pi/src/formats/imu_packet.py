## define header size used in udp_listener.py
## defines struct format for packets
## defines constants for packet types

import struct
from dataclasses import dataclass

# ----------------------------
# Constants
# ----------------------------

PACKET_VERSION = 1

HAND_LEFT = 0
HAND_STRUM = 1

PAYLOAD_RAW_IMU = 0x0001

# ----------------------------
# Header definition
# ----------------------------
# <  = little-endian
# B  = uint8   (version)
# B  = uint8   (hand_id)
# Q  = uint64  (source timestamp)
# H  = uint16  (payload type)

HEADER_FMT = "<BBQH"
HEADER_SIZE = struct.calcsize(HEADER_FMT)

@dataclass
class PacketHeader:
    version: int
    hand_id: int
    source_ts_ns: int
    payload_type: int

    @classmethod
    def from_bytes(cls, data: bytes) -> "PacketHeader":
        if len(data) < HEADER_SIZE:
            raise ValueError("Packet too short for header")

        fields = struct.unpack(HEADER_FMT, data[:HEADER_SIZE])
        return cls(*fields)

    def to_bytes(self) -> bytes:
            return struct.pack(
                HEADER_FMT,
                self.version,
                self.hand_id,
                self.source_ts_ns,
                self.payload_type
            )