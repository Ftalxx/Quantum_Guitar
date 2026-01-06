## the router for ingesting data from various sources

from src.formats.imu_packet import HAND_LEFT, HAND_STRUM, PacketHeader
from src.storage.binary_writer import RawStrumWriter

_writer = RawStrumWriter()

def route_packet(header: PacketHeader, payload: bytes):
    if header.hand_id == HAND_STRUM:
        _writer.write_packet(header.to_bytes() + payload)
        print("[router] STRUM packet written")

    elif header.hand_id == HAND_LEFT:
        # intentionally ignored for now
        pass
