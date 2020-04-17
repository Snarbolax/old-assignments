#pragma once

#include <string>

class Song {
private:
    std::string name_;
    std::string artist_;
    std::string album_;
    unsigned int duration_;
    bool explicit_lyrics_;

public:
    Song(std::string, std::string, std::string, unsigned int, bool);

	Song(string name, string artist, string album, unsigned int duration, bool explicit_lyrics) {
		name_ = name;
		artist_ = artist;
		album_ = album;
		duration_ = duration;
		explicit_lyrics_ = explicit_lyrics;
	}

	std::string name() {
		return name_;
	}
	std::string artist() {
		return artist_;
	}
	std::string album() {
		return album_;
	}
	unsigned int minutes() {
		return (duration_ / 60);
	}
	unsigned int seconds() {
		return (duration_ % 60);
	}
	bool explicit_lyrics() {
		return explicit_lyrics_;
	}
};
