from challenge import Challenge1,Challenge2,Challenge3,Challenge4,Challenge5
from secret import flag_easy,flag_hard
roll_left = 56

def guess_coin(level, query_num):
    Ch = level()
    for _ in range(query_num):
        msg = bytes.fromhex(input("msg? > "))
        inverse = input("inverse? > ") == 'y'
        assert len(msg) == Ch.input_size
        print(Ch.roll(msg, inverse).hex())
    assert input("coin? > ") == str(Ch.coin) 

def roll_challenge(challenge_level, challenge):
    global roll_left
    print(f"[+] Challenge Level: {challenge_level}")
    roll_num = int(input(f"How many times are required to roll for solving {challenge_level}? > "))
    roll_left -= roll_num
    [guess_coin(challenge, roll_num) for _ in range(33)]

roll_challenge("1", Challenge1)
roll_challenge("2", Challenge2)
roll_challenge("3", Challenge3)

if roll_left <= 0:
    print("You passed all challenges for EASY but times limit exceeded. Try harder :(")
    exit(-1)

print("flag for easy is ", flag_easy)

roll_challenge("4", Challenge4)
roll_challenge("5", Challenge5)

if roll_left <= 0:
    print("You passed all challenges for HARD but times limit exceeded. Try harder :(")
    exit(-1)

print("flag for hard is ", flag_hard)
