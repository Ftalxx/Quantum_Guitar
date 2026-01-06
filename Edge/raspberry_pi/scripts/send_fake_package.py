import socket
import struct
import time
from src.formats.imu_packet import (
    HEADER_FMT,
    PACKET_VERSION,
    HAND_LEFT,
    HAND_STRUM,
    PAYLOAD_RAW_IMU
)

def send(hand_id):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    ts_ns = time.time_ns()
    header = struct.pack(
        HEADER_FMT,
        PACKET_VERSION,
        hand_id,
        ts_ns,
        PAYLOAD_RAW_IMU
    )

    fake_payload = b"\x00" * 24  # pretend IMU data
    packet = header + fake_payload

    sock.sendto(packet, ("127.0.0.1", 9000))
    sock.close()

if __name__ == "__main__":
    send(HAND_LEFT)
    send(HAND_STRUM)
