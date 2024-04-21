import os
import collections

hash_entries = {}


def add_hash(hsh, path):
    if hash_entries.get(hsh) is None:
        hash_entries[hsh] = []

    hash_entries[hsh].append(path)


def parse_get_hash(s: str):
    s = s.replace("-", "")
    s = s.replace(" ", "")
    s = s.replace("Algorithm", "")
    s = s.replace("Hash", "")
    s = s.replace("Path", "")


def inspect_path(path: str):
    if not os.path.isfile(path):
        return
    print("Inspect path:", path)
    cmd = f"Get-FileHash .\\{path} > tmp.txt"
    os.system(cmd)

    with open("tmp.txt", "r") as tmp_file:
        old = tmp_file.read()
        print(old)
        add_hash(parse_get_hash(old), path)


def traverse_folder(path):
    q = collections.deque()
    q.append(path)
    if not os.path.exists(path):
        return

    while not len(q) == 0:
        p = q[0]
        q.popleft()
        for entry in os.listdir(p):
            entry_path = os.path.join(p, entry)
            if os.path.isdir(entry_path):
                q.append(entry_path)
            elif os.path.isfile(entry_path):
                inspect_path(entry_path)


def solve():
    traverse_folder("TEST")

    with open("output.txt", "w") as f:
        for hsh in hash_entries:
            print(hsh, hash_entries[hsh], file=f)


def main():
    solve()


if __name__ == '__main__':
    main()
