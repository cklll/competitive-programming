def generate_primes(n):
    primes = [True for i in range(n+1)]
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * 2, n+1, p):
                primes[i] = False
        p += 1

    prime_numbers = []
    for i in range(len(primes)):
        if primes[i]:
            prime_numbers.append(i)

    # 0, 1 not prime
    return prime_numbers[2:]


def run():
    n = int(input())

    primes = generate_primes(n)
    prime_hash = {}
    for number in primes:
        prime_hash[number] = True

    prime_counter = 1
    result = []
    for i in range(2, n+1):
        if i in prime_hash:
            result.append(prime_counter)
            prime_counter += 1
        else:
            for index, prime in enumerate(primes):
                if i % prime == 0:
                    result.append(index + 1)
                    break

    str_numbers = map(str, result)
    return ' '.join(str_numbers)


print(run())
