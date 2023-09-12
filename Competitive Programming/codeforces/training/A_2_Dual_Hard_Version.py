def all_possitive(opr, n):
    for i in range(1, n):
            opr.append([i, i-1])

def all_negative(opr, n):
    for i in range(n-2, -1, -1):
            opr.append([i, i+1])

def locate_of_max_element(arr, n):
    mav, loc = -999999999, -1
    for i in range(n):
        if arr[i] > mav:
            mav = arr[i]
            loc = i
    return loc

def locate_of_min_element(arr, n):
    miv, loc = 999999999, -1
    for i in range(n):
        if arr[i] < miv:
            miv = arr[i]
            loc = i
    return loc

def build_the_out_of_range_element(opr, loc):
    s = arr[loc]
    if (s == 0):
        return
    while (abs(s) <= 20):
        opr.append([loc, loc])
        s *= 2

def convert_all_left_negative_into_positive_element(arr, n, opr, loc):
    for i in range(n):
        if arr[i] < 0:
            opr.append([i, loc])
    
def convert_all_left_positive_into_negative_element(arr, n, opr, loc):
    for i in range(n):
        if arr[i] > 0:
            opr.append([i, loc])

tc = int(input())

for _ in range(tc):
    # Input
    n = int(input())
    arr = list(map(int, input().split()))
    # Solve
    opr = []
    miv_loc = locate_of_min_element(arr, n)
    mav_loc = locate_of_max_element(arr, n)
    # Case all elements is positive
    if arr[miv_loc] >= 0:
        all_possitive(opr, n)
    # Case all elements are negative
    elif arr[mav_loc] <= 0:
        all_negative(opr, n)
    # Case have both positive and negative elements
    else:
        # convert into all positive elements
        opr1 = []
        mn, mx = arr[miv_loc], arr[mav_loc]
        while mx < -mn:
            mx *= 2
            opr1.append([mav_loc, mav_loc])
        convert_all_left_negative_into_positive_element(arr, n, opr1, mav_loc)
        all_possitive(opr1, n)
        # convert into all negative elements
        opr2 = []
        mn, mx = arr[miv_loc], arr[mav_loc]
        while mn > -mx:
            mn *= 2
            opr2.append([miv_loc, miv_loc])
        convert_all_left_positive_into_negative_element(arr, n, opr2, miv_loc)
        all_negative(opr2, n)
        
        if len(opr1) <= 31:
            opr = opr1
        else:
            opr = opr2
    # Output
    print(len(opr))
    for v in opr:
        print(v[0]+1, v[1]+1)