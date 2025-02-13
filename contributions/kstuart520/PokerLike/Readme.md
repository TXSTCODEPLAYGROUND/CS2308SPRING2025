# PokerLike Project Overview

## Introduction
Welcome to the **PokerLike** project! This C++ project simulates a simplified poker game where you can explore key programming concepts such as code organization, dynamic data structures, and custom data types using structs. The game demonstrates the complete flow from creating and shuffling a deck to dealing cards and determining a winner based on game-specific rules.

<div style="background-color: red; color: white; font-size: 1.5em; text-align: center; padding: 10px; border-radius: 5px;">
<strong>WARNING:</strong> If you want to contribute to this project by modifying it, do not modify this original project. Instead, create a copy (e.g., <code>PokerLikeYourModification</code>) and contribute within the <code>unit01</code> folder.
</div>

## Concepts Covered

- **Code Organization:**  
  The project is divided into:
  - **Header Files** (e.g., `cards.h`):  
    These files contain declarations for data structures (such as `Card`, `Deck`, and `Poker`) and function prototypes.
  - **Source Files** (e.g., `cards.cpp`):  
    These files contain the implementations of the functions declared in the header files. This separation ensures the code is modular, easier to read, and maintain.

- **Vectors:**  
  The project uses `std::vector` to manage dynamic collections, such as the deck of cards and players' hands. Vectors provide flexible and efficient storage that can dynamically resize as needed.

- **Structs:**  
  Custom data types like `Card`, `Deck`, and `Poker` are defined using `struct`:
  - **Card:**  
    Represents a playing card with attributes such as suit and rank. Unicode symbols are used to represent suits (e.g., ♦, ♥, ♣, ♠), with red used for the ♦ and ♥ suits.
  - **Deck:**  
    Manages a collection of `Card` objects and includes functionalities for creating, shuffling, burning, and dealing cards.
  - **Poker:**  
    Orchestrates the game flow by setting up the deck, dealing cards to players, and calculating scores.
  
  *Note:* Advanced struct concepts will be explored later. For now, this project gives you a practical introduction to grouping related data and functionalities using structs.

## Game Continuation & Rules

The game progresses as follows:

- **Initial Setup:**  
  A deck is created (with or without a random shuffle) and displayed. The deck undergoes operations such as burning (removing the top card) to ensure fairness before dealing community cards.

- **Dealing Cards:**  
  - **Player Hands:** Each player is dealt two cards.
  - **Community Cards:**  
    The game deals community cards in stages:
    - **Flop:** Three community cards are dealt after burning a card.
    - **Turn:** One additional card is dealt following another burn.
    - **River:** Finally, one more card is dealt after burning another card.

