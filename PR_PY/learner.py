def reg():
    with open('svi.txt','r') as file_handle:
        #It's best to open file by usnig "with" statement as it closes the file after reading automatically
        #Sometimes when you forget to close you file after reading or writing the data in it could be courppted
        #So it's best to always open a file like
        #with open('file_path',mode) as any_variable_name_you_like:
            #Do some reading or anything with file

        opened_file = file_handle.read()
        registered_username_list = [i.split('|')[0] for i in opened_file.split('\n')]
        #Above line is left for you to correct(if only it's wrong) as i don't know how did you arrage the textfile

        file_handle.close() #Doing this is un nessasery but i still do it anyway        
        #i have a rough idea but not very sure how are you seprating the file  entries by
        # The variable 'registered_username_list' should contain all the registered usernames
    first_name = input('Please Enter your first name: ')
    last_name = input('Please Enter your last name: ')
    if not((first_name in registered_username_list)) : print('User name "%s" is available!'%(first_name,))#checks if last or first name.. 
    if not((last_name in registered_username_list)) : print('User name "%s" is available!'%(last_name,))#...could be used as usernames
    text = "Please Enter Username*"
    while True:
        username = input(text)
        if (username in registered_username_list):
            print("Sorry , username already exists , please try a diffrent username. :(")
            text = "Please re-enter Username"
        else:
            break
    print("Please choose a password: \nThe password must be alpha numeric and must be of atleast 7 characters!")
    while True:
        password = input("Please enter you password as per the criteria given about:")
        if (( len(password) < 7 ) or not( (any(i in password for i in [x for x in "1234567890"])) ) ):
            print("Wrong type , Please enter you password according to the above dicipline!")
            continue
        re_password = input(" Please confirm your password:")
        if not(password == re_password):
            print("Password Don't match!")
            continue
        else:
            break
    with open('svi.txt','a') as file_handle:
        print("Thanks for registering with us!")
        file_handle.write("%s|%s|%s|%s|kupac\n"%(username,password,first_name,last_name))
