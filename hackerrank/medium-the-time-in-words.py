# https://www.hackerrank.com/challenges/the-time-in-words/problem

def timeInWords(h, m):
    words = [
        'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen',
        'eighteen', 'nineteen', 'twenty', 'twenty one', 'twenty two', 'twenty three', 'twenty four', 'twenty five', 'twenty six', 'twenty seven', 'twenty eight', 'twenty nine',
    ]

    if m == 0:
        return '{hour} o\' clock'.format(hour = words[h - 1])
    elif m == 15:
        return 'quarter past {hour}'.format(hour = words[h - 1])
    elif m < 30:
        return '{minute} minute{s} past {hour}'.format(minute = words[m - 1], hour = words[h - 1], s = 's' if m > 1 else '')
    elif m == 30:
        return 'half past {hour}'.format(hour = words[h - 1])
    elif m == 45:
        return 'quarter to {hour}'.format(hour = words[h % 12])
    else: # > 30 && < 60
        return '{minute} minute{s} to {hour}'.format(minute = words[59 - m], hour = words[h % 12], s = 's' if m < 59 else '')
