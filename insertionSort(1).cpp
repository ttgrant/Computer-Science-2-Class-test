#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Prototypes
void insertSort (int* a, int no_ele);
void insertSortCard(int* a, int no_ele, int card_no);
void shuffle(int* deck, int no_cards);
void displayHand(int* deck, int no_cards,int x, int y);


int main()
{
  int i = 0;
  int x = 0;
  int y = 0;
  const int TOTAL_CARDS = 13;
  int no_cards = 6;
  int* deck = new int[TOTAL_CARDS];
  int* hand = new int[no_cards];
  string fn;

  //Display Grpaphics
  displayGraphics();
 
  //Shuffle the deck
  shuffle(deck, TOTAL_CARDS);

  //Display the hand
  displayHand(deck,TOTAL_CARDS,50,50);

  Sleep(3000);

  //Perform insertion sort on the deck
  insertSort(deck,TOTAL_CARDS);

  //Display the hand
  displayHand(deck,TOTAL_CARDS,150,50);

  Sleep(2000);

  //Reshuffle
  shuffle(deck, TOTAL_CARDS);

  

  //Maintain sorted list
  for (i = 0; i < no_cards; i++)
  {
    //Display Card to be inserted
   
    fn = "h" + to_string(deck[i]) + ".bmp";
    displayBMP(fn,500,0);
    Sleep(3000);

    //Insert the card
    insertSortCard(hand,i,deck[i]);
    displayHand(hand,i+1,250,50);
    
  }

 

  
  
  
  return 0;
}


void shuffle(int* deck, int no_cards)
{
  int i = 0;
  int j = 0;
  bool duplicate = false;


  //Set the seed
  srand(time(0));

  //Generate no_colors random numbers
  for (i = 0; i < no_cards; i++)
  {
    deck[i] = (rand()%no_cards)+2;

    //Check all previous values
    do
    {
      //Set duplicate to false
      duplicate = false;

      //Check prvious values
      for (j = 0; j < i; j++)
      {
        if (deck[i] == deck[j])
        {
          deck[i] = (rand()%no_cards)+2;
          duplicate = true;
        }
      }
    }while(duplicate);
  }
}



void insertSort (int* a, int n)
{	
  //Variable Declaration/Initialization
  int i = 0;
  int j = 0; 
  int v = 0;

	// For each element after the first:
	for (i = 1; i < n; i++) 
	{	
    // Look back through the previous (sorted) elts.
		// Insert this elt after first that is smaller,
		// moving the others up as you go by them.
		v = a[i];

		for (j = i-1; j >= 0 && a[j] > v; j--)
		{
			// a[j] is bigger; move it up
			a[j+1] = a[j];
		}
		
		// a[j] <= v; put v after a[j]
		a[j+1] = v;
	}
}

void displayHand(int* deck, int no_cards,int x, int y)
{
  //Work with only hearts
  int i = 0;
  string name;

  for (i = 0; i < no_cards; i++)
  {
    //Use sprintf to combine name info
   
    name = "h" + to_string(deck[i]) + ".bmp";
    displayBMP(name,x,y);
    
    //Offset card
    y+= 20;
  }
}

void insertSortCard(int* a, int no_ele, int card_no)
{
  //Variable Declaration/Initialization
  int v = 0;
  int j = 0;

  v = card_no;

  for (j = no_ele-1; j >= 0 && a[j] > v; j--)
  {
    // a[j] is bigger; move it up
    a[j+1] = a[j];
  }
		
  // a[j] <= v; put v after a[j]
  a[j+1] = v;
	

}



