import random
for i in range (3):
    choose=input("Write your option in lowercase")
    list2=["rock","paper","scissors"]
    print(list2)
    list2.remove(choose)
    print(list2)
    print(f"choice={choose}")
    computer=random.choice(list2)
    print(computer)
    if(computer=="rock" and choose=="paper"):
        print("You win")
    elif(computer=="rock" and choose=="scissors"):
        print("Commputer wins")
    elif(computer=="paper" and choose=="rock"):
        print("Computer wins")
    elif (computer=="paper" and choose=="scissors"):
        print("You win")
    elif (computer=="scissors" and choose=="rock"):
        print("you win")
    elif (computer=="scissors" and choose=="paper"):
        print("Computer wins")