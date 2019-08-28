def run():
    nums = [1, 1, 2, 10]
    target = 10

    num_dict = {}

    for num in nums:
        if num in num_dict:
            num_dict[num] += 1
        else:
            num_dict[num] = 1

    for num in nums:
        remaining = target - num

        found = False
        if remaining in num_dict:
            if remaining != num:
                found = True
            else:
                if num_dict[remaining] > 1:
                    found = True

        if found:
            print(num, remaining)
            return

    print('NOT FOUND')

if __name__ == "__main__":
    run()
