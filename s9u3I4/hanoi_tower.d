import std.stdio;

enum MOD = 1_000_000_007;

int[] countsFromSizes(int[] sizes) {
  int[] result = [];
  int prev;
  foreach (size; sizes) {
    if (result.length > 0 && size == prev)
      result[result.length - 1]++;
    else
      result ~= 1;
    prev = size;
  }
  return result;
}

int hanoiTower(int[] counts) {
  int result = 0;
  foreach (count; counts) {
    result = (2 * result) % MOD;
    result = (result + count) % MOD;
  }
  return result;
}

void main() {
  writeln(countsFromSizes([]));
  writeln(countsFromSizes([1]));
  writeln(countsFromSizes([1, 1]));
  writeln(countsFromSizes([1, 2]));
  writeln(countsFromSizes([1, 1, 1]));
  writeln(countsFromSizes([1, 1, 2]));
  writeln(countsFromSizes([1, 2, 2]));
  writeln(countsFromSizes([1, 2, 3]));

  writeln(hanoiTower([]));
  writeln(hanoiTower([1]));
  writeln(hanoiTower([2]));
  writeln(hanoiTower([1, 1]));
  writeln(hanoiTower([3]));
  writeln(hanoiTower([2, 1]));
  writeln(hanoiTower([1, 2]));
  writeln(hanoiTower([1, 1, 1]));

  writeln(hanoiTower(countsFromSizes([])));
  writeln(hanoiTower(countsFromSizes([1])));
  writeln(hanoiTower(countsFromSizes([1, 1])));
  writeln(hanoiTower(countsFromSizes([1, 2])));
  writeln(hanoiTower(countsFromSizes([1, 1, 1])));
  writeln(hanoiTower(countsFromSizes([1, 1, 2])));
  writeln(hanoiTower(countsFromSizes([1, 2, 2])));
  writeln(hanoiTower(countsFromSizes([1, 2, 3])));
}
