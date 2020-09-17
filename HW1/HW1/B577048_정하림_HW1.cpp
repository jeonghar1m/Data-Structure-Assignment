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
	int no = my_playlist.no_of_songs;
	strcpy_s(my_playlist.song_list[0].artist, 10, "Twice");
	strcpy_s(my_playlist.song_list[0].title, 10, "Cheer Up!");
	strcpy_s(my_playlist.song_list[1].artist, 10, "BTS");
	strcpy_s(my_playlist.song_list[1].title, 10, "Dynamite");
	strcpy_s(my_playlist.song_list[2].artist, 10, "IU");
	strcpy_s(my_playlist.song_list[2].title, 10, "25");


	printf("No\tArtist\tTitle\n");
	printf("==\t======\t=====\n");
	for (no; no < 3; ++no)
		cout << no + 1 << "\t" << my_playlist.song_list->artist[no] << "\t" << my_playlist.song_list->title[no] << endl;
	cout << "A total number of songs in the list: " << no << endl;
	return 0;
}