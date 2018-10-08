

#include "Player.hpp"

Player::Player() {
	_score = 0;
	_time = time(0);
	_lives = 3;
	_level = 0;
}

Player::~Player() {}

Player::Player(Player const & a) {
	*this = a;
	_time = time(0);
}

Player& 	Player::operator=(Player const &a) {
	if (this != &a) {
		_score = a._score;
		_time = time(0);
		_lives = a._lives;
		_level = a._level;
	}
	return *this;
}

int			 Player::getScore() {
	return _score;
}

time_t 		Player::getTime() {
	return _time;
}

int			Player::getLives() {
	return _lives;
}

int 		Player::getLevel() {
	return _level;
}

void		 Player::setScore(int score) {
	_score = score;
}

void 		Player::setTime(time_t time) {
	_time = time;
}

void 		Player::setLevel(int level) {
	_level = level;
}

void		 Player::setLives(int lives) {
	_lives = lives;
}

void		Player::addLevel() {
	this->_level++;
}

void		Player::addScore() {
	this->_score += 10;
}

void		Player::takeDamage() {
	system("afplay doh.mp3 &");
	this->_lives--;
}