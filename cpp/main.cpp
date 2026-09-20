#include "CinemaFilm.cpp"

#include <iostream> // library for input and output
#include <string> // library for string
#include <vector> // library for list/dynamic arrays
#include <regex> // library for regular expressions
#include <algorithm> // library for array manipulation
#include <stdexcept> // library for exception handling

// namespace for standard library for simpler syntax
using namespace std;

// function declarations
void displayFilms(vector<CinemaFilm>& filmList);
void addFilm(vector<CinemaFilm>& filmList, const vector<string>& genres);
void updateFilm(vector<CinemaFilm>& filmList, const vector<string>& genres);
void deleteFilm(vector<CinemaFilm>& filmList);
void searchFilm(vector<CinemaFilm>& filmList);
void absoluteCinema();

int main() {
    // an array of absolute cinema film genres
    const vector<string> genres = {
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
    };
    // a dynamic array to store absolute cinema films
    vector<CinemaFilm> filmList;

    // print welcome message and menu
    cout << "====================================================\n";

    cout << "       ( )                 (_ )        ( )_        " << '\n';
    cout << "   _ _ | |_     ___    _    | |  _   _ | ,_)   __  " << '\n';
    cout << " /'_` )| '_`\\ /',__) /'_`\\  | | ( ) ( )| |   /'__`\\" << '\n';
    cout << "( (_| || |_) )\\__, \\( (_) ) | | | (_) || |_ (  ___/" << '\n';
    cout << "`\\__,_)(_,__/'(____/`\\___/'(___)`\\___/'`\\__)`\\____)" << '\n';
    cout << "                                                   " << '\n';
    cout << "   ___ (_)  ___     __    ___ ___     _ _          " << '\n';
    cout << " /'___)| |/' _ `\\ /'__`\\/' _ ` _ `\\ /'_` )         " << '\n';
    cout << "( (___ | || ( ) |(  ___/| ( ) ( ) |( (_| | _       " << '\n';
    cout << "`\\____)(_)(_) (_)`\\____)(_) (_) (_)`\\__,_)(_)      " << '\n';

    cout << "\n====================================================" << '\n';

    cout << "__   __                         __   __ " << '\n';
    cout << "/  ` /  \\  |\\/|  |\\/|  /\\  |\\ | |  \\ /__`" << '\n';
    cout << "\\__, \\__/  |  |  |  | /~~\\ | \\| |__/ .__/\n\n";

    cout << "1. /add (ADD NEW ABSOLUTE CINEMA FILM)" << '\n';
    cout << "2. /display (DISPLAY ALL ABSOLUTE CINEMA FILM)" << '\n';
    cout << "3. /update (UPDATE ABSOLUTE CINEMA FILM)" << '\n';
    cout << "4. /delete (DELETE ABSOLUTE CINEMA FILM)" << '\n';
    cout << "5. /search (SEARCH ABSOLUTE CINEMA FILM)" << '\n';
    cout << "6. /??? (HINT: FIRST NAME OF ABSOLUTE CINEMA DIRECTOR)" << '\n';
    cout << "7. /exit (EXIT)" << '\n';

    cout << "\nenter your command: " << '\n';

    // loop to continuously accept user commands
    while (true) {
        cout << ">> ";
        // get the command from input
        string command;
        getline(cin, command);

        // call the respective method based on the function
        if (command == "/add") {
            addFilm(filmList, genres);
        } 
        else if (command == "/display") {
            displayFilms(filmList);
        } 
        else if (command == "/update") {
            updateFilm(filmList, genres);
        } 
        else if (command == "/delete") {
            deleteFilm(filmList);
        } 
        else if (command == "/search") {
            searchFilm(filmList);
        } 
        else if (command == "/martin") {
            absoluteCinema();
        } 
        else if (command == "/exit") {
            cout << "                          _  _                      " << '\n';
            cout << "                         ( )( )                     " << '\n';
            cout << "   __     _      _      _| || |_    _   _    __     " << '\n';
            cout << " /'_ `\\ /'_`\\  /'_`\\  /'_` || '_`\\ ( ) ( ) /'__`\\" << '\n';
            cout << "( (_) |( (_) )( (_) )( (_| || |_) )| (_) |(  ___/ _ " << '\n';
            cout << "`\\__  |`\\___/'`\\___/'`\\__,_)(_,__/'`\\__, |`\\____)(_)" << '\n';
            cout << "( )_) |                            ( )_| |          " << '\n';
            cout << " \\___/'                            `\\___/'          " << '\n';
            exit(0);
        } 
        else {
            cout << "\ninvalid command.\n";
        }
    }

    return 0;
}

