try:
    while (1):
        number_a = input()
        number_b = input()

        number_a = int(number_a)
        number_b = int(number_b)

        sum = number_a + number_b

        print(sum)
except ValueError:
    print("Você não digitou um número")