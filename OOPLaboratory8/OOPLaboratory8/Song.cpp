#include "Song.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

Song::Song(std::string artist, std::string title, std::string lyrics) : artist(artist), title(title)
{
    this->artist = artist;
    this->title = title;

    std::stringstream ss(lyrics);
    std::string word;
    while (ss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
        word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return !std::isalpha(c); }),
            word.end());
        if (!word.empty()) {
            this->lyrics.push_back(word);
        }
    }
}

std::string Song::getArtist()
{
    return artist;
}

std::string Song::getTitle()
{
    return title;
}

std::vector<std::string> Song::getLyrics()
{
    return lyrics;
}
