# Create an object oriented version of a guess random number game which offers the public
# methods enter_guess(), get_new_random_number() and check(). The player can make 5
# guesses. Also, you should indicate if the guess is lower or higher than the actual number.
import random

class RandomNumber:
    number = 50
    guessed = None

    def enter_guess(self):
      for i in range(5):
          print(f"[{5 - i} attempts left]")
          self.guessed = int(input("Enter your guess: "))
          if self.check():
            break
          else: 
            if i == 4:
              print(f"You lost! The correct number was {self.number}.")

    def get_new_random_number(self):
      self.number = random.randint(1, 50);

    def check(self):
      if self.guessed == self.number:
        print("Congratulations! You guessed correctly.")
        return True
      elif self.guessed > self.number:
        print("The number you guessed is greater than the correct number, try again!")   
        return False;
      else:
        print("The number you guessed is less than the correct number, try again!")   
        return False

rn1 = RandomNumber()
rn1.get_new_random_number()
rn1.enter_guess()