// function to display all films
void displayFilms(vector<CinemaFilm>& filmList) {
    // error handling if the film list is empty
        if (filmList.empty()) {
            cout << "non absolute cinema. no film.\n\n";
            return;
        }

        // print all films numbered
        cout << "\nabsolute cinema. list of films:";
        int filmNumber = 1;
        cout<< '\n' << "-----------------------------" << '\n';
        for (CinemaFilm& film : filmList) {
            cout << filmNumber++ << ". [ " << film.getFilmTitle() << " ]" << '\n';
            cout << "     code: " << film.getFilmCode() << '\n';
            cout << "     genre: " << film.getFilmGenre() << '\n';
            cout << "     duration: " << film.getFilmDuration() << " minutes" << '\n';
            cout << "     ticket price: $" << film.getTicketPrice() << '\n';
            cout << "     rating: " << film.getFilmRating() << "/10" << '\n';
            cout << "-----------------------------" << '\n';
        }

        // print total films
        cout << "total absolute cinema films: " << filmList.size() << "\n\n";
    }

// function to add new film
void addFilm(vector<CinemaFilm>& filmList, const vector<string>& genres) {
        // ask user for film code
        cout << "\ncode: ";
        // read film code
        string code;
        getline(cin, code);
        // error handling for film code format
        while (true) {
            if (!regex_match(code, regex("^CF\\d{3}$"))) {
                cout << "non absolute cinema. invalid code. format must be CF000.\n\n";
            }
            else {
                bool codeExists = false;
                for (CinemaFilm& film : filmList) {
                    if (film.getFilmCode() == code) {
                        codeExists = true;
                        break;
                    }
                }

                if (!codeExists) {
                    break;
                }

                cout << "non absolute cinema. film code already exists. please enter a different code.\n\n";
            }

            cout << "code: ";
            getline(cin, code);
        }

        // ask and read film title
        cout << "title: ";
        string title;
        getline(cin, title);

        // ask and read film genre
        cout << "genre: ";
        string genre;
        getline(cin, genre);
        // error handling for film genre if the genre is not in the list
        while (find(genres.begin(), genres.end(), genre) == genres.end()) {
            cout << "non absolute cinema. invalid genre. please enter a valid genre from this list: [";
            for (size_t i = 0; i < genres.size(); ++i) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << genres[i];
            }
            cout << "]\n\n";
            cout << "genre: ";
            getline(cin, genre);
        }
        genre = genre;

        // ask for duration
        cout << "duration (minutes): ";
        int duration;
        while (true) {
            // input the duration as string
            string durationInput;
            getline(cin, durationInput);
            durationInput = durationInput.substr(0, durationInput.find_last_not_of(" \t\r\n") + 1);
            // error handling if number is decimal
            if (regex_match(durationInput, regex("^-?\\d+\\.\\d+$"))) {
                cout << "non absolute cinema. invalid duration. no decimal numbers allowed.\n";
            } 
            else {
                // error handling if duration is not a number
                try {
                    duration = stoi(durationInput);
                    // error handling if duration is negative
                    if (duration < 0) {
                        cout << "non absolute cinema. invalid duration. negative numbers are not allowed.";
                    } 
                    // error handling if duration is more than 873 minutes
                    else if (duration > 873) {
                        cout << "non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.";
                    } 
                    else {
                        break;
                    }
                } 
                catch (const invalid_argument&) {
                    cout << "non absolute cinema. invalid duration. input is not a valid number.";
                } 
                catch (const out_of_range&) {
                    cout << "non absolute cinema. invalid duration. input is not a valid number.";
                }
                cout << "\n";
            }
            // keep asking for duration until valid
            cout << "\n";
            cout << "duration (minutes): ";
        }

        // ask for ticket price
        cout << "ticket price (us dollars): ";
        int ticketPrice;
        while (true) {
            // input the ticket price as string
            string ticketPriceInput;
            getline(cin, ticketPriceInput);
            ticketPriceInput = ticketPriceInput.substr(0, ticketPriceInput.find_last_not_of(" \t\r\n") + 1);
            // error handling if number is decimal
            if (regex_match(ticketPriceInput, regex("^-?\\d+\\.\\d+$"))) {
                cout << "non absolute cinema. invalid ticket price. no decimal numbers allowed.\n";
            } 
            else {
                // error handling if ticket price is not a number
                try {
                    ticketPrice = stoi(ticketPriceInput);
                    // error handling if ticket price is negative
                    if (ticketPrice < 0) {
                        cout << "non absolute cinema. invalid ticket price. negative numbers are not allowed.";
                    } 
                    // error handling if ticket price is more than 500 dollars
                    else if (ticketPrice > 500) {
                        cout << "non absolute cinema. invalid ticket price. the maximum ticket price is 500 dollars.";
                    } 
                    else {
                        break;
                    }
                } 
                catch (const invalid_argument&) {
                    cout << "non absolute cinema. invalid ticket price. input is not a valid number.";
                } 
                catch (const out_of_range&) {
                    cout << "non absolute cinema. invalid ticket price. input is not a valid number.";
                }
                cout << "\n";
            }
            // keep asking for ticket price until valid
            cout << "\n";
            cout << "ticket price (us dollars): ";
        }

        // ask for rating
        cout << "rating (out of 10): ";
        int rating;
        while (true) {
            // input the rating as string
            string ratingInput;
            getline(cin, ratingInput);
            ratingInput = ratingInput.substr(0, ratingInput.find_last_not_of(" \t\r\n") + 1);
            // error handling if number is decimal
            if (regex_match(ratingInput, regex("^-?\\d+\\.\\d+$"))) {
                cout << "non absolute cinema. invalid rating. no decimal numbers allowed.\n";
            } 
            else {
                // error handling if rating is not a number
                try {
                    rating = stoi(ratingInput);
                    // error handling if rating is negative
                    if (rating < 0) {
                        cout << "non absolute cinema. invalid rating. negative numbers are not allowed.";
                    } 
                    // error handling if rating is more than 10
                    else if (rating > 10) {
                        cout << "non absolute cinema. invalid rating. the maximum rating is 10.";
                    } 
                    else {
                        break;
                    }
                } 
                catch (const invalid_argument&) {
                    cout << "non absolute cinema. invalid rating. input is not a valid number.";
                } 
                catch (const out_of_range&) {
                    cout << "non absolute cinema. invalid rating. input is not a valid number.";
                }
                cout << "\n";
            }
            // keep asking for rating until valid
            cout << "\n";
            cout << "rating (out of 10): ";
        }

        // instantiate a new CinemaFilm object from user input
        CinemaFilm newFilm(code, title, genre, duration, ticketPrice, rating);
        // add it to the list
        filmList.push_back(newFilm);
        // print success message
        cout << "absolute cinema. new film has been added.\n\n";
    }

