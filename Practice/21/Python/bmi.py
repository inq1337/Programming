def bmi(weight: float, height: float) -> float:
    return weight / (height * height / 10000)
def print_bmi(bmi: float) -> float:
    if bmi < 18.5:
        print('Underweight')
    elif 18.5 <= bmi and bmi < 25:
        print('Normal')
    elif 25 <= bmi and bmi < 30:
        print('Overweight')
    else:
        print("Obesity")
print("Введите вес (в килограммах) и рост (в сантиметрах) человека через пробел")  
w, h = map(float,input().split())
print_bmi(bmi(w, h))