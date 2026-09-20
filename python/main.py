from CinemaFilm import CinemaFilm

import re # library for regular expression
import sys # library for system exit


# function to display all films
def displayFilms(filmList):
    # error handling if the film list is empty
    if not filmList:
        print("non absolute cinema. no film.\n")
        return

    # print all films numbered
    print("\nabsolute cinema. list of films:")
    filmNumber = 1
    print('-----------------------------')
    for film in filmList:
        print(f"{filmNumber}. [ {film.getFilmTitle()} ]")
        print(f"     code: {film.getFilmCode()}")
        print(f"     genre: {film.getFilmGenre()}")
        print(f"     duration: {film.getFilmDuration()} minutes")
        print(f"     ticket price: ${film.getTicketPrice()}")
        print(f"     rating: {film.getFilmRating()}/10")
        print('-----------------------------')
        filmNumber += 1

    # print total films
    print("total absolute cinema films: ", len(filmList), "\n")

# function to add new film
def addFilm(filmList, genres):
    # ask user for film code
    print("\ncode: ", end="")
    # read film code
    code = input()
    # error handling for film code format and duplicates
    while True:
        if not re.fullmatch(r"CF\d{3}", code):
            print("non absolute cinema. invalid code. format must be CF000.\n")
        else:
            codeExists = False
            for film in filmList:
                if film.getFilmCode() == code:
                    codeExists = True
                    break

            if not codeExists:
                break

            print("non absolute cinema. film code already exists. please enter a different code.\n")

        print("code: ", end="")
        code = input()

    # ask and read film title
    print("title: ", end="")
    title = input()

    # ask and read film genre
    print("genre: ", end="")
    genre = input()
    # error handling for film genre if the genre is not in the list
    while genre not in genres:
        print("non absolute cinema. invalid genre. please enter a valid genre from this list: [", end="")
        for i, validGenre in enumerate(genres):
            if i > 0:
                print(", ", end="")
            print(validGenre, end="")
        print("]\n")
        print("genre: ", end="")
        genre = input()
    genre = genre

    # ask for duration
    print("duration (minutes): ", end="")
    while True:
        # input the duration as string
        durationInput = input().rstrip(" \t\r\n")
        # error handling if number is decimal
        if re.fullmatch(r"-?\d+\.\d+", durationInput):
            print("non absolute cinema. invalid duration. no decimal numbers allowed.")
        else:
            # error handling if duration is not a number
            try:
                duration = int(durationInput)
                # error handling if duration is negative
                if duration < 0:
                    print("non absolute cinema. invalid duration. negative numbers are not allowed.")
                # error handling if duration is more than 873 minutes
                elif duration > 873:
                    print("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.")
                else:
                    break
            except (ValueError, OverflowError):
                print("non absolute cinema. invalid duration. input is not a valid number.")
        # keep asking for duration until valid
        print("\nduration (minutes): ", end="")

    # ask for ticket price
    print("ticket price (us dollars): ", end="")
    while True:
        # input the ticket price as string
        ticketPriceInput = input().rstrip(" \t\r\n")
        # error handling if number is decimal
        if re.fullmatch(r"-?\d+\.\d+", ticketPriceInput):
            print("non absolute cinema. invalid ticket price. no decimal numbers allowed.\n")
        else:
            # error handling if ticket price is not a number
            try:
                ticketPrice = int(ticketPriceInput)
                # error handling if ticket price is negative
                if ticketPrice < 0:
                    print("non absolute cinema. invalid ticket price. negative numbers are not allowed.")
                # error handling if ticket price is more than 500 dollars
                elif ticketPrice > 500:
                    print("non absolute cinema. invalid ticket price. the maximum ticket price is 500 dollars.")
                else:
                    break
            except (ValueError, OverflowError):
                print("non absolute cinema. invalid ticket price. input is not a valid number.")
        # keep asking for ticket price until valid
        print("\nticket price (us dollars): ", end="")

    # ask for rating
    print("rating (out of 10): ", end="")
    while True:
        # input the rating as string
        ratingInput = input().rstrip(" \t\r\n")
        # error handling if number is decimal
        if re.fullmatch(r"-?\d+\.\d+", ratingInput):
            print("non absolute cinema. invalid rating. no decimal numbers allowed.\n")
        else:
            # error handling if rating is not a number
            try:
                rating = int(ratingInput)
                # error handling if rating is negative
                if rating < 0:
                    print("non absolute cinema. invalid rating. negative numbers are not allowed.")
                # error handling if rating is more than 10
                elif rating > 10:
                    print("non absolute cinema. invalid rating. the maximum rating is 10.")
                else:
                    break
            except (ValueError, OverflowError):
                print("non absolute cinema. invalid rating. input is not a valid number.")
        # keep asking for rating until valid
        print("\nrating (out of 10): ", end="")

    # instantiate a new CinemaFilm object from user input
    newFilm = CinemaFilm(code, title, genre, duration, ticketPrice, rating)
    # add it to the list
    filmList.append(newFilm)
    # print success message
    print("absolute cinema. new film has been added.\n")

