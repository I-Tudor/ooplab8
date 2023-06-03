#pragma once
#include <vector>
#include <string>

class Song {
private:
	std::string artist;
	std::string title;
	std::vector<std::string> lyrics;
	
public:
	Song(std::string artist, std::string title, std::string lyrics);
	std::string getArtist();
	std::string getTitle();
	std::vector<std::string> getLyrics();
};