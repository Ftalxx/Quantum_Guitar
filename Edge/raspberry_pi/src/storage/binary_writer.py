## writer for binary files

import os
import struct
import time
from pathlib import Path

# Disk record format
# Q = uint64 (pi receive timestamp ns)
# I = uint32 (packet byte length)
RECORD_HEADER_FMT = "<QI"
RECORD_HEADER_SIZE = struct.calcsize(RECORD_HEADER_FMT)

class RawStrumWriter:
    def __init__(self, base_dir="data/raw/strumming"):
        self.base_dir = Path(base_dir)
        self.base_dir.mkdir(parents=True, exist_ok=True)

        ts = time.strftime("%Y%m%d_%H%M%S")
        self.file_path = self.base_dir / f"strum_{ts}.bin"

        self.f = open(self.file_path, "ab", buffering=0)

        print(f"[writer] writing to {self.file_path}")

    def write_packet(self, packet_bytes: bytes):
        pi_ts = time.time_ns()
        header = struct.pack(
            RECORD_HEADER_FMT,
            pi_ts,
            len(packet_bytes)
        )
        self.f.write(header)
        self.f.write(packet_bytes)

    def close(self):
        self.f.close()