# function to update film
def updateFilm(filmList, genres):
    # ask user for film code to update
    print("\nenter film code to update: ", end="")
    # read film code
    filmCode = input()

    # find the film with the given code
    for film in filmList:
        if film.getFilmCode() == filmCode:
            # ask and read new film code
            print("new code: ", end="")
            newCode = input()
            # error handling for film code format and duplicates
            while True:
                if not re.fullmatch(r"CF\d{3}", newCode):
                    print("non absolute cinema. invalid code. format must be CF000.\n")
                else:
                    codeExists = False
                    for otherFilm in filmList:
                        if otherFilm is not film and otherFilm.getFilmCode() == newCode:
                            codeExists = True
                            break

                    if not codeExists:
                        break

                    print("non absolute cinema. film code already exists. please enter a different code.\n")

                print("new code: ", end="")
                newCode = input()
            # update the film's code using setter method
            film.setFilmCode(newCode)

            # ask and read new film title
            print("new title: ", end="")
            newTitle = input()
            # update the film's title using setter method
            film.setFilmTitle(newTitle)

            # ask and read new film genre
            print("new genre: ", end="")
            newGenre = input()
            # error handling for film genre if the genre is not in the list
            while newGenre not in genres:
                print("non absolute cinema. invalid genre. please enter a valid genre from this list: [", end="")
                for i, validGenre in enumerate(genres):
                    if i > 0:
                        print(", ", end="")
                    print(validGenre, end="")
                print("]\n")
                print("new genre: ", end="")
                newGenre = input()
            # update the film's genre using setter method
            film.setFilmGenre(newGenre)

            # ask for new duration
            print("new duration (minutes): ", end="")
            while True:
                # input the duration as string
                durationInput = input().rstrip(" \t\r\n")
                # error handling if number is decimal
                if re.fullmatch(r"-?\d+\.\d+", durationInput):
                    print("non absolute cinema. invalid duration. no decimal numbers allowed.")
                else:
                    # error handling if duration is not a number
                    try:
                        newDuration = int(durationInput)
                        # error handling if duration is negative
                        if newDuration < 0:
                            print("non absolute cinema. invalid duration. negative numbers are not allowed.")
                        # error handling if duration is more than 873 minutes
                        elif newDuration > 873:
                            print("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.")
                        else:
                            break
                    except (ValueError, OverflowError):
                        print("non absolute cinema. invalid duration. input is not a valid number.")
                # keep asking for duration until valid
                print("\nnew duration (minutes): ", end="")
            # update the film's duration using setter method
            film.setFilmDuration(newDuration)

            # ask for new ticket price
            print("new ticket price (us dollars): ", end="")
            while True:
                # input the ticket price as string
                newTicketPriceInput = input().rstrip(" \t\r\n")
                # error handling if number is decimal
                if re.fullmatch(r"-?\d+\.\d+", newTicketPriceInput):
                    print("non absolute cinema. invalid ticket price. no decimal numbers allowed.\n")
                else:
                    # error handling if ticket price is not a number
                    try:
                        newTicketPrice = int(newTicketPriceInput)
                        # error handling if ticket price is negative
                        if newTicketPrice < 0:
                            print("non absolute cinema. invalid ticket price. negative numbers are not allowed.")
                        # error handling if ticket price is more than 500 dollars
                        elif newTicketPrice > 500:
                            print("non absolute cinema. invalid ticket price. the maximum ticket price is 500 dollars.")
                        else:
                            break
                    except (ValueError, OverflowError):
                        print("non absolute cinema. invalid ticket price. input is not a valid number.")
                # keep asking for ticket price until valid
                print("\nnew ticket price (us dollars): ", end="")
            # update the film's ticket price using setter method
            film.setTicketPrice(newTicketPrice)

            # ask for new rating
            print("new rating (out of 10): ", end="")
            while True:
                # input the rating as string
                newRatingInput = input().rstrip(" \t\r\n")
                # error handling if number is decimal
                if re.fullmatch(r"-?\d+\.\d+", newRatingInput):
                    print("non absolute cinema. invalid rating. no decimal numbers allowed.\n")
                else:
                    # error handling if rating is not a number
                    try:
                        newRating = int(newRatingInput)
                        # error handling if rating is negative
                        if newRating < 0:
                            print("non absolute cinema. invalid rating. negative numbers are not allowed.")
                        # error handling if rating is more than 10
                        elif newRating > 10:
                            print("non absolute cinema. invalid rating. the maximum rating is 10.")
                        else:
                            break
                    except (ValueError, OverflowError):
                        print("non absolute cinema. invalid rating. input is not a valid number.")
                # keep asking for rating until valid
                print("\nnew rating (out of 10): ", end="")
            # update the film's rating using setter method
            film.setFilmRating(newRating)

            print("absolute cinema. film has been updated.\n")
            return

    # error handling if the film code is not found
    print("non absolute cinema. film with code ", filmCode, " was not found.\n")

