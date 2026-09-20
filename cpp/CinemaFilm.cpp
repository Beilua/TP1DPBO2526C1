#include <string>

// class to represent a cinema film
class CinemaFilm {

// private attributes
private:
	std::string filmCode;
	std::string filmTitle;
	std::string filmGenre;
	int filmDuration;
	int ticketPrice;
	int filmRating;

public:
	// empty constructor
	CinemaFilm() {
	}

	// constructor with parameters
	CinemaFilm(std::string filmCode, std::string filmTitle, std::string filmGenre,
			int filmDuration, int ticketPrice, int filmRating) {
		this->filmCode = filmCode;
		this->filmTitle = filmTitle;
		this->filmGenre = filmGenre;
		this->filmDuration = filmDuration;
		this->ticketPrice = ticketPrice;
		this->filmRating = filmRating;
	}

	// filmCode getter and setter
	std::string getFilmCode() {
		return filmCode;
	}

	void setFilmCode(std::string filmCode) {
		this->filmCode = filmCode;
	}

	// filmTitle getter and setter
	std::string getFilmTitle() {
		return filmTitle;
	}

	void setFilmTitle(std::string filmTitle) {
		this->filmTitle = filmTitle;
	}

	// filmGenre getter and setter
	std::string getFilmGenre() {
		return filmGenre;
	}

	void setFilmGenre(std::string filmGenre) {
		this->filmGenre = filmGenre;
	}

	// filmDuration getter and setter
	int getFilmDuration() {
		return filmDuration;
	}

	void setFilmDuration(int filmDuration) {
		this->filmDuration = filmDuration;
	}

	// ticketPrice getter and setter
	int getTicketPrice() {
		return ticketPrice;
	}

	void setTicketPrice(int ticketPrice) {
		this->ticketPrice = ticketPrice;
	}

	// filmRating getter and setter
	int getFilmRating() {
		return filmRating;
	}

	void setFilmRating(int filmRating) {
		this->filmRating = filmRating;
	}
};
