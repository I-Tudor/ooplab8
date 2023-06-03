#pragma once
#include "Song.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <set>

class SongCollection {
private:
    std::vector<Song> songs;

public:
    SongCollection(std::string filename);
    std::vector<Song> getSongs(std::string filename);
    std::set<std::string> getUniqueArtists() ;
    std::map<std::string, std::vector<Song>> groupByArtist();
    void groupSongsByArtist();

    void sortByArtist();
    void sortByTitle();
    void sortByLyrics();
};