# function to delete film
def deleteFilm(filmList):
    # ask for film code to delete
    print("\nenter film code to delete: ", end="")
    # read film code
    filmCode = input()

    # find film code in list
    for i, film in enumerate(filmList):
        if film.getFilmCode() == filmCode:
            # if found
            # remove film from list
            del filmList[i]
            print("absolute cinema. film has been deleted.\n")
            return
    # error handling if the film code is not found
    print("non absolute cinema. film with code ", filmCode, " was not found.\n")

# function to search film
def searchFilm(filmList):
    # ask for film code to search
    print("\nenter film code to search: ", end="")
    # read film code
    filmCode = input()

    # find film code in list
    for film in filmList:
        # if found
        if film.getFilmCode() == filmCode:
            # print film details
            print("absolute cinema. film found:")
            print('-----------------------------')
            print(f"[ {film.getFilmTitle()} ]")
            print(f"  code: {film.getFilmCode()}")
            print(f"  genre: {film.getFilmGenre()}")
            print(f"  duration: {film.getFilmDuration()} minutes")
            print(f"  ticket price: ${film.getTicketPrice()}")
            print(f"  rating: {film.getFilmRating()}/10")
            print("-----------------------------\n")
            return
    # error handling if the film code is not found
    print("non absolute cinema. film with code ", filmCode, " was not found.\n")

