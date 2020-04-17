#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "Song.hpp"

class RadList {
private:
    std::list<Song> queue_;
    std::list<Song>::iterator nowPlaying_;
public:
    void loadPlaylist(const std::string&);
	void next() {
		nowPlaying_++;
	}
	void prev() {
		nowPlaying_--;
	}
	Song nowPlaying() {
		return *(queue_+nowPlaying_);
	}
	void addToQueue(const Song&) {
		queue_.push_back(Song&);
	}
	void playNext(const Song&) {
		queue_.insert(nowPlaying_+1, Song&);
	}
};

void RadList::loadPlaylist(const std::string& filename) {
    std::ifstream playlist(filename);

    if (playlist.is_open()) {
        std::string name, artist, album, duration, explicit_lyrics, toss;

        // Read in everything from comma seperated values file
        while (std::getline(playlist, name, ',')) {
            std::getline(playlist, toss, ' ');           // ignore leading space
            std::getline(playlist, artist, ',');
            std::getline(playlist, toss, ' ');           // ignore leading space
            std::getline(playlist, album, ',');
            std::getline(playlist, toss, ' ');           // ignore leading space
            std::getline(playlist, duration, ',');
            std::getline(playlist, toss, ' ');           // ignore leading space
            std::getline(playlist, explicit_lyrics);

            // Construct Song and add to queue
            queue_.push_back(Song(name, artist, album, stoi(duration), explicit_lyrics == "true"));
        }

        playlist.close();
        nowPlaying_ = queue_.begin();
    } else {
        throw std::invalid_argument("Could not open " + filename);
    }
}
