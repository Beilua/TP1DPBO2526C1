#include <string>

class CinemaFilm {
private:
	std::string filmCode;
	std::string filmTitle;
	std::string filmGenre;
	int filmDuration;
	int ticketPrice;
	int filmRating;

public:
	CinemaFilm() {
	}

	CinemaFilm(std::string filmCode, std::string filmTitle, std::string filmGenre,
			int filmDuration, int ticketPrice, int filmRating) {
		this->filmCode = filmCode;
		this->filmTitle = filmTitle;
		this->filmGenre = filmGenre;
		this->filmDuration = filmDuration;
		this->ticketPrice = ticketPrice;
		this->filmRating = filmRating;
	}

	std::string getFilmCode() {
		return filmCode;
	}

	void setFilmCode(std::string filmCode) {
		this->filmCode = filmCode;
	}

	std::string getFilmTitle() {
		return filmTitle;
	}

	void setFilmTitle(std::string filmTitle) {
		this->filmTitle = filmTitle;
	}

	std::string getFilmGenre() {
		return filmGenre;
	}

	void setFilmGenre(std::string filmGenre) {
		this->filmGenre = filmGenre;
	}

	int getFilmDuration() {
		return filmDuration;
	}

	void setFilmDuration(int filmDuration) {
		this->filmDuration = filmDuration;
	}

	int getTicketPrice() {
		return ticketPrice;
	}

	void setTicketPrice(int ticketPrice) {
		this->ticketPrice = ticketPrice;
	}

	int getFilmRating() {
		return filmRating;
	}

	void setFilmRating(int filmRating) {
		this->filmRating = filmRating;
	}
};
