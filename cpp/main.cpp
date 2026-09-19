#include "CinemaFilm.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Main {
private:
    static const vector<string> genres;

public:
    static void displayFilms(vector<CinemaFilm>& filmList) {
        if (filmList.empty()) {
            cout << "non absolute cinema. no film.\n\n";
            return;
        }

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

        cout << "total absolute cinema films: " << filmList.size() << "\n\n";
    }

    static void addFilm(vector<CinemaFilm>& filmList) {
        cout << "\ncode: ";
        string code;
        getline(cin, code);
        while (!regex_match(code, regex("^CF\\d{3}$"))) {
            cout << "non absolute cinema. invalid code. format must be CF000.\n";
            cout << "code: ";
            getline(cin, code);
        }

        cout << "title: ";
        string title;
        getline(cin, title);

        cout << "genre: ";
        string genre;
        getline(cin, genre);
        while (find(genres.begin(), genres.end(), genre) == genres.end()) {
            cout << "non absolute cinema. invalid genre. please enter a valid genre from this list: [";
            for (size_t i = 0; i < genres.size(); ++i) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << genres[i];
            }
            cout << "]\n";
            cout << "genre: ";
            getline(cin, genre);
        }
        genre = genre;

        cout << "duration (minutes): ";
        int duration;
        while (true) {
            string durationInput;
            getline(cin, durationInput);
            durationInput = durationInput.substr(0, durationInput.find_last_not_of(" \t\r\n") + 1);
            if (regex_match(durationInput, regex("^-?\\d+\\.\\d+$"))) {
                cout << "non absolute cinema. invalid duration. no decimal numbers allowed.\n";
            } else {
                try {
                    duration = stoi(durationInput);
                    if (duration < 0) {
                        cout << "non absolute cinema. invalid duration. negative numbers are not allowed.";
                    } else if (duration > 873) {
                        cout << "non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.";
                    } else {
                        break;
                    }
                } catch (const invalid_argument&) {
                    cout << "non absolute cinema. invalid duration. input is not a valid number.";
                } catch (const out_of_range&) {
                    cout << "non absolute cinema. invalid duration. input is not a valid number.";
                }
                cout << "\n";
            }
            cout << "\n";
            cout << "duration (minutes): ";
        }

        cout << "ticket price (us dollars): ";
        int ticketPrice;
        string ticketPriceInput;
        getline(cin, ticketPriceInput);
        ticketPrice = stoi(ticketPriceInput);

        cout << "rating (out of 10): ";
        int rating;
        string ratingInput;
        getline(cin, ratingInput);
        rating = stoi(ratingInput);

        CinemaFilm newFilm(code, title, genre, duration, ticketPrice, rating);
        filmList.push_back(newFilm);
        cout << "absolute cinema. new film has been added.\n\n";
    }

    static void updateFilm(vector<CinemaFilm>& filmList) {
        cout << "\nenter film code to update: ";
        string filmCode;
        getline(cin, filmCode);

        for (CinemaFilm& film : filmList) {
            if (film.getFilmCode() == filmCode) {
                cout << "new code: ";
                string newCode;
                getline(cin, newCode);
                while (!regex_match(newCode, regex("^CF\\d{3}$"))) {
                    cout << "non absolute cinema. invalid code. format must be CF000.\n";
                    cout << "new code: ";
                    getline(cin, newCode);
                }
                film.setFilmCode(newCode);

                cout << "new title: ";
                string newTitle;
                getline(cin, newTitle);
                film.setFilmTitle(newTitle);

                cout << "new genre: ";
                string newGenre;
                getline(cin, newGenre);
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
                film.setFilmGenre(newGenre);

                cout << "new duration (minutes): ";
                int newDuration;
                while (true) {
                    string durationInput;
                    getline(cin, durationInput);
                    durationInput = durationInput.substr(0, durationInput.find_last_not_of(" \t\r\n") + 1);
                    if (regex_match(durationInput, regex("^-?\\d+\\.\\d+$"))) {
                        cout << "non absolute cinema. invalid duration. no decimal numbers allowed.\n";
                    } else {
                        try {
                            newDuration = stoi(durationInput);
                            if (newDuration < 0) {
                                cout << "non absolute cinema. invalid duration. negative numbers are not allowed.";
                            } else if (newDuration > 873) {
                                cout << "non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.";
                            } else {
                                break;
                            }
                        } catch (const invalid_argument&) {
                            cout << "non absolute cinema. invalid duration. input is not a valid number.";
                        } catch (const out_of_range&) {
                            cout << "non absolute cinema. invalid duration. input is not a valid number.";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                    cout << "new duration (minutes): ";
                }
                film.setFilmDuration(newDuration);

                cout << "new ticket price (us dollars): ";
                string newTicketPriceInput;
                getline(cin, newTicketPriceInput);
                film.setTicketPrice(stoi(newTicketPriceInput));

                cout << "new rating (out of 10): ";
                string newRatingInput;
                getline(cin, newRatingInput);
                film.setFilmRating(stoi(newRatingInput));

                cout << "absolute cinema. film has been updated.\n\n";
                return;
            }
        }

        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

    static void deleteFilm(vector<CinemaFilm>& filmList) {
        cout << "\nenter film code to delete: ";
        string filmCode;
        getline(cin, filmCode);

        for (auto it = filmList.begin(); it != filmList.end(); ++it) {
            if (it->getFilmCode() == filmCode) {
                filmList.erase(it);
                cout << "absolute cinema. film has been deleted.\n\n";
                return;
            }
        }
        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

    static void searchFilm(vector<CinemaFilm>& filmList) {
        cout << "\nenter film code to search: ";
        string filmCode;
        getline(cin, filmCode);

        for (CinemaFilm& film : filmList) {
            if (film.getFilmCode() == filmCode) {
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
        cout << "non absolute cinema. film with code " << filmCode << " was not found.\n\n";
    }

    static void absoluteCinema() {
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
};

const vector<string> Main::genres = {
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

class Scanner {
public:
    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }
};

int main() {
    vector<CinemaFilm> filmList;
    Scanner scanner;

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
    while (true) {
        cout << ">> ";
        string command;
        getline(cin, command);

        if (command == "/add") {
            Main::addFilm(filmList);
        } else if (command == "/display") {
            Main::displayFilms(filmList);
        } else if (command == "/update") {
            Main::updateFilm(filmList);
        } else if (command == "/delete") {
            Main::deleteFilm(filmList);
        } else if (command == "/search") {
            Main::searchFilm(filmList);
        } else if (command == "/martin") {
            Main::absoluteCinema();
        } else if (command == "/exit") {
            cout << "                          _  _                      " << '\n';
            cout << "                         ( )( )                     " << '\n';
            cout << "   __     _      _      _| || |_    _   _    __     " << '\n';
            cout << " /'_ `\\ /'_`\\  /'_`\\  /'_` || '_`\\ ( ) ( ) /'__`\\" << '\n';
            cout << "( (_) |( (_) )( (_) )( (_| || |_) )| (_) |(  ___/ _ " << '\n';
            cout << "`\\__  |`\\___/'`\\___/'`\\__,_)(_,__/'`\\__, |`\\____)(_)" << '\n';
            cout << "( )_) |                            ( )_| |          " << '\n';
            cout << " \\___/'                            `\\___/'          " << '\n';
            exit(0);
        } else {
            cout << "\ninvalid command.\n";
        }
    }

    return 0;
}
