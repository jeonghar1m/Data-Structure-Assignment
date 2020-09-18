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
	strcpy_s(my_playlist.song_list[0].artist, 10, "Twice");
	strcpy_s(my_playlist.song_list[0].title, 10, "Cheer Up!");
	my_playlist.no_of_songs++; //곡이 추가될 때마다 1씩 증가.
	strcpy_s(my_playlist.song_list[1].artist, 10, "BTS");
	strcpy_s(my_playlist.song_list[1].title, 10, "Dynamite");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[2].artist, 10, "IU");
	strcpy_s(my_playlist.song_list[2].title, 10, "25");
	my_playlist.no_of_songs++;

	printf("No\tArtist\tTitle\n");
	printf("==\t======\t=====\n");
	for (int i = 0; i < sizeof(my_playlist.no_of_songs) - 1; i++)
		cout << i + 1 << "\t" << my_playlist.song_list[i].artist << "\t" << my_playlist.song_list[i].title << endl;
	cout << "A total number of songs in the list: " << my_playlist.no_of_songs << endl;
	return 0;
}