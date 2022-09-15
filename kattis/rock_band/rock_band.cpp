#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <chrono>

using Song = int;
using Playlist = std::vector<Song>;
using Favourites = std::vector<Playlist>;
using Concert = std::set<Song>;

int main()
// int main(const int, char **)
{
    unsigned nMembers = 0;
    unsigned nSongs = 0;
    std::cin >> nMembers;
    std::cin >> nSongs;

    Favourites favourites(nMembers, Playlist(nSongs, 0));
    // Read input to an array indexed by prio and musician
    for (unsigned musician = 0; musician < nMembers; ++musician)
    {
        for (unsigned prio = 0; prio < nSongs; ++prio)
        {
            std::cin >> favourites[musician][prio];
        }
    }
    auto start = std::chrono::steady_clock::now();
    Concert concert;
    /* For each priority, from highest to lowest; add unique songs whished be each musician to playlist
     * When the number of songs in the playlist equals the number of priorites processed - we can stop.
     * Why? What is the connection between priority level and playlist lenght?
     * At least one song has to be inserted at the first prio
     *
     */

    for (unsigned prio = 0; prio < nSongs; ++prio)
    {
        for (unsigned musician = 0; musician < nMembers; ++musician)
        {
            // Insert every unique song in the set.
            // No need to check if the song exists since std::set does not allow duplicates
            concert.insert(favourites[musician][prio]);
        }
        // When the size of the set is the same as the number of evaluated songs
        // we have found the smallest common set.
        if (concert.size() == prio + 1)
        {
            break;
        }
    }
    std::cout << concert.size() << std::endl;
    for (const auto c : concert)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
}