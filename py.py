# Konstanta standar Xinu
SYSERR = -1
NPROC = 10  # Maksimal jumlah proses dalam tabel proses


class ProcessEntry:
    """Representasi dari 'struct procent' pada Xinu"""

    def __init__(self, pid: int, prprio: int, is_active: bool = True):
        self.pid = pid
        self.prprio = prprio
        self.is_active = is_active


# Inisialisasi tabel proses (proctab) sebagai simulasi
proctab = {
    0: ProcessEntry(pid=0, prprio=0, is_active=True),  # Null process
    1: ProcessEntry(pid=1, prprio=20, is_active=True),  # Contoh proses aktif
    2: ProcessEntry(pid=2, prprio=50, is_active=True),  # Contoh proses aktif
}


def disable() -> bool:
    """Simulasi mematikan interrupt (mengembalikan status mask sebelumnya)"""
    return True


def restore(mask: bool) -> None:
    """Simulasi mengembalikan status interrupt"""
    pass


def isbadpid(pid: int) -> bool:
    """Mengecek apakah PID tidak valid atau proses tidak aktif"""
    if pid < 0 or pid >= NPROC or pid not in proctab:
        return True
    return not proctab[pid].is_active


def kprintf(text: str) -> None:
    """Simulasi fungsi cetak kernel Xinu"""
    print(text, end="")


def chname(pid: int, newprio: int) -> int:
    """
    chname - Dummy syscall (versi Python)
    Mengubah prioritas proses dan menampilkan pesan 'New Syscall is easy'.
    """
    # Simpan interrupt mask dan matikan interrupt
    mask = disable()

    # Validasi PID
    if isbadpid(pid):
        restore(mask)
        return SYSERR

    # Ambil pointer/referensi ke entri tabel proses
    prptr = proctab[pid]

    # Simpan prioritas lama dan perbarui dengan prioritas baru
    oldprio = prptr.prprio
    prptr.prprio = newprio

    # Cetak pesan sesuai instruksi pada gambar
    kprintf("\n\nNew Syscall is easy\n\n")

    # Kembalikan interrupt mask dan return prioritas lama
    restore(mask)
    return oldprio


# ==========================================
# Contoh Penggunaan / Pengujian
# ==========================================
if __name__ == "__main__":
    target_pid = 1
    prioritas_baru = 100

    print(f"Prioritas awal PID {target_pid}: {proctab[target_pid].prprio}")

    # Memanggil syscall chname
    hasil = chname(target_pid, prioritas_baru)

    if hasil != SYSERR:
        print(f"Syscall berhasil! Prioritas lama: {hasil}")
        print(
            f"Prioritas baru PID {target_pid}: {proctab[target_pid].prprio}"
        )
    else:
        print("Error: PID tidak valid (SYSERR)")