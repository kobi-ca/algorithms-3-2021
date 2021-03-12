from itertools import islice


def third_last_vowel():
    vowels = set('aeiou')
    input_str = "Hi, hello world"
    # Note, reversed provide a reverse iterator, not
    filtered = filter(lambda x: x in vowels, reversed(input_str))
    index = 2  # 0, 1, 2
    # iterator slice, returns iterator
    # Need None to pick the right overload. see here:
    # https://docs.python.org/3/library/itertools.html#itertools.islice
    # itertools.islice(iterable, stop)
    # itertools.islice(iterable, start, stop[, step])
    # it returns iter, and we call next just once.
    # so we dont care about "stop"
    v = next(islice(filtered, index, None))
    print(f"{v}")


def main():
    third_last_vowel()


if __name__ == "__main__":
    main()
