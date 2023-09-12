import bisect

def find_first_larger(arr, x):
    index = bisect.bisect_right(arr, x)
    if index < len(arr):
        return index
    else:
        return None

# Example usage:
arr = [1, 3, 5, 7, 9, 9]
x = 7
result = find_first_larger(arr, x)

if result is not None:
    print(f"The first number larger than {x} is {result}")
else:
    print(f"There is no number larger than {x} in the array.")
