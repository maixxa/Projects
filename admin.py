# Name:  kyle bezant
# Student Number:  10390297

# Import the json module to allow us to read and write data in JSON format.
import json

# takes input and checks if it is an integer and if so will return the value hoever if not will prompt for another input. Note: I was unable to implement this function with how i programmed the 'view' choice.
def input_int(prompt):
    try:
        num = int(prompt)
        return int(prompt)
        
    except:
        prompt = input('please enter an integer')

# takes input and checks if it solely whitespace and if so will continue to prompt for an input other than whitespace
def input_something(prompt):
    while prompt == (' '):
        prompt = input('Please enter something other than blank space')    
    return prompt


# takes a variable and adds it to the end of the file using append, uses 'with open' to open and close the file after writing to it.
def save_data(data_list):
    data.append(data_list)
    with open('data.txt', 'w') as f:
        f.write(json.dumps(data))
    return f

# opens the file into the 'f' variable then attempts to load the data into the 'data' list variable
f = open('data.txt', 'r')
data = []

try:
    data = json.load(f)
except:
    data = []
x = len(data)


print('Welcome to the "Would You Rather" Admin Program.')
# while true to infinitely loop the main body this will also reset the question dictionary for continuous use as well as the count variable and printing the menu options.
while True:
    Question = {
    "option_1": "",
    "option_2": "",
    "mature": "",
    "votes_1": 0,
    "votes_2": 0
    }
    
    
    count = 0
    print('\nChoose [a]dd, [l]ist, [s]earch, [v]iew, [d]elete or [q]uit.')
    choice = input('> ').lower() # Convert input to lowercase to make choice selection case-insensitive.
    
    # if user inputs 'a' they will be prompted to input the first part of the 'would you rather' which is then checked by input_something and run again for the second part of 'would you rather' it then asks if the question is mature.
    if choice == 'a':
        Question['option_1'] = input('Both options should be phrased to follow "Would you rather..."\n Enter Option 1:')
        input_something(Question['option_1'])
        Question['option_2'] = input('Enter Option 2:')
        input_something(Question['option_2'])
        while Question['mature'] != 'y' and Question['mature'] != 'n':
            Question['mature'] = input('Is this question intended for mature audiences only?[Y/N]:')
            print (Question['mature'])
        Question_copy = Question.copy()
        save_data(Question_copy)
        print ('Question added.')

    # if user inputs 'l' it will print a list as it counts through the list and dumps each dictionary entry in the list
    elif choice == 'l':
        if x == 0:
            print ('no questions saved')

        else:
            while count != x:
                print (json.dumps(data[count]))
                count += 1


    # if user inputs 's' they will be prompted to enter a word to search the options of each dictionary, the input will be checked if it is whitespace before doing this.
    elif choice == 's':
        search = input('Please enter a word to search question')
        input_something(search)
        count = 0
        options = [data][count]
        for y in options:            
            if search in str(data[count]):
                print (json.dumps(data[count]['option_1']) + json.dumps(data[count]['option_2']))            
            count+=1
            
    # if user input 'v' they will be prompted to enter a number of the question to view, which will be checked to see if its within range before running through multiple if else to print the options, if its mature and its vote count.
    elif choice == 'v':
        view = input('Please enter the number of the question you would like to view')
        if int(view) <= 0 or int(view) >= x:
            print ("Invalid index number")
            continue
        else:
            print ("Would your rather...\n Option 1) " + data[int(view)]['option_1'] + "? \n Option 2) " + data[int(view)]['option_2'] + "?")

        if data[int(view)]['mature'] == 'y':
            print ("This question is intended for mature audiences only!")
        else:
            print ("This question is intened for all ages.")
        vote_number = data[int(view)]['votes_1']
        if 0 == data[int(view)]['votes_1'] and 0 == data[int(view)]['votes_2']:
            print ("Nobody has answered this question")
        else:
            print ("Option 1 has received " + str(data[int(view)]['votes_1']) + " vote(s), Option 1 has received " + str(data[int(view)]['votes_2']) + " vote(s).")    
        
    # if user inputs 'd' they will be prompted to enter a number to delete a particular dictionary from the list file, 'with open' opens and writes to the file the new list without the deleted dictionary.
    elif choice == 'd':
        remove_question = input('Enter the question number you want to delete.')

        del data[int(remove_question)]
        with open('data.txt', 'w') as f:
            f.write(json.dumps(data))
        print("Question deleted.")

    # if user inputs 'q' they are told 'goodbye' and the program ends.
    elif choice == 'q':
        print ("Goodbye!")
        exit()
        
    else:
        print ("Invalid choice")
        
# If you have been paid to write this program, please delete this comment.