# SUPER SECRET ABSOLUTE CINEMA FUNCTION (DO NOT CALL THIS FUNCTION UNLESS YOU ARE ABSOLUTELY SURE)
def absoluteCinema():
    print("⠀⠀⢀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀")
    print("⢀⠀⣿⡂⢹⡇⠀⠀⣰⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀")
    print("⢸⡇⢸⣇⢸⣇⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⠀⠀⣯⡀⡆⠀⠀")
    print("⢸⣷⢸⣇⣸⣇⠀⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⣂⠀⣿⡄⢸⡀⣤")
    print("⢠⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣊⡝⠛⠙⠂⠄⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣦⣼⣷⣼⣁⠼")
    print("⢸⣿⣿⣿⣿⣿⣿⣀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⡻⣥⢋⡔⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣂⣜⣿⡟⢿⣿⣿⣄")
    print("⠈⣿⣿⣿⣿⣿⣿⣿⠿⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣷⢯⣿⣾⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢪⣷⣿⢿⣿⣿")
    print("⠀⣿⣿⣟⢿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⡟⠛⠉⡉⢸⡉⠁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣽⣗⣿⠇")
    print("⠀⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠺⣿⡇⣤⡤⢔⡿⣇⠀⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣯⠀")
    print("⠘⡟⣛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⣿⣿⠗⡲⠏⠟⠿⠀⠈⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠍⠁⠁⠀")
    print("⠃⡜⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣼⣿⡟⢡⡿⠿⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⠒⠂⠂")
    print("⠐⢐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠸⣡⢶⣿⣟⡃⠀⠘⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⡀⠀")
    print("⢠⡏⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡰⢨⠣⠉⠉⠋⠉⠀⠀⠀⠀⢈⠀⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡿⠀⠀⠀⠀")
    print("⢺⡇⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⡿⢛⢭⠏⣢⠍⠈⠖⠀⠀⠒⣶⢦⡁⠂⠀⠀⠀⠀⠀⠯⠤⣤⣴⢶⣍⠝⣯⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢌⣿⠱⠀⠀⠀⠀⠀")
    print("⣯⣯⠸⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠄⠀⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠏⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠧⠍⠶⠤⠈⣆⠀⠀⠀⠀⠀⠀⠀⣷⡻⠀⣼⠀⠀⠀")
    print("⣯⣨⡀⢀⡠⠤⣐⠤⣀⣰⠔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⠐⠐⠢⠺⠥⡾⠉⡠⠀⠀⠀")
    print("⠋⠙⠈⠉⠉⠁⠈⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀")
    print("⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀")
    print("⠀⠀⠇⣣⡁⢶⣠⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢶⠀⡶⣲⠀⣆⡒⣰⠒⢦⢰⠀⢰⡆⣴⠐⣶⠒⣐⣒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣺⣿⣿⣿⠛")
    print("⠀⠀⠑⢌⠻⣗⣔⠉⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⠚⠃⠻⠴⠃⠦⠝⠘⠤⠎⠸⠤⠘⠧⠞⠀⠛⠀⠰⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⣾⣿⣿⣿⠃⠀")
    print("⠀⠀⠀⠀⠉⠢⠁⠀⠀⠀⠀⢀⣤⣤⣤⣄⠀⠀⢠⣤⠀⠀⣤⣄⠀⠀⠀⣤⣤⠀⢠⣤⣤⣤⣤⣤⡄⢠⣤⣄⠀⠀⠀⠀⣤⣤⡄⠀⠀⠀⢠⣤⡄⠀⠀⠀⢘⡮⡝⣿⣿⡿⢆⠁⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠏⠉⠉⢿⣷⠀⢸⣿⠀⠠⣿⣿⣧⡀⠀⣿⣿⠀⢸⣿⡏⠉⠉⠉⠁⢼⣿⣿⡄⠀⠀⢸⡿⣿⡇⠀⠀⢀⣿⢻⣷⠀⠀⠀⠞⡜⣹⣿⣿⡙⢆⠀⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⢸⣿⠀⠐⣿⡯⢻⣷⡀⣿⣿⠀⢸⣿⣷⣶⣶⡆⠀⢺⣿⠹⣿⡀⢠⣿⠃⣿⡇⠀⠀⣾⡟⠀⢿⣧⠀⠀⠀⠠⢽⣿⣯⡙⠀⠀⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⡀⠀⠀⣠⣤⠀⢸⣿⠀⢈⣿⡧⠀⠹⣿⣿⣿⠀⢸⣿⡇⠀⠀⠀⠀⢸⣿⡄⢻⣧⣾⡏⢠⣿⡇⠀⣼⣿⣷⣶⣾⣿⣇⠀⠀⠀⠘⣿⢣⠜⠁⠀⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣶⣾⣿⠏⠀⢸⣿⠀⠀⣿⡷⠀⠀⠹⣿⣿⠀⢸⣿⣿⣿⣿⣿⡆⢸⣿⡆⠀⢿⡿⠀⢰⣿⡇⢀⣿⡏⠀⠀⠀⢹⣿⡀⠀⠀⠀⠀⠈⡆⠀⠀⠀")
    print("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠈⠉⠀⠀⠉⠁⠀⠀⠀⠉⠉⠀⠈⠉⠉⠈⠉⠉⠁⠈⠉⠀⠀⠈⠁⠀⠀⠉⠁⠈⠉⠀⠀⠀⠀⠈⠉⠁⠐⡀⠀⠀⠀⠀⠀⠀⠀")


