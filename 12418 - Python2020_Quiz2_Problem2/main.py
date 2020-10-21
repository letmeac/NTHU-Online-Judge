name = input()
skillList = [str(skill) for skill in input().split()]
print('My nickname is "' + name + '".')
print("I'm good at " + ', '.join(skillList) + ", etc.")
