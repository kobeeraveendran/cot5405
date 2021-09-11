def ksort(arr, i):

    sublists = [arr[j:j + 5] for j in range(0, len(arr), 5)]
    medians = [sorted(sublist)[len(sublist) // 2] for sublist in sublists]

    if len(medians) <= 5:
        pivot = sorted(medians)[len(medians) // 2]

    else:
        pivot = ksort(medians, len(medians) // 2)

    # partitioning
    low = [j for j in arr if j < pivot]
    high = [j for j in arr if j > pivot]

    print("low: ", low)
    print("high: ", high)

    k = len(low)

    if i < k:
        return ksort(low, i)

    elif i > k:
        return ksort(high, i - k - 1)

    return pivot

if __name__ == "__main__":
    test1 = [25, 21, 98, 100, 76, 22, 43, 60, 89, 87]
    #test1 = [1, 2, 3, 4, 5, 1000, 8, 9, 99]
    test2 = [1, 2, 3, 4, 5, 6]

    print(ksort(test1, 0))