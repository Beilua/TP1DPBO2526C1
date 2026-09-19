import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final List<String> genres = Arrays.asList(
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
    );

    public static void main(String[] args) {
        ArrayList<CinemaFilm> filmList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        
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
        System.out.println("`\\____)(_)(_) (_)`\\____)(_) (_) (_)`\\__,_)(_)      ");

        System.out.println("\n====================================================");

        System.out.println("__   __                         __   __ ");
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
        while(true) {
            System.out.print(">> ");
            String command = scanner.nextLine();

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

    public static void displayFilms(ArrayList<CinemaFilm> filmList) {
        if (filmList.isEmpty()) {
            System.out.println("non absolute cinema. no film.\n");
            return;
        }

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

        System.out.println("total absolute cinema films: " + filmList.size() + "\n");
    }

    public static void addFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        System.out.print("\ncode: ");
        String code = scanner.nextLine();
        while (!code.matches("CF\\d{3}")) {
            System.out.println("non absolute cinema. invalid code. format must be CF000.\n");
            System.out.print("code: ");
            code = scanner.nextLine();
        }

        System.out.print("title: ");
        String title = scanner.nextLine();

        System.out.print("genre: ");
        String genre = scanner.nextLine();
        while (!genres.contains(genre.trim().toLowerCase())) {
            System.out.println("non absolute cinema. invalid genre. please enter a valid genre from this list: " + genres + "\n");
            System.out.print("genre: ");
            genre = scanner.nextLine();
        }
        genre = genre.trim().toLowerCase();

        System.out.print("duration (minutes): ");
        int duration;
        while (true) {
            String durationInput = scanner.nextLine().trim();

            if (durationInput.matches("-?\\d+\\.\\d+")) {
                System.out.println("non absolute cinema. invalid duration. no decimal numbers allowed.\n");
            } else {
                try {
                    duration = Integer.parseInt(durationInput);
                    if (duration < 0) {
                        System.out.println("non absolute cinema. invalid duration. negative numbers are not allowed.");
                    } else if (duration > 873) {
                        System.out.println("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.");
                    } else {
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("non absolute cinema. invalid duration. input is not a valid number.");
                }
                System.out.print("\n");
            }
            
            System.out.print("duration (minutes): ");
        }

        System.out.print("ticket price (us dollars): ");
        int ticketPrice = Integer.parseInt(scanner.nextLine());

        System.out.print("rating (out of 10): ");
        int rating = Integer.parseInt(scanner.nextLine());

        CinemaFilm newFilm = new CinemaFilm(
            code,
            title,
            genre,
            duration,
            ticketPrice,
            rating
        );

        filmList.add(newFilm);
        System.out.println("absolute cinema. new film has been added.\n");
    }

    public static void updateFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        System.out.print("\nenter film code to update: ");
        String filmCode = scanner.nextLine();

        for (CinemaFilm film : filmList) {
            if (film.getFilmCode().equals(filmCode)) {
                System.out.print("new code: ");
                String newCode = scanner.nextLine();
                while (!newCode.matches("CF\\d{3}")) {
                    System.out.println("non absolute cinema. invalid code. format must be CF000.\n");
                    System.out.print("new code: ");
                    newCode = scanner.nextLine();
                }
                film.setFilmCode(newCode);

                System.out.print("new title: ");
                film.setFilmTitle(scanner.nextLine());

                System.out.print("new genre: ");
                String newGenre = scanner.nextLine();
                while (!genres.contains(newGenre.trim().toLowerCase())) {
                    System.out.println("non absolute cinema. invalid genre. please enter a valid genre from this list: " + genres + "\n");
                    System.out.print("new genre: ");
                    newGenre = scanner.nextLine();
                }
                film.setFilmGenre(newGenre.trim().toLowerCase());

                System.out.print("new duration (minutes): ");
                int newDuration;
                while (true) {
                    String durationInput = scanner.nextLine().trim();

                    if (durationInput.matches("-?\\d+\\.\\d+")) {
                        System.out.println("non absolute cinema. invalid duration. no decimal numbers allowed.\n");
                    } else {
                        try {
                            newDuration = Integer.parseInt(durationInput);
                            if (newDuration < 0) {
                                System.out.println("non absolute cinema. invalid duration. negative numbers are not allowed.");
                            } else if (newDuration > 873) {
                                System.out.println("non absolute cinema. even the longest cinema film in history is only 873 minutes long. please enter a valid duration.");
                            } else {
                                break;
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("non absolute cinema. invalid duration. input is not a valid number.");
                        }
                        System.out.print("\n");
                    }

                    System.out.print("new duration (minutes): ");
                }
                film.setFilmDuration(newDuration);

                System.out.print("new ticket price (us dollars): ");
                film.setTicketPrice(Integer.parseInt(scanner.nextLine()));

                System.out.print("new rating (out of 10): ");
                film.setFilmRating(Integer.parseInt(scanner.nextLine()));

                System.out.println("absolute cinema. film has been updated.\n");
                return;
            }
        }

        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

    public static void deleteFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        System.out.print("\nenter film code to delete: ");
        String filmCode = scanner.nextLine();

        for (CinemaFilm film : filmList) {
            if (film.getFilmCode().equals(filmCode)) {
                filmList.remove(film);
                System.out.println("absolute cinema. film has been deleted.\n");
                return;
            }
        }
        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

    public static void searchFilm(ArrayList<CinemaFilm> filmList, Scanner scanner) {
        System.out.print("\nenter film code to search: ");
        String filmCode = scanner.nextLine();

        for (CinemaFilm film : filmList) {
            if (film.getFilmCode().equals(filmCode)) {
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
        System.out.println("non absolute cinema. film with code " + filmCode + " was not found.\n");
    }

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