from matplotlib import pyplot as plt
import pandas as pd
import csv

#plot set A
nameOne = "SetOneA.csv"
nameTwo = "SetTwoA.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)
plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)

plt.legend()
plt.grid(True)

plt.savefig("SetA.png")
plt.close()
print("finish ploting set A")

#plot set B
nameOne = "SetOneB.csv"
nameTwo = "SetTwoB.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)
plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)

plt.legend()
plt.grid(True)

plt.savefig("SetB.png")
plt.close()
print("finish ploting set B")

#plot misclassification for part 1
nameOne = "1A-Misclassified1.csv"
nameTwo = "1A-Misclassified2.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)
plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)

plt.legend()
plt.grid(True)

plt.savefig("part1misclass.png")
plt.close()
print("finish ploting plot misclassification for part 1")

#plot misclassification for part 2
nameOne = "2A-Misclassified1.csv"
nameTwo = "2A-Misclassified2.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)
plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)

plt.legend()
plt.grid(True)

plt.savefig("part2misclass.png")
plt.close()
print("finish ploting plot misclassification for part 2")

#plot misclassification for part 3
nameOne = "3A-Misclassified1.csv"
nameTwo = "3A-Misclassified2.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)
plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)

plt.legend()
plt.grid(True)

plt.savefig("part3misclass.png")
plt.close()
print("finish ploting plot misclassification for part 3")

#plot misclassification for part 4
nameOne = "4A-Misclassified1.csv"
nameTwo = "4A-Misclassified2.csv"

SetOne = pd.read_csv(nameOne)
SetTwo = pd.read_csv(nameTwo)

plt.scatter(SetOne['x'], SetOne['y'], marker='+', c='blue', label=nameOne)
plt.scatter(SetTwo['x'], SetTwo['y'], marker='o', c='red', edgecolors='none', label=nameTwo)

plt.legend()
plt.grid(True)

plt.savefig("part4misclass.png")
print("finish ploting plot misclassification for part 4")