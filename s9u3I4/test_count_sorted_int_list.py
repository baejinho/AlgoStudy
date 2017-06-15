#!/usr/bin/env python

from typing import List, Tuple, Union
import pytest


def _find_index_sorted_list(xs: List[Union[int, float]], x: Union[int, float], lower: int=..., upper: int=...) -> int:
    if lower == ...:
        lower = 0
    if upper == ...:
        upper = len(xs)

    mid_index = int((lower + upper) / 2)

    if lower >= upper:
        return mid_index

    mid_value = xs[mid_index]

    if x < mid_value:
        return _find_index_sorted_list(xs, x, lower, mid_index)
    elif x > mid_value:
        return _find_index_sorted_list(xs, x, mid_index + 1, upper)
    else:
        return mid_index


def count_sorted_int_list(ns: List[int], n: int) -> int:
    lower = _find_index_sorted_list(ns, n - 0.5)
    upper = _find_index_sorted_list(ns, n + 0.5)
    return upper - lower


@pytest.mark.parametrize('xs, x, index', [
    ([], 3, 0),
    ([3], 3, 0),
    ([3], 2.5, 0),
    ([3], 3.5, 1),
    ([1, 3], 3, 1),
    ([1, 3], 2.5, 1),
    ([1, 3], 3.5, 2),
    ([4, 4, 4], 3, 0),
    ([1, 1, 3, 3, 4, 4, 4], 2.5, 2),
    ([1, 1, 3, 3, 4, 4, 4], 3.5, 4),
])
def test_find_index_sorted_list(xs: List[Union[int, float]], x: Union[int, float], index: int):
    assert _find_index_sorted_list(xs, x) == index


@pytest.mark.parametrize('ns, n, count', [
    ([], 3, 0),
    ([3], 0, 0),
    ([3], 3, 1),
    ([1, 3], 1, 1),
    ([1, 3], 3, 1),
    ([1, 3], 4, 0),
    ([1, 1, 3], 1, 2),
    ([1, 1, 3], 3, 1),
    ([1, 1, 3], 4, 0),
    ([4, 4, 4], 3, 0),
    ([4, 4, 4], 4, 3),
    ([1, 1, 3, 3, 4, 4, 4], 0, 0),
    ([1, 1, 3, 3, 4, 4, 4], 1, 2),
    ([1, 1, 3, 3, 4, 4, 4], 3, 2),
    ([1, 1, 3, 3, 4, 4, 4], 4, 3),
    ([0, 0, 0, 0, 1, 1, 3, 3, 4, 4, 4], 0, 4),
    ([-5, -5, -5, -5, -5, 0, 0, 0, 0, 1, 1, 3, 3, 4, 4, 4], -5, 5),
])
def test_count_sorted_int_list(ns: List[int], n: int, count: int):
    assert count_sorted_int_list(ns, n) == count
