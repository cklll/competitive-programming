def run():
    num_test = int(input())

    for i in range(num_test):
        speeds = list(map(int, input().split()))

        result = max(speeds)
        print('Case {}: {}'.format(i + 1, result))

if __name__ == "__main__":
    run()
