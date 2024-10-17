def get_valid_float():
    while True:
        try:
            value = float(input("cash: "))
            if value >= 0:
                return value
        except ValueError:
            continue


cash = get_valid_float()
cents = int(cash * 100)

c25 = cents // 25
cents %= 25

c10 = cents // 10
cents %= 10

c5 = cents // 5
cents %= 5

c1 = cents

print(c25 + c10 + c5 + c1)
