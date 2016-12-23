buzz = lambda : ['Buzz_Fizz' if tmp % 3 == 0 and tmp % 5 == 0 else ('Buzz' if tmp % 3 == 0 else ('Fizz' if tmp % 5 == 0 else tmp)) for tmp in range(1, 100)]
#['Buzz_Fizz' if t%3==0 and t%5==0 else ('Buzz' if t%3==0 else ('Fizz' if t%5 ==0 else t)) for t in range(1,100)]
