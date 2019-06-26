def format_result(i):
    if i != 1:
        return '{} months'.format(i)

    return '1 month'

def solve(loan_amount, down_payment, months, depreciations):
    current_car_value = loan_amount + down_payment
    current_loan_amount = loan_amount
    monthly_payment = loan_amount / months[-1]

    for i in range(len(months)):
        if i > 0:
            current_loan_amount -= monthly_payment

        current_car_value -= current_car_value * depreciations[i]

        if current_car_value > current_loan_amount:
            return i



def run():
    while True:
        inputs = input().split()
        loan_duration = int(inputs[0])
        down_payment = float(inputs[1])
        loan_amount = float(inputs[2])
        num_depreciation_record = int(inputs[3])

        if loan_duration < 0:
            return

        months = []
        depreciations = []
        for i in range(num_depreciation_record):
            inputs = input().split()
            month = int(inputs[0])
            depreciation = float(inputs[1])
            # first record
            if len(months) == 0:
                months.append(month)
                depreciations.append(depreciation)

            else:
                # fill in missing gap
                for j in range(months[-1]+1, month):
                    months.append(months[-1] + 1)
                    depreciations.append(depreciations[-1])

                # add the new record
                months.append(month)
                depreciations.append(depreciation)


        # fill in the remaining months
        for i in range(months[-1], loan_duration):
            months.append(months[-1] + 1)
            depreciations.append(depreciations[-1])


        result = solve(loan_amount, down_payment, months, depreciations)
        print(format_result(result))


    n = int(input())

    for i in range(n):
        a, b = map(int, input().split())
        result = solve(a, b)
        print(result)

if __name__ == "__main__":
    run()
