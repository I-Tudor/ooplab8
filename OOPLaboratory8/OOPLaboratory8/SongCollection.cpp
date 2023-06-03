#include "SongCollection.h"
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
SongCollection::SongCollection(std::string filename)
{
    songs = getSongs(filename);
}

std::vector<Song> SongCollection::getSongs(std::string filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::invalid_argument("Failed to open file");
    }
    std::vector<Song> songlist;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::string artist, title, lyrics;
        if (line.find("ARTIST=") == 0) {
            artist = line.substr(7, line.size() - 8);
        }
        if (std::getline(file, line) && line.find("TITLE=") == 0) {
            title = line.substr(6, line.size() - 7);
        }
        if (std::getline(file, line) && line.find("LYRICS=") == 0) {
            lyrics = line.substr(7, line.size() - 8);
        }

        songlist.push_back(Song(artist, title, lyrics));
    }
    return songlist;
}

std::set<std::string> SongCollection::getUniqueArtists()  {
    std::set<std::string> uniqueArtists;
    for (auto& song : songs) {
        uniqueArtists.insert(song.getArtist());
    }
    return std::set<std::string>(uniqueArtists.begin(), uniqueArtists.end());
}

std::map<std::string, std::vector<Song>> SongCollection::groupByArtist()  {
    std::map<std::string, std::vector<Song>> artistMap;
    for ( auto& song : songs) {
        artistMap[song.getArtist()].push_back(song);
    }
    return artistMap;
}

void SongCollection::groupSongsByArtist() {
    std::map<std::string, std::vector<Song>> artistToSongsMap;
    for (auto& song : songs) {
        artistToSongsMap[song.getArtist()].push_back(song);
    }

    std::vector<std::pair<std::string, int>> artistToNumSongsVec;
    for (const auto& entry : artistToSongsMap) {
        artistToNumSongsVec.push_back(std::make_pair(entry.first, entry.second.size()));
    }

    std::sort(artistToNumSongsVec.begin(), artistToNumSongsVec.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
        });

    int count = 0;
    for (const auto& entry : artistToNumSongsVec) {
        std::cout << entry.first << ": " << entry.second << std::endl;
        count++;
        if (count == 10) {
            break;
        }
    }
}

void SongCollection::sortByArtist() {
    std::sort(songs.begin(), songs.end(),
        []( Song& s1,  Song& s2) {  return s1.getArtist() < s2.getArtist(); });
}

void SongCollection::sortByTitle() {
    std::sort(songs.begin(), songs.end(),
        []( Song& s1,  Song& s2) { return s1.getTitle() > s2.getTitle(); });
}

void SongCollection::sortByLyrics() {
    std::sort(songs.begin(), songs.end(),
        []( Song& s1,  Song& s2) { return std::count(s1.getLyrics().begin(), s1.getLyrics().end(), ' ') < std::count(s2.getLyrics().begin(), s2.getLyrics().end(), ' ');});
}