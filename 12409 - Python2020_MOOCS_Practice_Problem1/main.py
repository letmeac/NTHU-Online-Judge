str1 = input('Enter a string:\n')
str2 = input('Enter another string:\n')

str1Len = len(str1)
str2Len = len(str2)

if str1Len == str2Len:
    print('First string: ' + str1 + ' (length ' + str(str1Len) + ')')
    print('Second string: ' + str2 + ' (length ' + str(str2Len) + ')')
elif str1Len < str2Len:
    print('Shorter string: ' + str1 + ' (length ' + str(str1Len) + ')')
    print('Longer string: ' + str2 + ' (length ' + str(str2Len) + ')')
else:
    print('Shorter string: ' + str2 + ' (length ' + str(str2Len) + ')')
    print('Longer string: ' + str1 + ' (length ' + str(str1Len) + ')')
