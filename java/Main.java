import java.util.ArrayList; // a utility class for dynamic arrays
import java.util.Arrays; // a utility class for array manipulation
import java.util.Scanner; // a utility class for user input

public class Main {
    // an array of absolute cinema film genres
    private static final String[] genres = {
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

    public static void main(String[] args) {
        // a dynamic array to store absolute cinema films
        ArrayList<CinemaFilm> filmList = new ArrayList<>();
        // a scanner for input
        Scanner scanner = new Scanner(System.in);
        
        // print welcome message and menu
        System.out.println("====================================================\n");

        System.out.println("       ( )                 (_ )        ( )_        ");
        System.out.println("   _ _ | |_     ___    _    | |  _   _ | ,_)   __  ");
        System.out.println(" /'_` )| '_`\\ /',__) /'_`\\  | | ( ) ( )| |   /'__`\\");
        System.out.println("( (_| || |_) )\\__, \\( (_) ) | | | (_) || |_ (  ___/");
        System.out.println("`\\__,_)(_,__/'(____/`\\___/'(___)`\\___/'`\\__)`\\____)");
        System.out.println("                                                   ");
        System.out.println("   ___ (_)  ___     __    ___ ___     _ _          ");
        System.out.println(" /'___)| |/' _ `\\ /'__`\\/' _ ` _ `\\ /'_` )         ");
        System.out.println("( (___ | || ( ) |(  ___/| ( ) ( ) |( (_| | _       ");
        System.out.println("`\\____)(_)(_) (_)`\\____)(_) (_) (_)`\\__,_)(_)      (java edition.)");

        System.out.println("\n====================================================");

        System.out.println(" __   __                         __   __ ");
        System.out.println("/  ` /  \\  |\\/|  |\\/|  /\\  |\\ | |  \\ /__`");
        System.out.println("\\__, \\__/  |  |  |  | /~~\\ | \\| |__/ .__/\n");

        System.out.println("1. /add (ADD NEW ABSOLUTE CINEMA FILM)");
        System.out.println("2. /display (DISPLAY ALL ABSOLUTE CINEMA FILM)");
        System.out.println("3. /update (UPDATE ABSOLUTE CINEMA FILM)");
        System.out.println("4. /delete (DELETE ABSOLUTE CINEMA FILM)");
        System.out.println("5. /search (SEARCH ABSOLUTE CINEMA FILM)");
        System.out.println("6. /??? (HINT: FIRST NAME OF ABSOLUTE CINEMA DIRECTOR)");
        System.out.println("7. /exit (EXIT)");

        System.out.println("\nenter your command: ");

        // loop to continuously accept user commands
        while(true) {
            System.out.print(">> ");
            // get the command from input
            String command = scanner.nextLine();

            // call the respective method based on the command
            switch (command) {
                case "/add":
                    addFilm(filmList, scanner);
                    break;
                case "/display":
                    displayFilms(filmList);
                    break;
                case "/update":
                    updateFilm(filmList, scanner);
                    break;
                case "/delete":
                    deleteFilm(filmList, scanner);
                    break;
                case "/search":
                    searchFilm(filmList, scanner);
                    break;
                case "/martin":
                    absoluteCinema();
                    break;
                case "/exit":
                    System.out.println("                          _  _                      ");
                    System.out.println("                         ( )( )                     ");
                    System.out.println("   __     _      _      _| || |_    _   _    __     ");
                    System.out.println(" /'_ `\\ /'_`\\  /'_`\\  /'_` || '_`\\ ( ) ( ) /'__`\\");
                    System.out.println("( (_) |( (_) )( (_) )( (_| || |_) )| (_) |(  ___/ _ ");
                    System.out.println("`\\__  |`\\___/'`\\___/'`\\__,_)(_,__/'`\\__, |`\\____)(_)");
                    System.out.println("( )_) |                            ( )_| |          ");
                    System.out.println(" \\___/'                            `\\___/'          ");
                    System.exit(0);
                default:
                    System.out.println("\ninvalid command.\n");
            }
        }
    }

    // method to display all films
    public static void displayFilms(ArrayList<CinemaFilm> filmList) {
        // error handling if the film list is empty
        if (filmList.isEmpty()) {
            System.out.println("non absolute cinema. no film.\n");
            return;
        }

        // print all films numbered
        System.out.println("\nabsolute cinema. list of films:");
        int filmNumber = 1;
        System.out.println("-----------------------------");
        for (CinemaFilm film : filmList) {
            System.out.println(filmNumber++ + ". [ " + film.getFilmTitle() + " ]");
            System.out.println("     code: " + film.getFilmCode());
            System.out.println("     genre: " + film.getFilmGenre());
            System.out.println("     duration: " + film.getFilmDuration() + " minutes");
            System.out.println("     ticket price: $" + film.getTicketPrice());
            System.out.println("     rating: " + film.getFilmRating() + "/10");
            System.out.println("-----------------------------");
        }

        // print total films
        System.out.println("total absolute cinema films: " + filmList.size() + "\n");
    }

    // method to add new film
    public static void addFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        // ask user for film code
        System.out.print("\ncode: ");
        // read film code
        String code = scanner.nextLine();
        // error handling for film code format and duplicates
        while (true) {
            if (!code.matches("CF\\d{3}")) {
                System.out.println("non absolute cinema. invalid code. format must be CF000.\n");
            }
            else {
                boolean codeExists = false;
                for (CinemaFilm film : filmList) {
                    if (film.getFilmCode().equals(code)) {
                        codeExists = true;
                        break;
                    }
                }

                if (!codeExists) {
                    break;
                }

                System.out.println("non absolute cinema. film code already exists. please enter a different code.\n");
            }

            System.out.print("code: ");
            code = scanner.nextLine();
        }

        // ask and read film title
        System.out.print("title: ");
        String title = scanner.nextLine();
        
        // ask and read film genre
        System.out.print("genre: ");
        String genre = scanner.nextLine();
        // error handling for film genre if the genre is not in the list
        while (!Arrays.asList(genres).contains(genre.trim().toLowerCase())) {
            System.out.println("non absolute cinema. invalid genre. please enter a valid genre from this list: " + Arrays.toString(genres) + "\n");
            System.out.print("genre: ");
            genre = scanner.nextLine();
        }
        genre = genre.trim().toLowerCase();

        // ask for duration
        System.out.print("duration (minutes): ");
        int duration;
        while (true) {
            // input the duration as string
            String durationInput = scanner.nextLine().trim();

            // error handling if number is decimal
            if (durationInput.matches("-?\\d+\\.\\d+")) {
                System.out.println("non absolute cinema. invalid duration. no decimal numbers allowed.\n");
            } 
            else {
                // error handling if duration is not a number
                try {
                    duration = Integer.parseInt(durationInput);
                    // error handling if duration is negative
                    if (duration < 0) {
                        System.out.println("non absolute cinema. invalid duration. negative numbers are not allowed.");
                    } 
                    // error handling if duration is more than 873 minutes
                    else if (duration > 873) {
                        System.out.println("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.");
                    }
                    else {
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("non absolute cinema. invalid duration. input is not a valid number.");
                }
                System.out.print("\n");
            }
            
            // keep asking for duration until valid
            System.out.print("duration (minutes): ");
        }

        // ask for ticket price
        System.out.print("ticket price (us dollars): ");
        int ticketPrice;
        while (true) {
            // input the ticket price as string
            String ticketPriceInput = scanner.nextLine().trim();

            // error handling if number is decimal
            if (ticketPriceInput.matches("-?\\d+\\.\\d+")) {
                System.out.println("non absolute cinema. invalid ticket price. no decimal numbers allowed.\n");
            } 
            else {
                // error handling if ticket price is not a number
                try {
                    ticketPrice = Integer.parseInt(ticketPriceInput);
                    // error handling if ticket price is negative
                    if (ticketPrice < 0) {
                        System.out.println("non absolute cinema. invalid ticket price. negative numbers are not allowed.");
                    } 
                    // error handling if ticket price is more than 500 dollars
                    else if (ticketPrice > 500) {
                        System.out.println("non absolute cinema. ticket price cannot be higher than 500 US dollars. please enter a valid ticket price.");
                    } 
                    else {
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("non absolute cinema. invalid ticket price. input is not a valid number.");
                }
                System.out.print("\n");
            }

            // keep asking for ticket price until valid
            System.out.print("ticket price (us dollars): ");
        }

        // ask for rating
        System.out.print("rating (out of 10): ");
        int rating;
        while (true) {
            // input the rating as string
            String ratingInput = scanner.nextLine().trim();

            // error handling if number is decimal
            if (ratingInput.matches("-?\\d+\\.\\d+")) {
                System.out.println("non absolute cinema. invalid rating. no decimal numbers allowed.\n");
            } 
            else {
                // error handling if rating is not a number
                try {
                    rating = Integer.parseInt(ratingInput);
                    // error handling if rating is negative
                    if (rating < 0) {
                        System.out.println("non absolute cinema. invalid rating. negative numbers are not allowed.");
                    } 
                    // error handling if rating is more than 10
                    else if (rating > 10) {
                        System.out.println("non absolute cinema. rating cannot be higher than 10. please enter a valid rating.");
                    } 
                    else {
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("non absolute cinema. invalid rating. input is not a valid number.");
                }
                System.out.print("\n");
            }

            // keep asking for rating until valid
            System.out.print("rating (out of 10): ");
        }

        // instantiate a new CinemaFilm object from user input
        CinemaFilm newFilm = new CinemaFilm(
            code,
            title,
            genre,
            duration,
            ticketPrice,
            rating
        );

        // add it to the list
        filmList.add(newFilm);
        // print success message
        System.out.println("absolute cinema. new film has been added.\n");
    }

    
    // method to update film
    public static void updateFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        // ask user for film code to update
        System.out.print("\nenter film code to update: ");
        // read film code
        String filmCode = scanner.nextLine();

        // find the film with the given code
        for (CinemaFilm film : filmList) {
            if (film.getFilmCode().equals(filmCode)) {
                // ask and read new film code
                System.out.print("new code: ");
                String newCode = scanner.nextLine();
                // error handling for film code format and duplicates
                while (true) {
                    if (!newCode.matches("CF\\d{3}")) {
                        System.out.println("non absolute cinema. invalid code. format must be CF000.\n");
                    }
                    else {
                        boolean codeExists = false;
                        for (CinemaFilm otherFilm : filmList) {
                            if (otherFilm != film && otherFilm.getFilmCode().equals(newCode)) {
                                codeExists = true;
                                break;
                            }
                        }

                        if (!codeExists) {
                            break;
                        }

                        System.out.println("non absolute cinema. film code already exists. please enter a different code.\n");
                    }

                    System.out.print("new code: ");
                    newCode = scanner.nextLine();
                }

                // update the film's code using setter method
                film.setFilmCode(newCode);

                // ask and read new film title
                System.out.print("new title: ");
                // update the film's title using setter method
                film.setFilmTitle(scanner.nextLine());

                // ask and read new film genre
                System.out.print("new genre: ");
                String newGenre = scanner.nextLine();
                // error handling for film genre if the genre is not in the list
                while (!Arrays.asList(genres).contains(newGenre.trim().toLowerCase())) {
                    System.out.println("non absolute cinema. invalid genre. please enter a valid genre from this list: " + Arrays.toString(genres) + "\n");
                    System.out.print("new genre: ");
                    newGenre = scanner.nextLine();
                }

                // update the film's genre using setter method
                film.setFilmGenre(newGenre.trim().toLowerCase());

                // ask for new duration
                System.out.print("new duration (minutes): ");
                int newDuration;
                while (true) {
                    // input the duration as string
                    String durationInput = scanner.nextLine().trim();

                    // error handling if number is decimal
                    if (durationInput.matches("-?\\d+\\.\\d+")) {
                        System.out.println("non absolute cinema. invalid duration. no decimal numbers allowed.\n");
                    } 
                    else {
                        // error handling if duration is not a number
                        try {
                            newDuration = Integer.parseInt(durationInput);
                            // error handling if duration is negative
                            if (newDuration < 0) {
                                System.out.println("non absolute cinema. invalid duration. negative numbers are not allowed.");
                            } 
                            // error handling if duration is more than 873 minutes
                            else if (newDuration > 873) {
                                System.out.println("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.");
                            } 
                            else {
                                break;
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("non absolute cinema. invalid duration. input is not a valid number.");
                        }
                        System.out.print("\n");
                    }

                    // keep asking for duration until valid
                    System.out.print("new duration (minutes): ");
                }

                // update the film's duration using setter method
                film.setFilmDuration(newDuration);

                // ask for new ticket price
                System.out.print("new ticket price (us dollars): ");
                int newTicketPrice;
                while (true) {
                    // input the ticket price as string
                    String ticketPriceInput = scanner.nextLine().trim();

                    // error handling if number is decimal
                    if (ticketPriceInput.matches("-?\\d+\\.\\d+")) {
                        System.out.println("non absolute cinema. invalid ticket price. no decimal numbers allowed.\n");
                    } 
                    else {
                        // error handling if ticket price is not a number
                        try {
                            newTicketPrice = Integer.parseInt(ticketPriceInput);
                            // error handling if ticket price is negative
                            if (newTicketPrice < 0) {
                                System.out.println("non absolute cinema. invalid ticket price. negative numbers are not allowed.");
                            } 
                            // error handling if ticket price is more than 500 dollars
                            else if (newTicketPrice > 500) {
                                System.out.println("non absolute cinema. ticket price cannot be higher than 500 US dollars. please enter a valid ticket price.");
                            } 
                            else {
                                break;
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("non absolute cinema. invalid ticket price. input is not a valid number.");
                        }
                        System.out.print("\n");
                    }

                    // keep asking for ticket price until valid
                    System.out.print("new ticket price (us dollars): ");
                }

                // update the film's ticket price using setter method
                film.setTicketPrice(newTicketPrice);

                // ask for new rating
                System.out.print("new rating (out of 10): ");
                int newRating;
                while (true) {
                    // input the rating as string
                    String ratingInput = scanner.nextLine().trim();

                    // error handling if number is decimal
                    if (ratingInput.matches("-?\\d+\\.\\d+")) {
                        System.out.println("non absolute cinema. invalid rating. no decimal numbers allowed.\n");
                    } 
                    else {
                        // error handling if rating is not a number
                        try {
                            newRating = Integer.parseInt(ratingInput);
                            // error handling if rating is negative
                            if (newRating < 0) {
                                System.out.println("non absolute cinema. invalid rating. negative numbers are not allowed.");
                            } 
                            // error handling if rating is more than 10
                            else if (newRating > 10) {
                                System.out.println("non absolute cinema. rating cannot be higher than 10. please enter a valid rating.");
                            } 
                            else {
                                break;
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("non absolute cinema. invalid rating. input is not a valid number.");
                        }
                        System.out.print("\n");
                    }

                    // keep asking for rating until valid
                    System.out.print("new rating (out of 10): ");
                }

                // update the film's rating using setter method
                film.setFilmRating(newRating);

                System.out.println("absolute cinema. film has been updated.\n");
                return;
            }
        }

        // error handling if the film code is not found
        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

    // method to delete film
    public static void deleteFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        // ask for film code to delete
        System.out.print("\nenter film code to delete: ");
        // read film code
        String filmCode = scanner.nextLine();

        // find film code in list
        for (CinemaFilm film : filmList) {
            // if found
            if (film.getFilmCode().equals(filmCode)) {
                // remove film from list
                filmList.remove(film);
                System.out.println("absolute cinema. film has been deleted.\n");
                return;
            }
        }
        
        // error handling if the film code is not found
        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

    // method to search film
    public static void searchFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        // ask for film code to search
        System.out.print("\nenter film code to search: ");
        // read film code
        String filmCode = scanner.nextLine();

        // find film code in list
        for (CinemaFilm film : filmList) {
            // if found
            if (film.getFilmCode().equals(filmCode)) {
                // print film details
                System.out.println("absolute cinema. film found:");
                System.out.println("-----------------------------");
                System.out.println("[ " + film.getFilmTitle() + " ]");
                System.out.println("  code: " + film.getFilmCode());
                System.out.println("  genre: " + film.getFilmGenre());
                System.out.println("  duration: " + film.getFilmDuration() + " minutes");
                System.out.println("  ticket price: $" + film.getTicketPrice());
                System.out.println("  rating: " + film.getFilmRating() + "/10");
                System.out.println("-----------------------------\n");
                return;
            }
        }

        // error handling if the film code is not found
        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

    // SUPER SECRET ABSOLUTE CINEMA METHOD (DO NOT CALL THIS METHOD UNLESS YOU ARE ABSOLUTELY SURE)
    public static void absoluteCinema() {
        System.out.println("⠀⠀⢀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
        System.out.println("⢀⠀⣿⡂⢹⡇⠀⠀⣰⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
        System.out.println("⢸⡇⢸⣇⢸⣇⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⠀⠀⣯⡀⡆⠀⠀");
        System.out.println("⢸⣷⢸⣇⣸⣇⠀⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⣂⠀⣿⡄⢸⡀⣤");
        System.out.println("⢠⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣊⡝⠛⠙⠂⠄⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣦⣼⣷⣼⣁⠼");
        System.out.println("⢸⣿⣿⣿⣿⣿⣿⣀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⡻⣥⢋⡔⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣂⣜⣿⡟⢿⣿⣿⣄");
        System.out.println("⠈⣿⣿⣿⣿⣿⣿⣿⠿⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣷⢯⣿⣾⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢪⣷⣿⢿⣿⣿");
        System.out.println("⠀⣿⣿⣟⢿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⡟⠛⠉⡉⢸⡉⠁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣽⣗⣿⠇");
        System.out.println("⠀⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠺⣿⡇⣤⡤⢔⡿⣇⠀⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣯⠀");
        System.out.println("⠘⡟⣛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⣿⣿⠗⡲⠏⠟⠿⠀⠈⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠍⠁⠁⠀");
        System.out.println("⠃⡜⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣼⣿⡟⢡⡿⠿⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⠒⠂⠂");
        System.out.println("⠐⢐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠸⣡⢶⣿⣟⡃⠀⠘⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⡀⠀");
        System.out.println("⢠⡏⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡰⢨⠣⠉⠉⠋⠉⠀⠀⠀⠀⢈⠀⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡿⠀⠀⠀⠀");
        System.out.println("⢺⡇⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⡿⢛⢭⠏⣢⠍⠈⠖⠀⠀⠒⣶⢦⡁⠂⠀⠀⠀⠀⠀⠯⠤⣤⣴⢶⣍⠝⣯⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢌⣿⠱⠀⠀⠀⠀⠀");
        System.out.println("⣯⣯⠸⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠄⠀⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠏⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠧⠍⠶⠤⠈⣆⠀⠀⠀⠀⠀⠀⠀⣷⡻⠀⣼⠀⠀⠀");
        System.out.println("⣯⣨⡀⢀⡠⠤⣐⠤⣀⣰⠔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⠐⠐⠢⠺⠥⡾⠉⡠⠀⠀⠀");
        System.out.println("⠋⠙⠈⠉⠉⠁⠈⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
        System.out.println("⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
        System.out.println("⠀⠀⠇⣣⡁⢶⣠⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢶⠀⡶⣲⠀⣆⡒⣰⠒⢦⢰⠀⢰⡆⣴⠐⣶⠒⣐⣒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣺⣿⣿⣿⠛");
        System.out.println("⠀⠀⠑⢌⠻⣗⣔⠉⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⠚⠃⠻⠴⠃⠦⠝⠘⠤⠎⠸⠤⠘⠧⠞⠀⠛⠀⠰⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⣾⣿⣿⣿⠃⠀");
        System.out.println("⠀⠀⠀⠀⠉⠢⠁⠀⠀⠀⠀⢀⣤⣤⣤⣄⠀⠀⢠⣤⠀⠀⣤⣄⠀⠀⠀⣤⣤⠀⢠⣤⣤⣤⣤⣤⡄⢠⣤⣄⠀⠀⠀⠀⣤⣤⡄⠀⠀⠀⢠⣤⡄⠀⠀⠀⢘⡮⡝⣿⣿⡿⢆⠁⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠏⠉⠉⢿⣷⠀⢸⣿⠀⠠⣿⣿⣧⡀⠀⣿⣿⠀⢸⣿⡏⠉⠉⠉⠁⢼⣿⣿⡄⠀⠀⢸⡿⣿⡇⠀⠀⢀⣿⢻⣷⠀⠀⠀⠞⡜⣹⣿⣿⡙⢆⠀⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⢸⣿⠀⠐⣿⡯⢻⣷⡀⣿⣿⠀⢸⣿⣷⣶⣶⡆⠀⢺⣿⠹⣿⡀⢠⣿⠃⣿⡇⠀⠀⣾⡟⠀⢿⣧⠀⠀⠀⠠⢽⣿⣯⡙⠀⠀⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⡀⠀⠀⣠⣤⠀⢸⣿⠀⢈⣿⡧⠀⠹⣿⣿⣿⠀⢸⣿⡇⠀⠀⠀⠀⢸⣿⡄⢻⣧⣾⡏⢠⣿⡇⠀⣼⣿⣷⣶⣾⣿⣇⠀⠀⠀⠘⣿⢣⠜⠁⠀⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣶⣾⣿⠏⠀⢸⣿⠀⠀⣿⡷⠀⠀⠹⣿⣿⠀⢸⣿⣿⣿⣿⣿⡆⢸⣿⡆⠀⢿⡿⠀⢰⣿⡇⢀⣿⡏⠀⠀⠀⢹⣿⡀⠀⠀⠀⠀⠈⡆⠀⠀⠀");
        System.out.println("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠈⠉⠀⠀⠉⠁⠀⠀⠀⠉⠉⠀⠈⠉⠉⠈⠉⠉⠁⠈⠉⠀⠀⠈⠁⠀⠀⠉⠁⠈⠉⠀⠀⠀⠀⠈⠉⠁⠐⡀⠀⠀⠀⠀⠀⠀⠀\n");

    }
}