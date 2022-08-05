import kdtrace


def test_kdtrace():
    assert kdtrace.add_one(1) == 2
    assert kdtrace.one_plus_one() == 2
