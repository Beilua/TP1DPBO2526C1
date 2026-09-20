<?php

class CinemaFilm
{
	// declare all attributes
	private $filmCode;
	private $filmTitle;
	private $filmGenre;
	private $filmDuration;
	private $ticketPrice;
	private $filmRating;

	// constructor with parameters
	public function __construct($filmCode, $filmTitle, $filmGenre, $filmDuration, $ticketPrice, $filmRating) {
		$this->filmCode = $filmCode;
		$this->filmTitle = $filmTitle;
		$this->filmGenre = $filmGenre;
		$this->filmDuration = $filmDuration;
		$this->ticketPrice = $ticketPrice;
		$this->filmRating = $filmRating;
	}

	// filmCode getter and setter
	public function getFilmCode()
	{
		return $this->filmCode;
	}

	public function setFilmCode($filmCode)
	{
		$this->filmCode = $filmCode;
	}

	// filmTitle getter and setter
	public function getFilmTitle()
	{
		return $this->filmTitle;
	}

	public function setFilmTitle($filmTitle)
	{
		$this->filmTitle = $filmTitle;
	}

	// filmGenre getter and setter
	public function getFilmGenre()
	{
		return $this->filmGenre;
	}

	public function setFilmGenre($filmGenre)
	{
		$this->filmGenre = $filmGenre;
	}

	// filmDuration getter and setter
	public function getFilmDuration()
	{
		return $this->filmDuration;
	}

	public function setFilmDuration($filmDuration)
	{
		$this->filmDuration = $filmDuration;
	}

	// ticketPrice getter and setter
	public function getTicketPrice()
	{
		return $this->ticketPrice;
	}

	public function setTicketPrice($ticketPrice)
	{
		$this->ticketPrice = $ticketPrice;
	}

	// filmRating getter and setter
	public function getFilmRating()
	{
		return $this->filmRating;
	}

	public function setFilmRating($filmRating)
	{
		$this->filmRating = $filmRating;
	}
}
?>