def main():
    # a list of absolute cinema film genres
    genres = [
    "action", "comedy", "drama", "horror", "romance", "sci-fi", "thriller", "documentary",
    "animation", "adventure", "fantasy", "mystery", "musical", "western", "crime", "biography",
    "family", "war", "sport", "history", "news", "reality", "talk show", "game show", "variety",
    "short", "experimental", "silent", "cult", "classic", "independent", "foreign", "art house",
    "avant-garde", "surrealist", "expressionist", "neo-realist", "postmodernist", "new wave", "dogme 95",
    "mockumentary", "found footage", "slasher", "psychological thriller", "superhero", "martial arts",
    "spy", "heist", "disaster", "zombie", "post-apocalyptic", "dystopian", "steampunk", "cyberpunk",
    "space opera", "time travel", "alternate history", "historical fiction", "biographical drama",
    "political thriller", "legal drama", "medical drama", "sports drama", "teen drama", "coming-of-age",
    "road", "buddy", "ensemble cast", "anthology", "experimental narrative", "nonlinear narrative",
    "metafictional", "self-reflexive", "mockumentary style"
    ]
    # a list to store absolute cinema films
    filmList = []

    # print welcome message and menu
    print("====================================================")

    print("       ( )                 (_ )        ( )_        ")
    print("   _ _ | |_     ___    _    | |  _   _ | ,_)   __  ")
    print(" /'_` )| '_`\\ /',__) /'_`\\  | | ( ) ( )| |   /'__`\\")
    print("( (_| || |_) )\\__, \\( (_) ) | | | (_) || |_ (  ___/")
    print("`\\__,_)(_,__/'(____/`\\___/'(___)`\\___/'`\\__)`\\____)")
    print("                                                   ")
    print("   ___ (_)  ___     __    ___ ___     _ _          ")
    print(" /'___)| |/' _ `\\ /'__`\\/' _ ` _ `\\ /'_` )         ")
    print("( (___ | || ( ) |(  ___/| ( ) ( ) |( (_| | _       ")
    print("`\\____)(_)(_) (_)`\\____)(_) (_) (_)`\\__,_)(_)      (python edition.)")

    print("\n====================================================")

    print(" __   __                         __   __ ")
    print("/  ` /  \\  |\\/|  |\\/|  /\\  |\\ | |  \\ /__`")
    print("\\__, \\__/  |  |  |  | /~~\\ | \\| |__/ .__/\n")

    print("1. /add (ADD NEW ABSOLUTE CINEMA FILM)")
    print("2. /display (DISPLAY ALL ABSOLUTE CINEMA FILM)")
    print("3. /update (UPDATE ABSOLUTE CINEMA FILM)")
    print("4. /delete (DELETE ABSOLUTE CINEMA FILM)")
    print("5. /search (SEARCH ABSOLUTE CINEMA FILM)")
    print("6. /??? (HINT: FIRST NAME OF ABSOLUTE CINEMA DIRECTOR)")
    print("7. /exit (EXIT)")

    print("\nenter your command: ")

    # loop to continuously accept user commands
    while True:
        print(">> ", end="")
        # get the command from input
        command = input()

        # call the respective method based on the function
        if command == "/add":
            addFilm(filmList, genres)
        elif command == "/display":
            displayFilms(filmList)
        elif command == "/update":
            updateFilm(filmList, genres)
        elif command == "/delete":
            deleteFilm(filmList)
        elif command == "/search":
            searchFilm(filmList)
        elif command == "/martin":
            absoluteCinema()
        elif command == "/exit":
            print("                          _  _                      ")
            print("                         ( )( )                     ")
            print("   __     _      _      _| || |_    _   _    __     ")
            print(" /'_ `\\ /'_`\\  /'_`\\  /'_` || '_`\\ ( ) ( ) /'__`\\")
            print("( (_) |( (_) )( (_) )( (_| || |_) )| (_) |(  ___/ _ ")
            print("`\\__  |`\\___/'`\\___/'`\\__,_)(_,__/'`\\__, |`\\____)(_)")
            print("( )_) |                            ( )_| |          ")
            print(" \\___/'                            `\\___/'          ")
            sys.exit(0)
        else:
            print("invalid command.\n")


main()
