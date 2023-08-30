# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
s = input()

while '  ' in s:
    s = s.replace('  ', ' ')

s = s.strip()

print(s)
