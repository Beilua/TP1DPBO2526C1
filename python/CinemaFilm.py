class CinemaFilm:
    # constructor with parameters
    def __init__(self, filmCode, filmTitle, filmGenre, filmDuration, ticketPrice, filmRating):
        self.filmCode = filmCode
        self.filmTitle = filmTitle
        self.filmGenre = filmGenre
        self.filmDuration = filmDuration
        self.ticketPrice = ticketPrice
        self.filmRating = filmRating

    # filmCode getter and setter
    def getFilmCode(self):
        return self.filmCode

    def setFilmCode(self, filmCode):
        self.filmCode = filmCode

    # filmTitle getter and setter
    def getFilmTitle(self):
        return self.filmTitle

    def setFilmTitle(self, filmTitle):
        self.filmTitle = filmTitle

    # filmGenre getter and setter
    def getFilmGenre(self):
        return self.filmGenre

    def setFilmGenre(self, filmGenre):
        self.filmGenre = filmGenre

    # filmDuration getter and setter
    def getFilmDuration(self):
        return self.filmDuration

    def setFilmDuration(self, filmDuration):
        self.filmDuration = filmDuration

    # ticketPrice getter and setter
    def getTicketPrice(self):
        return self.ticketPrice

    def setTicketPrice(self, ticketPrice):
        self.ticketPrice = ticketPrice

    # filmRating getter and setter
    def getFilmRating(self):
        return self.filmRating

    def setFilmRating(self, filmRating):
        self.filmRating = filmRating