- **Game Rules:**  
  **Following are the rules of this poker game:**
  - For each player, remove any community cards that match the rank of any card in the player's hand.
  - The remaining community cards (which do not have a matching rank with the player's hand) are considered the player's **valid cards**.
  - Sum the ranks of all valid cards, noting that:
    - Ace (A) is counted as 14,
    - Jack (J) as 11,
    - Queen (Q) as 12,
    - King (K) as 13,
    - Other cards have their numerical face values.
  - The player with the **lowest** sum of valid card ranks wins.
  - In the event of a tie (multiple players with the same lowest sum), the game results in a tie.

## How to Run

### Running from the Command Line

1. **Stay in the Repository Root:**  
   Navigate to the repository's root directory where the main `readme.md` is located.

2. **Use the Provided Shell Script:**  
   Run the script `run.sh` as instructed in the [readme.md](../readme.md). For the **PokerLike** project, you can pass additional arguments to specify player names. For example:
   ```bash
   sh run.sh chapter_codes/unit01/PokerLike "Kay" "Bay"
   ```
   - If you pass additional player names, those will be used.
   - If you do not pass any extra player names, the program will use the default players as specified in `main.cpp`.

### Running from CLion

Before running the code in CLion, you need to configure command line arguments:

1. **Open Run/Debug Configurations:**
   - Go to **Run > Edit Configurations**.

2. **Select the Target Executable:**
   - Choose the configuration corresponding to your project executable.

3. **Set Program Arguments:**
   - In the **Program arguments** field, enter the desired player names (e.g., `Kay Bay`). These will be passed to the program similarly to command line arguments.

4. **Apply and Run:**
   - Save your configuration and click the Run/Play button to execute the project with your specified arguments.

**Example Output**

```text
Initializing Deck...
Deck Created without shuffle
Show Deck...
---CARDS---------------------------------------------------------------------
[ A♦️] [ 2♦] [ 3♦] [ 4♦] [ 5♦] [ 6♦] [ 7♦] [ 8♦] [ 9♦] [10♦] [ J♦] [ Q♦] [ K♦] 
[ A♥] [ 2♥] [ 3♥] [ 4♥] [ 5♥] [ 6♥] [ 7♥] [ 8♥] [ 9♥] [10♥] [ J♥] [ Q♥] [ K♥] 
[ A♤] [ 2♤] [ 3♤] [ 4♤] [ 5♤] [ 6♤] [ 7♤] [ 8♤] [ 9♤] [10♤] [ J♤] [ Q♤] [ K♤] 
[ A♧] [ 2♧] [ 3♧] [ 4♧] [ 5♧] [ 6♧] [ 7♧] [ 8♧] [ 9♧] [10♧] [ J♧] [ Q♧] [ K♧] 
-----------------------------------------------------------------------------
Shuffle Deck..
---DECKS SHUFFLED------------------------------------------------------------
[ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] 
[ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] 
[ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] 
[ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] [ ? ] 
-----------------------------------------------------------------------------
---CARDS---------------------------------------------------------------------
[ J♤] [ K♧] [ 7♥] [ 5♧] [ 8♥] [10♦] [ J♥] [ 3♤] [ 2♥] [ Q♥] [ 9♥] [ 8♦] [ 2♦] 
[10♤] [ 7♦] [ 4♥] [ 5♥] [ 4♤] [ 2♤] [ 3♥] [ 9♦] [ 8♧] [ 6♧] [10♥] [ 9♧] [ K♥] 
[ A♧] [ 7♤] [ 6♥] [ 3♧] [ 4♧] [ J♦] [ Q♤] [ Q♦] [ K♦] [ A♥] [ A♤] [ 6♦] [ 3♦] 
[ A♦] [ 7♧] [ Q♧] [ 5♦] [ K♤] [ 6♤] [ 2♧] [10♧] [ 9♤] [ J♧] [ 8♤] [ 5♤] [ 4♦] 
-----------------------------------------------------------------------------
---VALUES--------------------------------------------------------------------
[ 11] [ 13] [  7] [  5] [  8] [ 10] [ 11] [  3] [  2] [ 12] [  9] [  8] [  2] 
[ 10] [  7] [  4] [  5] [  4] [  2] [  3] [  9] [  8] [  6] [ 10] [  9] [ 13] 
[ 14] [  7] [  6] [  3] [  4] [ 11] [ 12] [ 12] [ 13] [ 14] [ 14] [  6] [  3] 
[ 14] [  7] [ 12] [  5] [ 13] [  6] [  2] [ 10] [  9] [ 11] [  8] [  5] [  4] 
-----------------------------------------------------------------------------
Hit Enter to begin the game...

---CARDS---------------------------------------------------------------------
[ J♤] [ K♧] [ 7♥] [ 5♧] [ 8♥] [10♦] [ J♥] [ 3♤] [ 2♥] [ Q♥] [ 9♥] [ 8♦] [ 2♦] 
[10♤] [ 7♦] [ 4♥] [ 5♥] [ 4♤] [ 2♤] [ 3♥] [ 9♦] [ 8♧] [ 6♧] [10♥] [ 9♧] [ K♥] 
[ A♧] [ 7♤] [ 6♥] [ 3♧] [ 4♧] [ J♦] [ Q♤] [ Q♦] [ K♦] [ A♥] [ A♤] [ 6♦] [ 3♦] 
[ A♦] [ 7♧] [ Q♧] [ 5♦] [ K♤] [ 6♤] [ 2♧] [10♧] [ 9♤] [ J♧] [ 8♤] [ 5♤] [ 4♦] 
-----------------------------------------------------------------------------
---HANDS CARDS---------------------------------------------------------------
              Keshav : [ J♤] [10♦] 
                Anar : [ K♧] [ J♥] 
               James : [ 7♥] [ 3♤] 
                John : [ 5♧] [ 2♥] 
                Evry : [ 8♥] [ Q♥] 
-----------------------------------------------------------------------------
---COMMUNITY CARDS-----------------------------------------------------------
                Turn : [ 8♦] [ 2♦] [10♤] 
               River : [ 4♥] 
                Flop : [ 4♤] 

---CARDS---------------------------------------------------------------------

            [ 2♤] [ 3♥] [ 9♦] [ 8♧] [ 6♧] [10♥] [ 9♧] [ K♥] [ A♧] [ 7♤] [ 6♥] 
[ 3♧] [ 4♧] [ J♦] [ Q♤] [ Q♦] [ K♦] [ A♥] [ A♤] [ 6♦] [ 3♦] [ A♦] [ 7♧] [ Q♧] 
[ 5♦] [ K♤] [ 6♤] [ 2♧] [10♧] [ 9♤] [ J♧] [ 8♤] [ 5♤] [ 4♦] [ 9♥] [ 7♦] [ 5♥] 
-----------------------------------------------------------------------------
---STATS---------------------------------------------------------------------
              Keshav: [18] | [ 8♦] [ 2♦] [ 4♥] [ 4♤] 
                Anar: [28] | [ 8♦] [ 2♦] [10♤] [ 4♥] [ 4♤] 
               James: [28] | [ 8♦] [ 2♦] [10♤] [ 4♥] [ 4♤] 
                John: [26] | [ 8♦] [10♤] [ 4♥] [ 4♤] 
                Evry: [20] | [ 2♦] [10♤] [ 4♥] [ 4♤] 
---WINNERS-------------------------------------------------------------------
  Congratulations!! Keshav,
```
