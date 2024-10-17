def get_valid_height():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0 and height <= 8:
                return height
        except ValueError:

            continue


height = get_valid_height()

for i in range(1, height + 1):
    num_hashes = i
    num_spaces = height - i

    print(" " * num_spaces, end="")
    print("#" * num_hashes, end="  ")
    print("#" * num_hashes)
