import os
import collections


def inspect_path(path: str):
    if not os.path.isfile(path):
        return

    if not os.access(path, os.X_OK) and path.endswith(".exe"):
        os.remove(path)


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


def main():
    solve()


if __name__ == '__main__':
    main()
