def bmi(weight: float, height: float) -> float:
    return weight / (height * height)
def print_bmi(bmi: float) -> float:
    if (BMI < 18.5):
        print('Underweight')
    elif (18.5 <= BMI < 25):
        print("Normal weight")
    elif (25 <= BMI < 30):
        print("Overweight")
    else:
        print("Obesity")
print("Введите вес (в килограммах) и рост (в метрах) человека через пробел")  
w, h = map(float,input().split())
BMI = bmi(w, h)
print_bmi(BMI)