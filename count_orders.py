import sys
import argparse

data = []


def count_orders(zipcode):
    global data
    return data.count(zipcode)


def load_file(name):
    global data
    with open(name, "r") as f:
        data = [int(x) for x in f.readlines()]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("datafile")
    parser.add_argument("zipcodes", type=int, nargs="*")
    args = parser.parse_args(sys.argv[1:])
    load_file(args.datafile)
    for zipcode in args.zipcodes:
        print(count_orders(zipcode))


if __name__ == "__main__":
    main()
