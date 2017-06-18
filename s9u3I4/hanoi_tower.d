import std.stdio;

enum MOD = 1_000_000_007;

int hanoi_tower(int[] counts) {
  int result = 0;
  foreach (count; counts) {
    result = (2 * result) % MOD;
    result = (result + count) % MOD;
  }
  return result;
}

void main() {
  writeln(hanoi_tower([]));
  writeln(hanoi_tower([1]));
  writeln(hanoi_tower([2]));
  writeln(hanoi_tower([1, 1]));
  writeln(hanoi_tower([3]));
  writeln(hanoi_tower([2, 1]));
  writeln(hanoi_tower([1, 2]));
  writeln(hanoi_tower([1, 1, 1]));
}