// function to update film
void updateFilm(vector<CinemaFilm>& filmList, const vector<string>& genres) {
        // ask user for film code to update
        cout << "\nenter film code to update: ";
        // read film code
        string filmCode;
        getline(cin, filmCode);

        // find the film with the given code
        for (CinemaFilm& film : filmList) {
            if (film.getFilmCode() == filmCode) {
                // ask and read new film code
                cout << "new code: ";
                string newCode;
                getline(cin, newCode);
                // error handling for film code format
                while (true) {
                    if (!regex_match(newCode, regex("^CF\\d{3}$"))) {
                        cout << "non absolute cinema. invalid code. format must be CF000.\n\n";
                    }
                    else {
                        bool codeExists = false;
                        for (CinemaFilm& otherFilm : filmList) {
                            if (&otherFilm != &film && otherFilm.getFilmCode() == newCode) {
                                codeExists = true;
                                break;
                            }
                        }

                        if (!codeExists) {
                            break;
                        }

                        cout << "non absolute cinema. film code already exists. please enter a different code.\n\n";
                    }

                    cout << "new code: ";
                    getline(cin, newCode);
                }
                // update the film's code using setter method
                film.setFilmCode(newCode);

                // ask and read new film title
                cout << "new title: ";
                string newTitle;
                getline(cin, newTitle);
                // update the film's title using setter method
                film.setFilmTitle(newTitle);

                // ask and read new film genre
                cout << "new genre: ";
                string newGenre;
                getline(cin, newGenre);
                // error handling for film genre if the genre is not in the list
                while (find(genres.begin(), genres.end(), newGenre) == genres.end()) {
                    cout << "non absolute cinema. invalid genre. please enter a valid genre from this list: [";
                    for (size_t i = 0; i < genres.size(); ++i) {
                        if (i > 0) {
                            cout << ", ";
                        }
                        cout << genres[i];
                    }
                    cout << "]\n";
                    cout << "new genre: ";
                    getline(cin, newGenre);
                }
                // update the film's genre using setter method
                film.setFilmGenre(newGenre);

                // ask for new duration
                cout << "new duration (minutes): ";
                int newDuration;
                while (true) {
                    // input the duration as string
                    string durationInput;
                    getline(cin, durationInput);
                    durationInput = durationInput.substr(0, durationInput.find_last_not_of(" \t\r\n") + 1);
                    // error handling if number is decimal
                    if (regex_match(durationInput, regex("^-?\\d+\\.\\d+$"))) {
                        cout << "non absolute cinema. invalid duration. no decimal numbers allowed.\n";
                    } 
                    else {
                        // error handling if duration is not a number
                        try {
                            newDuration = stoi(durationInput);
                            // error handling if duration is negative
                            if (newDuration < 0) {
                                cout << "non absolute cinema. invalid duration. negative numbers are not allowed.";
                            } 
                            // error handling if duration is more than 873 minutes
                            else if (newDuration > 873) {
                                cout << "non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.";
                            } 
                            else {
                                break;
                            }
                        } 
                        catch (const invalid_argument&) {
                            cout << "non absolute cinema. invalid duration. input is not a valid number.";
                        } 
                        catch (const out_of_range&) {
                            cout << "non absolute cinema. invalid duration. input is not a valid number.";
                        }
                        cout << "\n";
                    }
                    // keep asking for duration until valid
                    cout << "\n";
                    cout << "new duration (minutes): ";
                }
                // update the film's duration using setter method
                film.setFilmDuration(newDuration);

                // ask for new ticket price
                cout << "new ticket price (us dollars): ";
                int newTicketPrice;
                while (true) {
                    // input the ticket price as string
                    string newTicketPriceInput;
                    getline(cin, newTicketPriceInput);
                    newTicketPriceInput = newTicketPriceInput.substr(0, newTicketPriceInput.find_last_not_of(" \t\r\n") + 1);
                    // error handling if number is decimal
                    if (regex_match(newTicketPriceInput, regex("^-?\\d+\\.\\d+$"))) {
                        cout << "non absolute cinema. invalid ticket price. no decimal numbers allowed.\n";
                    } 
                    else {
                        // error handling if ticket price is not a number
                        try {
                            newTicketPrice = stoi(newTicketPriceInput);
                            // error handling if ticket price is negative
                            if (newTicketPrice < 0) {
                                cout << "non absolute cinema. invalid ticket price. negative numbers are not allowed.";
                            } 
                            // error handling if ticket price is more than 500 dollars
                            else if (newTicketPrice > 500) {
                                cout << "non absolute cinema. invalid ticket price. the maximum ticket price is 500 dollars.";
                            } 
                            else {
                                break;
                            }
                        } 
                        catch (const invalid_argument&) {
                            cout << "non absolute cinema. invalid ticket price. input is not a valid number.";
                        } 
                        catch (const out_of_range&) {
                            cout << "non absolute cinema. invalid ticket price. input is not a valid number.";
                        }
                        cout << "\n";
                    }
                    // keep asking for ticket price until valid
                    cout << "\n";
                    cout << "new ticket price (us dollars): ";
                }
                // update the film's ticket price using setter method
                film.setTicketPrice(newTicketPrice);

                // ask for new rating
                cout << "new rating (out of 10): ";
                int newRating;
                while (true) {
                    // input the rating as string
                    string newRatingInput;
                    getline(cin, newRatingInput);
                    newRatingInput = newRatingInput.substr(0, newRatingInput.find_last_not_of(" \t\r\n") + 1);
                    // error handling if number is decimal
                    if (regex_match(newRatingInput, regex("^-?\\d+\\.\\d+$"))) {
                        cout << "non absolute cinema. invalid rating. no decimal numbers allowed.\n";
                    } 
                    else {
                        // error handling if rating is not a number
                        try {
                            newRating = stoi(newRatingInput);
                            // error handling if rating is negative
                            if (newRating < 0) {
                                cout << "non absolute cinema. invalid rating. negative numbers are not allowed.";
                            } 
                            // error handling if rating is more than 10
                            else if (newRating > 10) {
                                cout << "non absolute cinema. invalid rating. the maximum rating is 10.";
                            } 
                            else {
                                break;
                            }
                        } 
                        catch (const invalid_argument&) {
                            cout << "non absolute cinema. invalid rating. input is not a valid number.";
                        } 
                        catch (const out_of_range&) {
                            cout << "non absolute cinema. invalid rating. input is not a valid number.";
                        }
                        cout << "\n";
                    }
                    // keep asking for rating until valid
                    cout << "\n";
                    cout << "new rating (out of 10): ";
                }
                // update the film's rating using setter method
                film.setFilmRating(newRating);

                cout << "absolute cinema. film has been updated.\n\n";
                return;
            }
        }

        // error handling if the film code is not found
        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

// function to delete film
void deleteFilm(vector<CinemaFilm>& filmList) {
        // ask for film code to delete
        cout << "\nenter film code to delete: ";
        // read film code
        string filmCode;
        getline(cin, filmCode);

        // find film code in list
        for (auto it = filmList.begin(); it != filmList.end(); ++it) {
            if (it->getFilmCode() == filmCode) {
                // if found
                // remove film from list
                filmList.erase(it);
                cout << "absolute cinema. film has been deleted.\n\n";
                return;
            }
        }
        // error handling if the film code is not found
        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

// function to search film
void searchFilm(vector<CinemaFilm>& filmList) {
        // ask for film code to search
        cout << "\nenter film code to search: ";
        // read film code
        string filmCode;
        getline(cin, filmCode);

        // find film code in list
        for (CinemaFilm& film : filmList) {
            if (film.getFilmCode() == filmCode) {
                // if found
                // print film details
                cout << "absolute cinema. film found:";
                cout << '\n' << "-----------------------------" << '\n';
                cout << "[ " << film.getFilmTitle() << " ]" << '\n';
                cout << "  code: " << film.getFilmCode() << '\n';
                cout << "  genre: " << film.getFilmGenre() << '\n';
                cout << "  duration: " << film.getFilmDuration() << " minutes" << '\n';
                cout << "  ticket price: $" << film.getTicketPrice() << '\n';
                cout << "  rating: " << film.getFilmRating() << "/10" << '\n';
                cout << "-----------------------------\n\n";
                return;
            }
        }
        // error handling if the film code is not found
        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

// SUPER SECRET ABSOLUTE CINEMA FUNCTION (DO NOT CALL THIS FUNCTION UNLESS YOU ARE ABSOLUTELY SURE)
void absoluteCinema() {
        cout << "⠀⠀⢀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
        cout << "⢀⠀⣿⡂⢹⡇⠀⠀⣰⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
        cout << "⢸⡇⢸⣇⢸⣇⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⠀⠀⣯⡀⡆⠀⠀" << '\n';
        cout << "⢸⣷⢸⣇⣸⣇⠀⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⣂⠀⣿⡄⢸⡀⣤" << '\n';
        cout << "⢠⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣊⡝⠛⠙⠂⠄⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣦⣼⣷⣼⣁⠼" << '\n';
        cout << "⢸⣿⣿⣿⣿⣿⣿⣀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⡻⣥⢋⡔⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣂⣜⣿⡟⢿⣿⣿⣄" << '\n';
        cout << "⠈⣿⣿⣿⣿⣿⣿⣿⠿⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣷⢯⣿⣾⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢪⣷⣿⢿⣿⣿" << '\n';
        cout << "⠀⣿⣿⣟⢿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⡟⠛⠉⡉⢸⡉⠁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣽⣗⣿⠇" << '\n';
        cout << "⠀⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠺⣿⡇⣤⡤⢔⡿⣇⠀⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣯⠀" << '\n';
        cout << "⠘⡟⣛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⣿⣿⠗⡲⠏⠟⠿⠀⠈⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠍⠁⠁⠀" << '\n';
        cout << "⠃⡜⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣼⣿⡟⢡⡿⠿⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⠒⠂⠂" << '\n';
        cout << "⠐⢐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠸⣡⢶⣿⣟⡃⠀⠘⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⡀⠀" << '\n';
        cout << "⢠⡏⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡰⢨⠣⠉⠉⠋⠉⠀⠀⠀⠀⢈⠀⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡿⠀⠀⠀⠀" << '\n';
        cout << "⢺⡇⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⡿⢛⢭⠏⣢⠍⠈⠖⠀⠀⠒⣶⢦⡁⠂⠀⠀⠀⠀⠀⠯⠤⣤⣴⢶⣍⠝⣯⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢌⣿⠱⠀⠀⠀⠀⠀" << '\n';
        cout << "⣯⣯⠸⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠄⠀⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠏⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠧⠍⠶⠤⠈⣆⠀⠀⠀⠀⠀⠀⠀⣷⡻⠀⣼⠀⠀⠀" << '\n';
        cout << "⣯⣨⡀⢀⡠⠤⣐⠤⣀⣰⠔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⠐⠐⠢⠺⠥⡾⠉⡠⠀⠀⠀" << '\n';
        cout << "⠋⠙⠈⠉⠉⠁⠈⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
        cout << "⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
        cout << "⠀⠀⠇⣣⡁⢶⣠⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢶⠀⡶⣲⠀⣆⡒⣰⠒⢦⢰⠀⢰⡆⣴⠐⣶⠒⣐⣒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣺⣿⣿⣿⠛" << '\n';
        cout << "⠀⠀⠑⢌⠻⣗⣔⠉⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⠚⠃⠻⠴⠃⠦⠝⠘⠤⠎⠸⠤⠘⠧⠞⠀⠛⠀⠰⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⣾⣿⣿⣿⠃⠀" << '\n';
        cout << "⠀⠀⠀⠀⠉⠢⠁⠀⠀⠀⠀⢀⣤⣤⣤⣄⠀⠀⢠⣤⠀⠀⣤⣄⠀⠀⠀⣤⣤⠀⢠⣤⣤⣤⣤⣤⡄⢠⣤⣄⠀⠀⠀⠀⣤⣤⡄⠀⠀⠀⢠⣤⡄⠀⠀⠀⢘⡮⡝⣿⣿⡿⢆⠁⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠏⠉⠉⢿⣷⠀⢸⣿⠀⠠⣿⣿⣧⡀⠀⣿⣿⠀⢸⣿⡏⠉⠉⠉⠁⢼⣿⣿⡄⠀⠀⢸⡿⣿⡇⠀⠀⢀⣿⢻⣷⠀⠀⠀⠞⡜⣹⣿⣿⡙⢆⠀⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⢸⣿⠀⠐⣿⡯⢻⣷⡀⣿⣿⠀⢸⣿⣷⣶⣶⡆⠀⢺⣿⠹⣿⡀⢠⣿⠃⣿⡇⠀⠀⣾⡟⠀⢿⣧⠀⠀⠀⠠⢽⣿⣯⡙⠀⠀⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⡀⠀⠀⣠⣤⠀⢸⣿⠀⢈⣿⡧⠀⠹⣿⣿⣿⠀⢸⣿⡇⠀⠀⠀⠀⢸⣿⡄⢻⣧⣾⡏⢠⣿⡇⠀⣼⣿⣷⣶⣾⣿⣇⠀⠀⠀⠘⣿⢣⠜⠁⠀⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣶⣾⣿⠏⠀⢸⣿⠀⠀⣿⡷⠀⠀⠹⣿⣿⠀⢸⣿⣿⣿⣿⣿⡆⢸⣿⡆⠀⢿⡿⠀⢰⣿⡇⢀⣿⡏⠀⠀⠀⢹⣿⡀⠀⠀⠀⠀⠈⡆⠀⠀⠀" << '\n';
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠈⠉⠀⠀⠉⠁⠀⠀⠀⠉⠉⠀⠈⠉⠉⠈⠉⠉⠁⠈⠉⠀⠀⠈⠁⠀⠀⠉⠁⠈⠉⠀⠀⠀⠀⠈⠉⠁⠐⡀⠀⠀⠀⠀⠀⠀⠀\n\n";
}
