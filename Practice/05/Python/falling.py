g = 9.8
a = g
x0, v0, t = map(float,input("Введите x0, v0, t\n").split())
x_t = x0 + v0 * t - a * t * t /2;
print (x_t - x0)