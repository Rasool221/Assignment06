#include<list>
#include<iostream>
#include<iterator>
#include<utility>
#include<string>
#include<cmath>

using namespace std;

void addToHashTable (const pair<string,char> toAdd, list<char>* &hashTable, int const hashSize ) 
{
	int calculatedIndex = 0;

	// Calculating index by hashing
	for ( int x = 2; x >= 0; x-- ) 
	{
		calculatedIndex += ( ( int ) ( ( toAdd .first ) [ x ] ) * ( int ) pow ( 31, x ) );
	}
	
	// Getting actual index
	calculatedIndex %= hashSize;

	// Adding to the hash table
	hashTable [ calculatedIndex ].push_back ( toAdd.second );
}

void removeFromHashTable ( const char valueToLookFor, list<char>*& hashTable )
{
	const int hashTableSize = hashTable->size ( );

	
}

void main ( ) {
	pair<string, char> orig [ ] = { pair<string,char> ( "r98",'A' ),
									pair<string,char> ( "11y",'L' ),
									pair<string,char> ( "q54",'G' ),
									pair<string,char> ( "p88",'O' ),
									pair<string,char> ( "bb1",'R' ),
									pair<string,char> ( "www",'I' ),
									pair<string,char> ( "nbn",'T' ),
									pair<string,char> ( "pop",'H' ),
									pair<string,char> ( "87u",'M' ),
									pair<string,char> ( "ede",'S' ),
									pair<string,char> ( "kk8",'A' ),
									pair<string,char> ( "711",'L' ),
									pair<string,char> ( "mom",'G' ),
									pair<string,char> ( "28m",'O' )
	};


	int dataSize = *( &orig + 1 ) - orig;
	int hashSize = 20;
	list<char>* hashTab = new list<char> [ hashSize ];
	int index;
	for ( int i = 0; i < dataSize; i++ ) {
		index = 0;
		for ( int x = 2; x >= 0; x-- ) {
			index += ( ( int ) ( ( orig [ i ].first ) [ x ] ) * ( int ) pow ( 31, x ) );	//((int)orig[i]* 31) % 11;
		}
		index %= hashSize;
		hashTab [ index ].push_back ( orig [ i ].second );
	}

	// Adding to list
	pair<string, char> *toadd = new pair<string, char> ( "nbn", 'X' );

	addToHashTable ( *toadd, hashTab, hashSize );

	for ( int i = 0; i < hashSize; i++ ) {
		cout << i << ": ";
		list<char>::iterator b = hashTab [ i ].begin ( );
		list<char>::iterator e = hashTab [ i ].end ( );
		for ( ; b != e; b++ ) {
			cout << *b << "->";
		}
		cout << "NULL" << endl;
	}
	delete [ ] hashTab;

	system ( "pause" );
}