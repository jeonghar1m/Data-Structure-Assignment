#include <iostream>
using namespace std;
typedef struct Song
{
	char artist[10];
	char title[10];
} song;
typedef struct Playlist
{
	int no_of_songs;
	song song_list[30][10];
} playlist;
int main()
{
	playlist my_playlist;
	//song song;
	my_playlist.no_of_songs = 0;

	strcpy_s(my_playlist.song_list[0]->artist, "Twice");
	strcpy_s(my_playlist.song_list[0]->title, "CheerUp");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[0]->artist, "BTS");
	strcpy_s(my_playlist.song_list[0]->title, "Dynamite");
	my_playlist.no_of_songs++;
	strcpy_s(my_playlist.song_list[0]->artist, "IU");
	strcpy_s(my_playlist.song_list[0]->title, "25");
	my_playlist.no_of_songs++;

	cout << "No\tArtist\tTitle" << endl;
	cout << "==\t======\t=====" << endl;
	for (int i = 1; i <= my_playlist.no_of_songs; ++i)
	{
		//printf("%d\t%s\t%s", i, my_playlist.song_list.artist[i - 1], my_playlist.song_list.title[i - 1]);
		cout << i << "\t" << my_playlist.song_list[0].artist[i] << "\t" << my_playlist.song_list[0].title[i] << endl;
	}
	cout << "A total number of songs in the list: " << my_playlist.no_of_songs << endl;
}