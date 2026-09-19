class CinemaFilm {
    
    // declare all attributes
    private String filmCode;
    private String filmTitle;
    private String filmGenre;
    private int filmDuration;
    private int ticketPrice;
    private int filmRating;

    // empty constructor
    CinemaFilm(){
        
    }

    // constructor with parameters
    CinemaFilm(String filmCode, String filmTitle, String filmGenre, int filmDuration, int ticketPrice, int filmRating){
        this.filmCode = filmCode;
        this.filmTitle = filmTitle;
        this.filmGenre = filmGenre;
        this.filmDuration = filmDuration;
        this.ticketPrice = ticketPrice;
        this.filmRating = filmRating;
    }

    // filmCode getter and setter
    public String getFilmCode() {
        return filmCode;
    }

    public void setFilmCode(String filmCode) {
        this.filmCode = filmCode;
    }

    // filmTitle getter and setter
    public String getFilmTitle() {
        return filmTitle;
    }

    public void setFilmTitle(String filmTitle) {
        this.filmTitle = filmTitle;
    }

    // filmGenre getter and setter
    public String getFilmGenre() {
        return filmGenre;
    }

    public void setFilmGenre(String filmGenre) {
        this.filmGenre = filmGenre;
    }


    // filmDuration getter and setter
    public int getFilmDuration() {
        return filmDuration;
    }

    public void setFilmDuration(int filmDuration) {
        this.filmDuration = filmDuration;
    }


    // ticketPrice getter and setter
    public int getTicketPrice() {
        return ticketPrice;
    }

    public void setTicketPrice(int ticketPrice) {
        this.ticketPrice = ticketPrice;
    }


    // filmRating getter and setter
    public int getFilmRating() {
        return filmRating;
    }

    public void setFilmRating(int filmRating) {
        this.filmRating = filmRating;
    }
}