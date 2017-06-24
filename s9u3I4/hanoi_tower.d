const MOD = 1_000_000_007;

int[] countsFromSizes(in int[] sizes) {
    int[] result = [];
    int prev;
    foreach (ref size; sizes) {
        if (result.length > 0 && size == prev)
            result[$ - 1]++;
        else
            result ~= 1;
        prev = size;
    }
    return result;
}

int hanoiTower(in int[] counts) {
    auto result = 0;
    foreach (ref count; counts) {
        result = (2 * result) % MOD;
        result = (result + count) % MOD;
    }
    return result;
}

void main() {
    import std.stdio;

    int totalCount;
    readf!" %d"(totalCount);

    int[] sizes = [];
    for (auto i = 0; i < totalCount; i++) {
        int size;
        readf!" %d"(size);
        sizes ~= size;
    }

    writeln(hanoiTower(countsFromSizes(sizes)));
}

unittest {
    assert(countsFromSizes([]) == []);
    assert(countsFromSizes([1]) == [1]);
    assert(countsFromSizes([1, 1]) == [2]);
    assert(countsFromSizes([1, 2]) == [1, 1]);
    assert(countsFromSizes([1, 1, 1]) == [3]);
    assert(countsFromSizes([1, 1, 2]) == [2, 1]);
    assert(countsFromSizes([1, 2, 2]) == [1, 2]);
    assert(countsFromSizes([1, 2, 3]) == [1, 1, 1]);

    assert(hanoiTower([]) == 0);
    assert(hanoiTower([1]) == 1);
    assert(hanoiTower([2]) == 2);
    assert(hanoiTower([1, 1]) == 3);
    assert(hanoiTower([3]) == 3);
    assert(hanoiTower([2, 1]) == 5);
    assert(hanoiTower([1, 2]) == 4);
    assert(hanoiTower([1, 1, 1]) == 7);

    assert(hanoiTower(countsFromSizes([])) == 0);
    assert(hanoiTower(countsFromSizes([1])) == 1);
    assert(hanoiTower(countsFromSizes([1, 1])) == 2);
    assert(hanoiTower(countsFromSizes([1, 2])) == 3);
    assert(hanoiTower(countsFromSizes([1, 1, 1])) == 3);
    assert(hanoiTower(countsFromSizes([1, 1, 2])) == 5);
    assert(hanoiTower(countsFromSizes([1, 2, 2])) == 4);
    assert(hanoiTower(countsFromSizes([1, 2, 3])) == 7);
}
