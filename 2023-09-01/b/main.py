### SUPPORT MATERIAL ###
# https://betterexplained.com/articles/understanding-the-birthday-paradox/
###

t = int( input() )
while t:
    t = t - 1
    year_day = int( input() )
    
    birthday_macth_probability = 1/year_day # In Earth, there is 365 days.
                                            # So, there is an probability 
                                            # p = 1/365 to someone has the
                                            # same birthday than me

    birthday_not_match_probability = 1 - birthday_macth_probability

    people = 2
    while True:
        combinations = people*(people-1)/2
        not_match_probability =  birthday_not_match_probability**combinations
        birthday_macth_probability = 1 - not_match_probability 
        if birthday_macth_probability > 0.5:
            print(people-1)
            break
        people += 1

