import socket
import time
from typing import Tuple
from src.formats.imu_packet import PacketHeader, HEADER_SIZE
from src.ingest.router import route_packet

UDP_IP = "0.0.0.0"     # listen on all interfaces
UDP_PORT = 9000        # choose once, stick to it
BUFFER_SIZE = 4096     # enough for IMU packets

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((UDP_IP, UDP_PORT))

    print(f"[udp] Listening on {UDP_IP}:{UDP_PORT}")

    packet_count = 0
    start_time = time.time()

    try:
        while True:
            data, addr = sock.recvfrom(BUFFER_SIZE)
            recv_ts = time.time_ns()

            try:
                header = PacketHeader.from_bytes(data)
                payload = data[HEADER_SIZE:]

                route_packet(header, payload)

            except Exception as e:
                print(f"[udp] malformed packet from {addr}: {e}")


    except KeyboardInterrupt:
        print("\n[udp] Shutting down cleanly")

    finally:
        sock.close()

if __name__ == "__main__":
    main()
