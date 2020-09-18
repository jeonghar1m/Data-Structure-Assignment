#include <iostream>
#include <string>
using namespace std;
typedef struct Song
{
	char artist[10];
	char title[10];
} song;
typedef struct Playlist
{
	int no_of_songs;
	song song_list[30];
} playlist;

int main()
{
	playlist my_playlist;
	my_playlist.no_of_songs = 0;
	int* no_of_songs = &my_playlist.no_of_songs;
	strcpy_s(my_playlist.song_list[0].artist, "Twice");
	strcpy_s(my_playlist.song_list[0].title, "Cheer Up!");
	strcpy_s(my_playlist.song_list[1].artist, "BTS");
	strcpy_s(my_playlist.song_list[1].title, "Dynamite");
	strcpy_s(my_playlist.song_list[2].artist, "IU");
	strcpy_s(my_playlist.song_list[2].title, "25");

	cout << "No\tArtist\tTitle" << endl;
	cout << "==\t======\t=====" << endl;
	for (int i = 0; i <= my_playlist.no_of_songs; ++i)
		cout << i + 1 << "\t" << my_playlist.song_list->artist[i] << "\t" << my_playlist.song_list->title[i] << endl;
	cout << "A total number of songs in the list: " << *no_of_songs << endl;
	return 0;
}