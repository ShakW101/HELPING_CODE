import matplotlib.pyplot as graph

Ys = '''58,62,67,70,74,80,86,91,100,103,110,116,121,125,128,131,131,125,113,95,78,66,58,51,48,45,44,43,42,41,
44,45,47,50,53,55'''.split(",")

Ys = list(map(int, Ys))
Xs = []

for x in range(0, 360, 10):
    Xs.append(x)

graph.plot(Xs, Ys)

graph.xlabel("Input Angle(°)")
graph.ylabel("Output Angle(°)")
graph.title("Input Angle vs Output Angle")

graph.xticks(Xs, rotation=45)
graph.yticks(range(0, max(Ys)+1, 10))
graph.grid(which="major", linewidth=1)
graph.grid(which="minor", linewidth=0.2)
graph.minorticks_on()
graph.show()
